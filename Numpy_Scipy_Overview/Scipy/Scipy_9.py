from pylab import *

from scipy.integrate import quad, trapz

x = clip(sort(np.random.randn(150) * 4 + 4), 0, 5)
print x

func = lambda x : sin(x) * cos(x ** 2) + 1
y = func(x)

fsolution = quad(func, 0, 5)
dsolution = trapz(y, x = x)
print fsolution
print dsolution
