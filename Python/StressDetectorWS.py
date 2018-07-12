'''
To run it just go to the folder and type "python StressDetectorWS.py" without the quotes
It will run as a http service listening to port 8080

Audio data array should be 8000 samples of wav data, 1 second of a 8KHz sample rate audio
To send a test request just run "curl -H "Content-Type: application/json" --data @audiodata.json http://localhost:8080/processAudio"
@author: maxmouse
'''

import emd
import web
import json
import numpy as np
import utilsStressDetector

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
		countZeros = utilsStressDetector.getZeroCrossings(myemd)
		audiotimelength = len(dat1)/float(rate1)

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
