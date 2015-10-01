'''
Created on 22 Jan 2014

@author: maxmouse
'''

from scipy.io import wavfile
import emd
import os
import web
import json
import simplejson
import matplotlib.pyplot as plt
import numpy as np

def notfound():
    #return web.notfound("Sorry, the page you were looking for was not found.")
    return json.dumps({'ok':0, 'errcode': 404})

def internalerror():
    #return web.internalerror("Bad, bad server. No donut for you.")
    return json.dumps({'ok':0, 'errcode': 500})

urls = (
    '/(.*)', 'processAudio'
)

app = web.application(urls, globals())
app.notfound = notfound
app.internalerror = internalerror

class processAudio:        
	def POST(self,  method_id):
		i = web.input()
		dat2 = web.data()
		dat2 = dat2[2:-2]
		dat1 = np.fromstring(dat2, dtype=int, sep=', ')
		rate1 = len(dat1)
		myemd = emd.emd(dat1, extrapolation=None, nimfs=8, shifting_distance=0.2)
		countZeros = 0
		imfCount = len(myemd[0])
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
