from pylab import *

from scipy.interpolate import interp1d

x = linspace(0, 10 * pi, 20)
y = cos(x)

figure(figsize = (10, 5), dpi = 800)

scatter(x, y)

# linear interpolation
fl = interp1d(x, y, kind = "linear")
fq = interp1d(x, y, kind = "quadratic")

xint = linspace(x.min(), x.max(), 1000)
yintl = fl(xint)
yintq = fq(xint)

plot(xint, yintl, c = "red", label = "Linear")
plot(xint, yintq, c = "green", label = "Quadratic")

legend()

savefig("Scipy_6.png", dpi = 800)
