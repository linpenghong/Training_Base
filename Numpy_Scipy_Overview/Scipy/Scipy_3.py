from numpy import *

from scipy.optimize import curve_fit

def func(x, a0, b0, c0, a1, b1, c1):
    return a0 * exp(-(x - b0) ** 2 / (2 * c0 **2)) + a1 * exp(-(x - b1) ** 2 / (2 * c1 **2))

x = linspace(0, 20, 200)
y = func(x, 1, 3, 1, -2, 15, 0.5)

# add noise to the data
yn = y + random.normal(size = len(x))

guesses = [1, 3, 1, 1, 15, 1]
popt, pcov = curve_fit(func, x, yn, p0 = guesses)
print popt
