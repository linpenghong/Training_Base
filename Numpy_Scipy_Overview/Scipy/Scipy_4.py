from numpy import *

from scipy.optimize import fsolve

line = lambda x: x + 3

solution = fsolve(line, -2) # fsolve: function, x0
print solution
