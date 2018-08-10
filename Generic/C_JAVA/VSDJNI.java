public class VSDJNI {

    static {
        System.loadLibrary("VSDJNI");
    }

    // --- Native VSD method
    public native double processAudio(double[] inputArray, int sampleRate);


    // --- Main method to test our native library
    public static void main(String[] args) {
        int sampleRate = 8000;
        double[] inputData = new double[sampleRate];
        
        VSDJNI theVSD = new VSDJNI();
        double stressFreq = theVSD.processAudio(inputData, sampleRate);

        System.out.println("stressFreq: " + stressFreq);
    }
}
