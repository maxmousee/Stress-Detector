public class VSD {
    /* loading the C DLL */
    static { System.loadLibrary("MATLAB_JNI"); } 
    /* functions prototypes */
    public static native double vsd(double[] input_data, int input_size);
}