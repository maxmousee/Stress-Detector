"""
Utils for Python Stress Detector
Created on 10 Jul 2018
@author: MaxMouse
"""

from scipy.io import wavfile
import emd
import os
import sys, getopt
import matplotlib.pyplot as plt


def plot_data(the_data):
    plt.plot(the_data)
    plt.show()


def get_audio_sample_rate_from_file(input_file):
    rate1,dat1 = wavfile.read(os.getcwd() + "/" + input_file)
    return rate1


def get_audio_data_from_file(input_file):
    rate1,dat1 = wavfile.read(os.getcwd() + "/" + input_file)
    return dat1


def extract_emd(dat1):
    the_emd = emd.emd(dat1, extrapolation=None, nimfs=8, shifting_distance=0.2)
    return the_emd


def extract_data(myemd, imf_count):
    the_data = []
    for freq in myemd:
        the_data.append(freq[imf_count - 1])
    return the_data


def get_zero_crossings(the_emd):
    count_zeros = 0
    imf_count = len(the_emd[0])
    if imf_count > 3:
        imf_count = imf_count - 1

    the_data = extract_data(the_emd, imf_count)

    for i in xrange(len(the_data)-1):
        if the_data[i] > 0 and the_data[i+1] < 0:
            count_zeros = count_zeros + 1
        elif the_data[i] < 0 and the_data[i+1] > 0:
            count_zeros = count_zeros + 1
    return count_zeros


def get_stress_tremor_average_from_data(the_data, rate1):
    the_emd = extract_emd(the_data)
    count_zeros = get_zero_crossings(the_emd)
    audio_time_length = len(the_data)/float(rate1)

    stress_tremor_avg = count_zeros - 1
    stress_tremor_avg = stress_tremor_avg/audio_time_length
    return stress_tremor_avg


def get_audio_file(argv):
    input_file = ''

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
           input_file = arg

    if not os.path.isfile(os.getcwd() + "/" + input_file):
        # file does NOT exist
        print "File does NOT exist, will exit"
        sys.exit(2)
    return input_file
