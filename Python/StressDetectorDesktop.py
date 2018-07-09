'''
Created on 22 Jan 2014
@author: maxmouse
'''

from scipy.io import wavfile
import emd
import os
import sys, getopt
import matplotlib.pyplot as plt

def main(argv):
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

    rate1,dat1 = wavfile.read(os.getcwd() + "/" + inputfile)
    #print dat1
    #print rate1
    myemd = emd.emd(dat1, extrapolation=None, nimfs=8, shifting_distance=0.2)
    #myemd = EMD.emd(dat1,  extrapolation='mirror', nimfs=5, shifting_distance=0.2)
    print "processing EMD"
    print myemd
    countZeros = 0
    imfCount = len(myemd[0])
    print imfCount
    if imfCount > 3:
        imfCount = imfCount - 1
    print "current imfcount is {}".format(imfCount)

    mydata = []
    for freq in myemd:
        #print freq[imfCount - 1]
        mydata.append(freq[imfCount - 1])

    for i in xrange(len(mydata)-1):
        #print mydata[i]
        if mydata[i] > 0 and mydata[i+1] < 0:
            print "crossing between indexes {} and {}".format(i, i+1)
            countZeros = countZeros + 1
        elif mydata[i] < 0 and mydata[i+1] > 0:
            print "crossing between indexes {} and {}".format(i, i+1)
            countZeros = countZeros + 1
    print "total number of elements is {}".format(len(mydata))

    #for audata in mydata:
        #print audata

    #plt.plot(myemd[imfCount-1])

    #print "number of crossing zeros {}".format(countZeros)
    audiotimelength = len(mydata)/float(rate1)
    print "total audio file length in seconds is {}".format(audiotimelength)

    stresstremoravg = countZeros - 1
    #print "countZeros - 1 is {}".format(stresstremoravg)
    stresstremoravg = stresstremoravg/audiotimelength
    print "stress microtremor avg freq is {}".format(stresstremoravg)
    if stresstremoravg > 12:
        print "subject is under stress"
    elif stresstremoravg < 8:
        print "subject is under stress"
    else:
        print "subject is NOT under stress"

    plt.plot(mydata)
    plt.show()
    #plt.plot(myemd)
    #plt.show()
    #get the second to last array. plot only it (second to last)

if __name__ == "__main__":
   main(sys.argv[1:])
