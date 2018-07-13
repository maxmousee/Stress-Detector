"""
To use it, you will need a wav file of 1 second length, EXACTLY
The wav file should have 8KHz sample rate
Open terminal and type "python StressDetectorDesktop -i <filename>
@author: MaxMouse
"""

import sys
import utils_stress_detector


def main(argv):
    the_data = utils_stress_detector.get_audio_data_from_file(argv)
    stress_tremor_average = utils_stress_detector.get_stress_tremor_average_from_file(the_data, argv)
    print "stress microtremor avg freq is {}".format(stress_tremor_average)
    if stress_tremor_average > 12:
        print "subject is under stress"
    elif stress_tremor_average < 8:
        print "subject is under stress"
    else:
        print "subject is NOT under stress"

    utils_stress_detector.plot_data(the_data)


if __name__ == "__main__":
   main(sys.argv[1:])
