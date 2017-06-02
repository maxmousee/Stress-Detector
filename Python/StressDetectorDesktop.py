'''
Created on 22 Jan 2014
@author: maxmouse
'''
#if __name__ == '__main__':
#    print "Be careful not to fall off!"

#sp.io.wavfile.read("/Users/maxmouse/Documents/TCC/plot_hht/Hum.wav")

from scipy.io import wavfile
import emd
import os
import matplotlib.pyplot as plt
rate1,dat1 = wavfile.read(os.getcwd() + "/rain_man_driver_8000.wav")
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
#get the second to last array. plot only it (penultima)
