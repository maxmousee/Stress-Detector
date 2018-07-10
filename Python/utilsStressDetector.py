'''
Utils for Python Stress Detector
Created on 10 Jul 2018
@author: maxmouse
'''

from scipy.io import wavfile
import emd
import os
import sys, getopt
import matplotlib.pyplot as plt

def getAudioFile(argv):
    inputfile = ''

    try:
        opts, args = getopt.getopt(argv,"hi:o:",["ifile="])
    except getopt.GetoptError:
        print 'python StressDetectorDesktop.py -i <inputfile>'
        sys.exit(2)

    for opt, arg in opts:
       if opt == '-h':
           print 'python StressDetectorDesktop.py -i <inputfile>'
           sys.exit()
       elif opt in ("-i", "--ifile"):
           inputfile = arg

    print 'Input file is "', inputfile
    if not os.path.isfile(os.getcwd() + "/" + inputfile):
        # file does NOT exist
        print "File does NOT exist, will exit"
        sys.exit(2)
    return inputfile