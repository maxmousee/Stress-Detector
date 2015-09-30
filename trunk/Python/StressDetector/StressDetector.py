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

def Base64Encode(ndarray):
    return json.dumps([str(ndarray.dtype),base64.b64encode(ndarray),ndarray.shape])

def Base64Decode(jsonDump):
    loaded = json.loads(jsonDump)
    dtype = np.dtype(loaded[0])
    arr = np.frombuffer(base64.decodestring(loaded[1]),dtype)
    if len(loaded) > 2:
        return arr.reshape(loaded[2])
    return arr

urls = (
    '/(.*)', 'processAudio'
)

app = web.application(urls, globals())
app.notfound = notfound
app.internalerror = internalerror

class processAudio:        
	def POST(self,  method_id):
		#rate3,dat3 = wavfile.read(os.getcwd() + "/rain_man_driver_8000.wav")
		i = web.input()
		dat2 = web.data()
		dat1 = np.array(json.loads(dat2))
		print dat1
		rate1 = 8000 
		#send it using this sample rate or die, your choice
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
