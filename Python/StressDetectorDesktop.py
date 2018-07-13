'''
To use it, you will need a wav file of 1 second length, EXACTLY
The wav file should have 8KHz sample rate
Open terminal and type "python StressDetectorDesktop -i <filename>
@author: maxmouse
'''

import sys
import utilsStressDetector
import matplotlib.pyplot as plt

def main(argv):
    stressTremorAverage = utilsStressDetector.get_stress_tremor_average(argv)

if __name__ == "__main__":
   main(sys.argv[1:])
