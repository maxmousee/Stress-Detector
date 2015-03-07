package com.nfsindustries.vsd;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;

public class LiveStressActivity extends Activity {
	private static final int RECORDER_SAMPLERATE = 8000;

	private static final int RECORDER_CHANNELS = AudioFormat.CHANNEL_IN_MONO;

	private static final int RECORDER_AUDIO_ENCODING = AudioFormat.ENCODING_PCM_16BIT;

	private AudioRecord recorder = null;
	private Thread recordingThread = null;
	private boolean isRecording = false;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_live_stress);

		startRecording();

		int bufferSize = AudioRecord.getMinBufferSize(RECORDER_SAMPLERATE,
				RECORDER_CHANNELS, RECORDER_AUDIO_ENCODING);
	}
	
	@Override
	public void onPause() {
		super.onPause();
		stopRecording();
	}


	int BufferElements2Rec = 1024; // want to play 2048 (2K) since 2 bytes we use only 1024
	int BytesPerElement = 2; // 2 bytes in 16bit format

	private void startRecording() {

		recorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
				RECORDER_SAMPLERATE, RECORDER_CHANNELS,
				RECORDER_AUDIO_ENCODING, BufferElements2Rec * BytesPerElement);

		recorder.startRecording();

		isRecording = true;

		recordingThread = new Thread(new Runnable() {

			public void run() {

				writeAudioDataToFile();

			}
		}, "AudioRecorder Thread");
		recordingThread.start();
	}

	//Conversion of short to byte
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

	private void writeAudioDataToFile() {
		// Write the output audio in byte
		String filePath = "/sdcard/8k16bitMono.pcm";

		short sData[] = new short[BufferElements2Rec];

		FileOutputStream os = null;
		try {
			os = new FileOutputStream(filePath);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		while (isRecording) {
			// gets the voice output from microphone to byte format
			recorder.read(sData, 0, BufferElements2Rec);
			System.out.println("Short wirting to file" + sData.toString());
			try {
				// writes the data to file from buffer stores the voice buffer
				byte bData[] = short2byte(sData);

				os.write(bData, 0, BufferElements2Rec * BytesPerElement);

			} catch (IOException e) {
				e.printStackTrace();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		try {
			os.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void stopRecording() {
		// stops the recording activity
		if (null != recorder) {
			isRecording = false;


			recorder.stop();
			recorder.release();

			recorder = null;
			recordingThread = null;
		}
	}

	// onClick of backbutton finishes the activity.
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (keyCode == KeyEvent.KEYCODE_BACK) {
			finish();
		}
		return super.onKeyDown(keyCode, event);
	}
}
