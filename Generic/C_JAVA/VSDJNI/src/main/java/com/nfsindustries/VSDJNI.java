package com.nfsindustries;

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
        double[] inputData = new double[8000];
        VSDJNI vsdjni = new VSDJNI();
        double stressFreq = vsdjni.processAudio(inputData);
        System.out.println("Stress Frequency " + stressFreq);
    }
}
