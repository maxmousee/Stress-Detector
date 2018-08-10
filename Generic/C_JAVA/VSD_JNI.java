public class VSD_JNI {

    // --- Native VSD method
    public native double processAudio(double[] intArray, int input_size);


    // --- Main method to test our native library
    public static void main(String[] args) {
        int sampleRate = 8000;
        double[] inputData = new double[sampleRate];
        
        System.loadLibrary("VSD_JNI");
        
        VSD_JNI theVSD = new VSD_JNI();
        double stressFreq = theVSD.processAudio(inputData, sampleRate);

        System.out.println("stressFreq: " + stressFreq);
    }
}
