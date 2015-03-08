package com.nfsindustries.vsd;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.media.AudioFormat;
import android.media.AudioRecord;
import android.media.MediaRecorder;
import android.os.Bundle;
import android.util.Log;
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
	
	private double audioRawData[] = null;
	private int bufPosition = 0;
	
	int BufferElements2Rec = 1024; // want to play 2048 (2K) since 2 bytes we use only 1024
	int BytesPerElement = 2; // 2 bytes in 16bit format
	
	private final int N = 104;
	private final double[] h = 
	{
	    6.553855209586238E-4,
	    3.753250585429486E-4,
	    4.79803047871974E-4,
	    6.00862643822468E-4,
	    7.397208382800241E-4,
	    8.98028185391829E-4,
	    0.0010769981646752463,
	    0.0012774723412864483,
	    0.0015003592425230827,
	    0.001747665450443479,
	    0.002020025175319997,
	    0.002316709522569405,
	    0.00264077729079677,
	    0.002990549297216827,
	    0.003367535528776758,
	    0.0037715454307637344,
	    0.004202639489901543,
	    0.004660372586192188,
	    0.00514435013986085,
	    0.0056539907559359,
	    0.006188071912546874,
	    0.00674554614926618,
	    0.007325316355760513,
	    0.007925232876353204,
	    0.008544009405323487,
	    0.009179263653586034,
	    0.009828873677149536,
	    0.010490261936552682,
	    0.011160881718929403,
	    0.011837853459360292,
	    0.012518161026070094,
	    0.013198854050934537,
	    0.01387667446320002,
	    0.014548279820402226,
	    0.015210510629407516,
	    0.01585977865344017,
	    0.016492796431630857,
	    0.017106079769785048,
	    0.0176963206423424,
	    0.018260154249347467,
	    0.018794432962873586,
	    0.019296111443218394,
	    0.019762235496064248,
	    0.02019013089689339,
	    0.020577277539338076,
	    0.020921321567595227,
	    0.021220253019739177,
	    0.021472216196396745,
	    0.021675686763106692,
	    0.021829397497892093,
	    0.02193241712461402,
	    0.021984078185526484,
	    0.021984078185526484,
	    0.02193241712461402,
	    0.021829397497892093,
	    0.021675686763106692,
	    0.021472216196396745,
	    0.021220253019739177,
	    0.020921321567595227,
	    0.020577277539338076,
	    0.02019013089689339,
	    0.019762235496064248,
	    0.019296111443218394,
	    0.018794432962873586,
	    0.018260154249347467,
	    0.0176963206423424,
	    0.017106079769785048,
	    0.016492796431630857,
	    0.01585977865344017,
	    0.015210510629407516,
	    0.014548279820402226,
	    0.01387667446320002,
	    0.013198854050934537,
	    0.012518161026070094,
	    0.011837853459360292,
	    0.011160881718929403,
	    0.010490261936552682,
	    0.009828873677149536,
	    0.009179263653586034,
	    0.008544009405323487,
	    0.007925232876353204,
	    0.007325316355760513,
	    0.00674554614926618,
	    0.006188071912546874,
	    0.0056539907559359,
	    0.00514435013986085,
	    0.004660372586192188,
	    0.004202639489901543,
	    0.0037715454307637344,
	    0.003367535528776758,
	    0.002990549297216827,
	    0.00264077729079677,
	    0.002316709522569405,
	    0.002020025175319997,
	    0.001747665450443479,
	    0.0015003592425230827,
	    0.0012774723412864483,
	    0.0010769981646752463,
	    8.98028185391829E-4,
	    7.397208382800241E-4,
	    6.00862643822468E-4,
	    4.79803047871974E-4,
	    3.753250585429486E-4,
	    6.553855209586238E-4,
	};
	
	private int n = 0;
	private double[] x = new double[N];
	
    public native double CopyAudioDataToInputBuffer(double[] arr );

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_live_stress);

		startRecording();

		int bufferSize = AudioRecord.getMinBufferSize(RECORDER_SAMPLERATE,
				RECORDER_CHANNELS, RECORDER_AUDIO_ENCODING);
		
		Log.d("LiveStressActivity", "BUFFERSIZE " + bufferSize);
	}
	
	@Override
	public void onPause() {
		super.onPause();
	}
	
	@Override
	public void onStop() {
		super.onStop();
		stopRecording();
	}
	
	static {
		try{
			System.loadLibrary("BufferManager");
		}catch(Exception e){
			e.printStackTrace();
		}
    }

	public double filter(double x_in)
	{
	    double y = 0.0;

	    // Store the current input, overwriting the oldest input
	    x[n] = x_in;

	    // Multiply the filter coefficients by the previous inputs and sum
	    for (int i=0; i<N; i++)
	    {
	        y += h[i] * x[((N - i) + n) % N];
	    }

	    // Increment the input buffer index to the next location
	    n = (n + 1) % N;

	    return y;
	}

	private void startRecording() {

		recorder = new AudioRecord(MediaRecorder.AudioSource.MIC,
				RECORDER_SAMPLERATE, RECORDER_CHANNELS,
				RECORDER_AUDIO_ENCODING, BufferElements2Rec * BytesPerElement);

		recorder.startRecording();

		isRecording = true;
		
		audioRawData = new double[8192];

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
	
	private double rootMeanSquared(short[] nums)
    {
        double ms = 0;
        for (int i = 0; i < nums.length; i++)
        {
            ms += nums[i] * nums[i];
        }
        ms /= nums.length;
        return Math.sqrt(ms);
    }

	private void writeAudioDataToFile() {
		// Write the output audio in byte
		String filePath = android.os.Environment.getExternalStorageDirectory().getPath() + "/8k16bitMono.pcm";

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
			//double currentVolume = rootMeanSquared(sData);
			
			double[] doubleData = new double[BufferElements2Rec];

			for (int j=0;j<BufferElements2Rec;j++) {
				doubleData[j] = (double)sData[j]/32768.0;
			}
			
			//System.out.println("Short wirting to file " + sData.toString());
			for (int j=0;j<BufferElements2Rec;j++) {
				doubleData[j] = filter(doubleData[j]);
				audioRawData[j + bufPosition] = doubleData[j];
				//System.out.println("Double read filtered" + doubleData[j]);
			}
			if(bufPosition < 7168) bufPosition += BufferElements2Rec;
			else {
				bufPosition = 0;
				//PROCESS AUDIO DATA
				//Log.d("LiveStressRecorder", "Buffer full, will process data...");
			}
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
			bufPosition = 0;
			audioRawData = null;
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
