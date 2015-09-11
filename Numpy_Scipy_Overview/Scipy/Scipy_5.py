from numpy import *

from scipy.optimize import fsolve

def findIntersection(func1, func2, x0):
    return fsolve(lambda x : func1(x) - func2(x), x0)

# define functions
funky = lambda x : cos(x / 5) * sin(x / 2)
line = lambda x : 0.01 * x - 0.5

result = findIntersection(funky, line, [15, 20, 25, 30, 35, 40, 45])
# fsolve can determine roots from various intial values

print result
