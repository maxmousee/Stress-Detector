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

def getAudioLength(argv):
    inputfile = getAudioFile(argv)
    rate1,dat1 = wavfile.read(os.getcwd() + "/" + inputfile)
    return rate1

def getAudioData(argv):
    inputfile = getAudioFile(argv)
    rate1,dat1 = wavfile.read(os.getcwd() + "/" + inputfile)
    return dat1

def extractEMD(dat1):
    myemd = emd.emd(dat1, extrapolation=None, nimfs=8, shifting_distance=0.2)
    return myemd

def extractData(myemd, imfCount):
    mydata = []
    for freq in myemd:
        mydata.append(freq[imfCount - 1])
    return mydata

def getZeroCrossings(myemd):
    countZeros = 0
    imfCount = len(myemd[0])
    if imfCount > 3:
        imfCount = imfCount - 1

    mydata = extractData(myemd, imfCount)

    for i in xrange(len(mydata)-1):
        if mydata[i] > 0 and mydata[i+1] < 0:
            countZeros = countZeros + 1
        elif mydata[i] < 0 and mydata[i+1] > 0:
            countZeros = countZeros + 1
    return countZeros

def getStressTremorAverage(argv):
    mydata = getAudioData(argv)
    myemd = extractEMD(mydata)
    countZeros = getZeroCrossings(myemd)
    rate1 = getAudioLength(argv)
    audiotimelength = len(mydata)/float(rate1)

    stresstremoravg = countZeros - 1
    stresstremoravg = stresstremoravg/audiotimelength
    print "stress microtremor avg freq is {}".format(stresstremoravg)
    if stresstremoravg > 12:
        print "subject is under stress"
    elif stresstremoravg < 8:
        print "subject is under stress"
    else:
        print "subject is NOT under stress"

    #plt.plot(mydata)
    #plt.show()
    return stresstremoravg

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

    if not os.path.isfile(os.getcwd() + "/" + inputfile):
        # file does NOT exist
        print "File does NOT exist, will exit"
        sys.exit(2)
    return inputfile