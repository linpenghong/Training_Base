from pylab import *

X, Y = mgrid[-5:5:0.05, -5:5:0.05]
print X
print Y

Z = sqrt(X ** 2 + Y ** 2) + sin(X ** 2 + Y ** 2)
print Z

figure(figsize = (10, 10), dpi = 800)

imshow(Z, cmap = matplotlib.pyplot.cm.summer)

colorbar()

savefig("Imshow.png", dpi = 800)
