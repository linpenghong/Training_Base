from pylab import *
import os
import sys

figure(figsize = (20, 20), dpi = 500)

lines = open(sys.argv[1], "r").readlines();

X = [float(line.strip().split(' ')[0]) for line in lines]
Y = [float(line.strip().split(' ')[1]) for line in lines]

scatter(X, Y)

savefig(sys.argv[1] + ".png", dpi = 500)
