#!/usr/bin/env python3
#Simple script to take a list of times from the command line and print the average and the standard deviation.
#Print should be time±stddev

import sys
import numpy as np

times = [float(x) for x in sys.argv[1:]]
#Print the result as an ASCII string
print("{:.2f}±{:.2f}".format(np.mean(times), np.std(times)))