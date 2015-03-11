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
	
	private final int N = 96;
	private final double[] h = 
	{
	    0.13558447113621766,
	    0.004928732395539108,
	    0.005008589679043771,
	    0.005118130457501802,
	    0.005187949168190137,
	    0.005302647340319791,
	    0.005379233648837747,
	    0.005495528147123371,
	    0.005567479999116259,
	    0.005675590825765346,
	    0.005727989182473309,
	    0.005822277614430552,
	    0.005842483603836184,
	    0.005927533645573396,
	    0.0058995806766223855,
	    0.006035915741420401,
	    0.00634175844092864,
	    0.006186773994924032,
	    0.006320884765663466,
	    0.006357041864552129,
	    0.006426696795940199,
	    0.006475659113476445,
	    0.006538230136469601,
	    0.006596492386841538,
	    0.006657469949298499,
	    0.006719146161200284,
	    0.006771483230623264,
	    0.006829895678916798,
	    0.006860772447932168,
	    0.006912152869314795,
	    0.006899327476622464,
	    0.006974314947865411,
	    0.007060255398414366,
	    0.007034338491871316,
	    0.007112560166318818,
	    0.007128391444372152,
	    0.007161048631488019,
	    0.00717736524386696,
	    0.007200420394200221,
	    0.007219812432244601,
	    0.007241675514305379,
	    0.007263818814942635,
	    0.007282178967895511,
	    0.007303848175442628,
	    0.0073076670157809,
	    0.007324627793506869,
	    0.007286124714592152,
	    0.007323762449061908,
	    0.007323762449061908,
	    0.007286124714592152,
	    0.007324627793506869,
	    0.0073076670157809,
	    0.007303848175442628,
	    0.007282178967895511,
	    0.007263818814942635,
	    0.007241675514305379,
	    0.007219812432244601,
	    0.007200420394200221,
	    0.00717736524386696,
	    0.007161048631488019,
	    0.007128391444372152,
	    0.007112560166318818,
	    0.007034338491871316,
	    0.007060255398414366,
	    0.006974314947865411,
	    0.006899327476622464,
	    0.006912152869314795,
	    0.006860772447932168,
	    0.006829895678916798,
	    0.006771483230623264,
	    0.006719146161200284,
	    0.006657469949298499,
	    0.006596492386841538,
	    0.006538230136469601,
	    0.006475659113476445,
	    0.006426696795940199,
	    0.006357041864552129,
	    0.006320884765663466,
	    0.006186773994924032,
	    0.00634175844092864,
	    0.006035915741420401,
	    0.0058995806766223855,
	    0.005927533645573396,
	    0.005842483603836184,
	    0.005822277614430552,
	    0.005727989182473309,
	    0.005675590825765346,
	    0.005567479999116259,
	    0.005495528147123371,
	    0.005379233648837747,
	    0.005302647340319791,
	    0.005187949168190137,
	    0.005118130457501802,
	    0.005008589679043771,
	    0.004928732395539108,
	    0.13558447113621766,
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
				audioRawData[j + bufPosition] = doubleData[j];
				//System.out.println("Double read filtered" + doubleData[j]);
			}
			if(bufPosition < 7168) bufPosition += BufferElements2Rec;
			else {
				//10x essa merda pra dar -120dB?
				for(int k = 0; k < 10; k++){
					for(int j = 0; j < 8192; j++){
						audioRawData[j] = filter(audioRawData[j]);
					}
				}
				double stressCoef = CopyAudioDataToInputBuffer(audioRawData);
				Log.d("Stress Coef", "" + stressCoef);
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
