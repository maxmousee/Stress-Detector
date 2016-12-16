package com.nfsindustries.vsd;

import android.Manifest;
import android.content.Context;
import android.content.pm.PackageManager;
import android.graphics.Color;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.os.Handler;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;
import android.widget.Toast;

import static android.media.AudioRecord.READ_BLOCKING;

public class Realtime extends AppCompatActivity {

    private static final int RECORDER_SAMPLERATE = 8000;
    private static final int RECORD_AUDIO_REQUEST_CODE = 1;
    private static final int RECORDER_AUDIO_ENCODING = AudioFormat.ENCODING_PCM_FLOAT;
    private static final String VSD_THREAD_CONST = "VSD_THREAD";
    private AudioRecord recorder = null;
    private Thread vsdThread = null;
    private boolean isReadingMic = false;
    private double stressFrequency = 0.0;

    private TextView stressFreqTextView;

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_realtime);

        // Example of a call to a native method
        stressFreqTextView = (TextView) findViewById(R.id.stressFreqTextView);
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
        requestRecordAudioPermission();
        startVSD();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           String permissions[], int[] grantResults) {
        switch (requestCode) {
            case RECORD_AUDIO_REQUEST_CODE: {
                // If request is cancelled, the result arrays are empty.
                if (grantResults.length > 0
                        && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    // permission was granted, yay!

                } else {
                    Context context = getApplicationContext();
                    CharSequence text = "Please, allow VSD to read microphone data. This is required ;)";
                    int duration = Toast.LENGTH_LONG;
                    Toast toast = Toast.makeText(context, text, duration);
                    toast.show();
                    this.finishAffinity();
                    // permission denied, boo!
                }
                return;
            }

            // other 'case' lines to check for other
            // permissions this app might request
        }
    }

    private void requestRecordAudioPermission() {
        if (ContextCompat.checkSelfPermission(this,
                Manifest.permission.RECORD_AUDIO)
                != PackageManager.PERMISSION_GRANTED) {

            // Should we show an explanation?
            if (ActivityCompat.shouldShowRequestPermissionRationale(this,
                    Manifest.permission.RECORD_AUDIO)) {

                // Show an explanation to the user *asynchronously* -- don't block
                // this thread waiting for the user's response! After the user
                // sees the explanation, try again to request the permission.

            } else {

                // No explanation needed, we can request the permission.

                ActivityCompat.requestPermissions(this,
                        new String[]{Manifest.permission.RECORD_AUDIO},
                        RECORD_AUDIO_REQUEST_CODE);
            }
        }
    }

    private void startVSD() {
        try {
            recorder = findAudioRecord();
            recorder.startRecording();
            isReadingMic = true;
            vsdThread = new Thread(new Runnable() {
                public void run() {
                    processAudio();
                    Handler mainHandler = new Handler(getApplicationContext().getMainLooper());
                    mainHandler.post(new Runnable() {

                        @Override
                        public void run() {
                            // run code on main thread
                            if (stressFrequency > 8 && stressFrequency < 14) {
                                stressFreqTextView.setText(R.string.not_stressed);
                                stressFreqTextView.setBackgroundColor(Color.GREEN);
                            } else if (stressFrequency == 8 || stressFrequency == 14) {
                                stressFreqTextView.setText(R.string.marginal_stress);
                                stressFreqTextView.setBackgroundColor(Color.rgb(255, 165, 0));
                            } else if (stressFrequency > 0 && stressFrequency < 8) {
                                stressFreqTextView.setText(R.string.stressed);
                                stressFreqTextView.setBackgroundColor(Color.RED);
                            } else if (stressFrequency > 14 ) {
                                stressFreqTextView.setText(R.string.stressed);
                                stressFreqTextView.setBackgroundColor(Color.RED);
                            } else if (stressFrequency <= 0) {
                                stressFreqTextView.setText(R.string.too_noisy);
                                stressFreqTextView.setBackgroundColor(Color.BLACK);
                            }
                        }
                    });

                }
            }, VSD_THREAD_CONST);
            vsdThread.start();
        } catch (NullPointerException exception) {
            Context context = getApplicationContext();
            CharSequence text = "Device incompatible! Probably some weird Android implementation." +
                    "Stay tuned for updates ;)";
            int duration = Toast.LENGTH_LONG;
            Toast toast = Toast.makeText(context, text, duration);
            toast.show();
            return;
        }
    }

    private static int[] mSampleRates = new int[] { 8000 };
    public AudioRecord findAudioRecord() {
        for (int rate : mSampleRates) {
            for (short audioFormat : new short[] { RECORDER_AUDIO_ENCODING }) {
                for (short channelConfig : new short[] { AudioFormat.CHANNEL_IN_MONO, AudioFormat.CHANNEL_IN_STEREO }) {
                    try {
                        Log.d("FIND_SAMPLE_RATE", "Attempting rate " + rate + "Hz, bits: " + audioFormat + ", channel: "
                                + channelConfig);
                        int bufferSize = AudioRecord.getMinBufferSize(rate, channelConfig, audioFormat);

                        if (bufferSize != AudioRecord.ERROR_BAD_VALUE) {
                            // check if we can instantiate and have a success
                            AudioRecord aRecorder = new AudioRecord(MediaRecorder.AudioSource.DEFAULT, rate, channelConfig, audioFormat, bufferSize);

                            if (aRecorder.getState() == AudioRecord.STATE_INITIALIZED)
                                return aRecorder;
                        }
                    } catch (Exception e) {
                        Log.e("NO_SAMPLE_RATE", rate + "Exception, keep trying.",e);
                    }
                }
            }
        }
        return null;
    }

    private void processAudio() {
        // Use MATLAB generated function to process audio read from microphone

        float sData[] = new float[RECORDER_SAMPLERATE];

        //while (isReadingMic) {
            // gets the voice output from microphone to byte format
            recorder.read(sData, 0, RECORDER_SAMPLERATE, READ_BLOCKING);
            //matlab uses double, so we shall convert data to double
            double sDataDouble[] = new double[sData.length];
            for (int i = 0 ; i < sDataDouble.length; i++)
            {
                sDataDouble[i] = (double) sData[i];
            }
            //Log.d("data from microphone", sData.toString());
            //return -1.0d;
            //stressFrequency = vsd(sDataDouble);
        //}
    }

    private void stopVSD() {
        // stops the recording activity
        if (null != recorder) {
            isReadingMic = false;
            recorder.stop();
            recorder.release();
            recorder = null;
            vsdThread = null;
            //stop task
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native Double vsd(double[] jInput);
}
