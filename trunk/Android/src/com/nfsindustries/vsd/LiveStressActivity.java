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
	
	private final int N = 143;
	private final double[] h = 
	{
	    -1.8847238544352936E-4,
	    -6.980168886363488E-5,
	    -8.102816935489324E-5,
	    -9.216358011864442E-5,
	    -1.0279032170613447E-4,
	    -1.1255575838983964E-4,
	    -1.2093146999605726E-4,
	    -1.2744184492778472E-4,
	    -1.3139604108451674E-4,
	    -1.321842977996246E-4,
	    -1.2897345613263898E-4,
	    -1.2101293814850909E-4,
	    -1.0734381299409424E-4,
	    -8.713465425620361E-5,
	    -5.934459179029833E-5,
	    -2.305593515826858E-5,
	    2.2889181508150338E-5,
	    7.952307294037183E-5,
	    1.4811491927372222E-4,
	    2.2973309566928259E-4,
	    3.256347254733431E-4,
	    4.368091647426344E-4,
	    5.644909313941044E-4,
	    7.096937956925888E-4,
	    8.73748564455255E-4,
	    0.0010575083113187915,
	    0.0012619625363845892,
	    0.0014876454253473124,
	    0.0017360324613860398,
	    0.0020073895485147406,
	    0.0023021172043524176,
	    0.002621142117110646,
	    0.0029643004791583974,
	    0.003332038402673223,
	    0.0037241476752824495,
	    0.004140603308037996,
	    0.004580918730722069,
	    0.0050446226363564965,
	    0.005530909219713059,
	    0.006038911878931667,
	    0.006567462353444733,
	    0.007115296875947859,
	    0.007680884494636327,
	    0.008262555256825902,
	    0.008858405485853631,
	    0.009466415388013032,
	    0.010084388324443716,
	    0.010709992372062323,
	    0.011340713746771909,
	    0.011973906462567619,
	    0.012606853925151117,
	    0.013236773625071332,
	    0.013860803635225112,
	    0.014475930492841689,
	    0.015079212586671852,
	    0.015667690798027673,
	    0.01623845353691721,
	    0.016788404881546454,
	    0.017314896280571573,
	    0.017815006476608528,
	    0.018286067786568286,
	    0.018725542832375333,
	    0.019131012054741776,
	    0.019500236489959678,
	    0.019831117906419404,
	    0.020121832094721386,
	    0.0203706960709221,
	    0.020576294598701347,
	    0.02073743053426645,
	    0.020853215719375207,
	    0.020922960735525246,
	    0.0209462645182068,
	    0.020922960735525246,
	    0.020853215719375207,
	    0.02073743053426645,
	    0.020576294598701347,
	    0.0203706960709221,
	    0.020121832094721386,
	    0.019831117906419404,
	    0.019500236489959678,
	    0.019131012054741776,
	    0.018725542832375333,
	    0.018286067786568286,
	    0.017815006476608528,
	    0.017314896280571573,
	    0.016788404881546454,
	    0.01623845353691721,
	    0.015667690798027673,
	    0.015079212586671852,
	    0.014475930492841689,
	    0.013860803635225112,
	    0.013236773625071332,
	    0.012606853925151117,
	    0.011973906462567619,
	    0.011340713746771909,
	    0.010709992372062323,
	    0.010084388324443716,
	    0.009466415388013032,
	    0.008858405485853631,
	    0.008262555256825902,
	    0.007680884494636327,
	    0.007115296875947859,
	    0.006567462353444733,
	    0.006038911878931667,
	    0.005530909219713059,
	    0.0050446226363564965,
	    0.004580918730722069,
	    0.004140603308037996,
	    0.0037241476752824495,
	    0.003332038402673223,
	    0.0029643004791583974,
	    0.002621142117110646,
	    0.0023021172043524176,
	    0.0020073895485147406,
	    0.0017360324613860398,
	    0.0014876454253473124,
	    0.0012619625363845892,
	    0.0010575083113187915,
	    8.73748564455255E-4,
	    7.096937956925888E-4,
	    5.644909313941044E-4,
	    4.368091647426344E-4,
	    3.256347254733431E-4,
	    2.2973309566928259E-4,
	    1.4811491927372222E-4,
	    7.952307294037183E-5,
	    2.2889181508150338E-5,
	    -2.305593515826858E-5,
	    -5.934459179029833E-5,
	    -8.713465425620361E-5,
	    -1.0734381299409424E-4,
	    -1.2101293814850909E-4,
	    -1.2897345613263898E-4,
	    -1.321842977996246E-4,
	    -1.3139604108451674E-4,
	    -1.2744184492778472E-4,
	    -1.2093146999605726E-4,
	    -1.1255575838983964E-4,
	    -1.0279032170613447E-4,
	    -9.216358011864442E-5,
	    -8.102816935489324E-5,
	    -6.980168886363488E-5,
	    -1.8847238544352936E-4,
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
				for(int j = 0; j < 8192; j++){
					audioRawData[j] = filter(audioRawData[j]);
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
