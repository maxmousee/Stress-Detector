## Stress-Detector

Voice Stress Detector API written in C, MATLAB and Swift (iOS).

Sample rate: 8KHz.

Ts = 1 second.

[![Build Status](https://travis-ci.org/maxmousee/Stress-Detector.svg?branch=master)](https://travis-ci.org/maxmousee/Stress-Detector)

[![CI Status](https://circleci.com/gh/maxmousee/Stress-Detector.svg?style=shield&circle-token=:circle-token)](https://circleci.com/gh/maxmousee/Stress-Detector)

[![BCH compliance](https://bettercodehub.com/edge/badge/maxmousee/Stress-Detector?branch=master)](https://bettercodehub.com/)


# iOS

This project is under iOS
 
Now you can run:
"open VSD.xcodeproj" using terminal or XCode


# MATLAB

This project is under Generic/MATLAB

Two MATLAB files are provided, vsd.m and tst.m
vsd.m contains the code itself and tst.m contains test code


# C 

This project is under Generic/C

If you want to use the C library, you are very brave!
But if you still feel lucky, just copy all .h and .c files under this directory to your project.

To call it, just use
double stressCoefficient = vsd(INPUT_AUDIO_DATA_ARRAY, BUFFER_LENGTH);


Contributions are welcome.
