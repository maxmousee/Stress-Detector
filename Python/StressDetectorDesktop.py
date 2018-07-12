'''
To use it, you will need a wav file of 1 second length, EXACTLY
The wav file should have 8KHz sample rate
Open terminal and type "python StressDetectorDesktop -i <filename>
@author: maxmouse
'''

from scipy.io import wavfile
import emd
import os
import sys, getopt
import matplotlib.pyplot as plt
import utilsStressDetector

def main(argv):
    stressTremorAverage = utilsStressDetector.getStressTremorAverage(argv)

if __name__ == "__main__":
   main(sys.argv[1:])
