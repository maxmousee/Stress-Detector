package com.nfsindustries.vsd

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_real_time.*

class RealTime : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_real_time)

        // Example of a call to a native method
        freq_tv.text = "done"
    }

    /**
     * A native method that is implemented by the 'vsd' native library,
     * which is packaged with this application.
     */
    external fun processAudio(array: Array<Double>): Double

    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("vsd")
        }
    }
}
