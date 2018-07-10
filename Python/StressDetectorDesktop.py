'''
Created on 22 Jan 2014
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
