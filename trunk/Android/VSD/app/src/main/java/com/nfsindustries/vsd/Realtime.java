package com.nfsindustries.vsd;

import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import static android.media.AudioRecord.READ_BLOCKING;

public class Realtime extends AppCompatActivity {

    private static final int RECORDER_SAMPLERATE = 8000;
    private static final int RECORDER_CHANNELS = AudioFormat.CHANNEL_IN_MONO;
    private static final int RECORDER_AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;
    private AudioRecord recorder = null;
    private Thread vsdThread = null;
    private boolean isReadingMic = false;
    int BufferElements2Rec = 1024; // want to play 2048 (2K) since 2 bytes we use only 1024
    int BytesPerElement = 2; // 2 bytes in 16bit format

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_realtime);

        int bufferSize = AudioRecord.getMinBufferSize(RECORDER_SAMPLERATE,
                RECORDER_CHANNELS, RECORDER_AUDIO_ENCODING);

        // Example of a call to a native method
        TextView stressFreqTextView = (TextView) findViewById(R.id.stressFreqTextView);
        //tv.setText(stringFromJNI());
        startVSD();
    }

    /**
     * Stop processing when activity is paused
     */
    @Override
    protected void onPause() {
        super.onPause();
        stopVSD();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        stopVSD();
    }

    @Override
    protected void onResume() {
        super.onResume();
        startVSD();
    }

    private void startVSD() {

        recorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
                RECORDER_SAMPLERATE, RECORDER_CHANNELS,
                RECORDER_AUDIO_ENCODING, RECORDER_SAMPLERATE);
                //RECORDER_AUDIO_ENCODING, BufferElements2Rec * BytesPerElement);

        recorder.startRecording();
        isReadingMic = true;
        vsdThread = new Thread(new Runnable() {
            public void run() {
                writeAudioDataToFile();
            }
        }, "VSD Thread");
        vsdThread.start();
    }

    //convert short to byte
    /*
    private byte[] short2byte(short[] sData) {
        int shortArrsize = sData.length;
        byte[] bytes = new byte[shortArrsize * 2];
        for (int i = 0; i < shortArrsize; i++) {
            bytes[i * 2] = (byte) (sData[i] & 0x00FF);
            bytes[(i * 2) + 1] = (byte) (sData[i] >> 8);
            sData[i] = 0;
        }
        return bytes;

    }
    */

    private void writeAudioDataToFile() {
        // Write the output audio in byte

        float sData[] = new float[RECORDER_SAMPLERATE];

        while (isReadingMic) {
            // gets the voice output from microphone to byte format

            recorder.read(sData, 0, BufferElements2Rec, READ_BLOCKING);
            System.out.println("float read from microphone" + sData.toString());

        }

    }

    private void stopVSD() {
        // stops the recording activity
        if (null != recorder) {
            isReadingMic = false;
            recorder.stop();
            recorder.release();
            recorder = null;
            vsdThread = null;
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
