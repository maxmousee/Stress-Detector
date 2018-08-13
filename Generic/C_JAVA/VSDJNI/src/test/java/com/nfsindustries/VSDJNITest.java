package com.nfsindustries;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;

class VSDJNITest {

    @Test
    void testInitialization() {
        VSDJNI vsdjni = new VSDJNI();
        assertNotNull(vsdjni);
    }

    @Disabled
    @Test
    void testProcessAudio() {
        double[] inputData = new double[8000];
        VSDJNI vsdjni = new VSDJNI();
        assertNotNull(vsdjni);
        double stressFreq = vsdjni.processAudio(inputData);
        assertEquals(stressFreq, 0.0);
        //This test will fail because JUNIT is a bitch and can NOT initialize JNI libraries AFAIK
    }
}
