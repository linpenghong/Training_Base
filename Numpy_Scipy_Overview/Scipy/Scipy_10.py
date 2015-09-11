from pylab import *

x = np.random.randn(1000)

mean = x.mean()
std = x.std()
var = x.var()

print mean, std, var
