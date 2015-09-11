from pylab import *

from scipy.interpolate import UnivariateSpline

x = linspace(1, 10 * pi, 30)
y = cos(x) + log10(x) + np.random.randn(30) / 10

f = UnivariateSpline(x, y, s = 1) # s -> smoothing factor

xint = linspace(x.min(), x.max(), 1000)
yint = f(xint)

figure(figsize = (10, 5), dpi = 800)

scatter(x, y, c = "black")
plot(xint, yint)

savefig("Scipy_7.png", dpi = 800)
