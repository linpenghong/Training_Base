from pylab import *
import os

figure(figsize = (20, 20), dpi = 500)

lines = open("2D_ACG.txt", "r").readlines();

X = [float(line.strip().split(' ')[0]) for line in lines]
Y = [float(line.strip().split(' ')[1]) for line in lines]

scatter(X, Y)

savefig("2D_ACG.png", dpi = 500)
