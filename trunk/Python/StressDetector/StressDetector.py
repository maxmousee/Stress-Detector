'''
Created on 22 Jan 2014

@author: maxmouse
'''

from scipy.io import wavfile
import emd
import os
import web
import json
import matplotlib.pyplot as plt


urls = (
    '/(.*)', 'processAudio'
)
app = web.application(urls, globals())

class processAudio:        
	def GET(self,  name):
		rate1,dat1 = wavfile.read(os.getcwd() + "/rain_man_driver_8000.wav")
		myemd = emd.emd(dat1, extrapolation=None, nimfs=8, shifting_distance=0.2)
		countZeros = 0
		imfCount = len(myemd[0])
		print imfCount
		if imfCount > 3:
			imfCount = imfCount - 1

		mydata = []
		for freq in myemd:
			mydata.append(freq[imfCount - 1])
		
		for i in xrange(len(mydata)-1):
			if mydata[i] > 0 and mydata[i+1] < 0:
				countZeros = countZeros + 1
			elif mydata[i] < 0 and mydata[i+1] > 0:
				countZeros = countZeros + 1

		audiotimelength = len(mydata)/float(rate1)

		stresstremoravg = countZeros - 1
		stresstremoravg = stresstremoravg/audiotimelength
		underStress = False
		if stresstremoravg > 12:
			underStress = True
		elif stresstremoravg < 8:
			underStress = True
		else:
			underStress = False

		pyDict = {'underStress':underStress}
		web.header('Content-Type', 'application/json')
		return json.dumps(pyDict)

if __name__ == "__main__":
    app.run()
