from numpy import *

from scipy.optimize import curve_fit

# create a function to model and create data
def func(x, a, b):
    return a * x + b

# generate clean data
x = linspace(0, 10, 100)
y = func(x, 1, 2)

# add noise to the data
yn = y + 0.9 + random.normal(size = len(x))

# execute curve_fit on noisy data
popt, pcov = curve_fit(func, x, yn)

# popt return the best fit values for parameters of the given model
print popt
