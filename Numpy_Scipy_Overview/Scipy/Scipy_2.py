from numpy import *

from scipy.optimize import curve_fit

# create a function to model and create data
def func(x, a, b, c):
    return a * exp(-(x - b) ** 2 / (2 * c ** 2))

# generate clean data
x = linspace(0, 10, 100)
y = func(x, 1, 5, 2)

# add noise to the data
yn = y + 0.2 * random.normal(size = len(x))

# execute curve_fit on noisy data
popt, pcov = curve_fit(func, x, yn) # parameters of curve_fit: model, x, y

print popt
