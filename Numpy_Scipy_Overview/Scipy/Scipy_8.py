from pylab import *
from scipy.integrate import quad

func = lambda x : cos(exp(x)) ** 2

solution = quad(func, 0, 3) # 1st -> desired value; 2nd -> error
print solution
