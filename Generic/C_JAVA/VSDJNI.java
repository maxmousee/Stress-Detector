public class VSDJNI {

    static{
        try{
            System.loadLibrary("VSDJNI");
        }catch(UnsatisfiedLinkError e){
            e.printStackTrace();
        }
    }

    // --- Native VSD method
    public native double processAudio(double[] inputArray);


    // --- Main method to test our native library
    public static void main(String[] args) {
        double[] inputData = new double[] {0};

        VSDJNI theVSD = new VSDJNI();
        double stressFreq = theVSD.processAudio(inputData);
        System.out.println("stressFreq: " + stressFreq);
    }
}
