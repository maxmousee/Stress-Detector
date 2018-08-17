## Stress-Detector

Voice Stress Detector API written in C, Java (JNI), MATLAB and iOS App.

Sample rate: 8KHz.

Ts = 1 second.

[![Build Status](https://travis-ci.org/maxmousee/Stress-Detector.svg?branch=master)](https://travis-ci.org/maxmousee/Stress-Detector)

[![CI Status](https://circleci.com/gh/maxmousee/Stress-Detector.svg?style=shield&circle-token=:circle-token)](https://circleci.com/gh/maxmousee/Stress-Detector)

[![BCH compliance](https://bettercodehub.com/edge/badge/maxmousee/Stress-Detector?branch=master)](https://bettercodehub.com/)


# iOS

This project is under iOS

To run it, you will need to install COCOAPODS https://cocoapods.org/
Then, install the project dependencies:
Just go to the iOS folder and run
"pod install"
 
Now you can run:
"open VSD.xcworkspace" using terminal or XCode


# JNI

This project is under Generic/C_JAVA

To build it, you will need to use the proper Makefile for your operating system:
"make all -f Makefile_java_mac" for MacOS
or
"make all -f Makefile_java_linux" for Linux

Then the proper shared library will be build so you can use in your project.

A Sample code is provided in VSDJNI.java

To run it, after you build the shared library:

Using Linux:
"cp lib/libVSDJNI.so libVSDJNI.so" 
"javac VSDJNI.java -h .;"
"java -cp . -Djava.library.path=$(pwd) VSDJNI"


Using MacOS:
"cp lib/libVSDJNI.dylib libVSDJNI.dylib" 
"javac VSDJNI.java -h .;"
"java -cp . -Djava.library.path=$(pwd) VSDJNI"


# MATLAB

This project is under Generic/MATLAB

Two MATLAB files are provided, vsd.m and tst.m
vsd.m contains the code itself and tst.m contains test code


# C 

This project is under Generic/C_JAVA

If you want to use the C library, you are very brave!
But if you still feel lucky, just copy all .h and .cpp files under this directory to your project (except for VSDJNI.h and VSDJNI.cpp).

To call it, just use
double stressCoefficient = vsd(INPUT_AUDIO_DATA_ARRAY, BUFFER_LENGTH);


Contributions are welcome.
