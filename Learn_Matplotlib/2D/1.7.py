from pylab import *

def f(x, y):
    return (1 - x / 2 + x ** 5 + y ** 3) * np.exp(-x ** 2 - y ** 2)

n = 10
x = np.linspace(-3, 3, 3.5 * n)
y = np.linspace(-3, 3, 3.0 * n)

X, Y = np.meshgrid(x, y)
Z = f(X, Y)

axes([0.025, 0.025, 0.95, 0.95])

imshow(Z, interpolation = "nearest", cmap = "bone", origin = "lower")
# imshow() --> Display an image on the axes.
# cmap --> color map
# origin --> place the [0, 0] index of the array in the upper left or the lower
# left.
colorbar(shrink = 0.92)
# matplotlib.pyplot.colorbar() --> add a color bar to a plot
# shrink --> default to be 1.0; fraction by which to shrink the colorbar

xticks([])
yticks([])

savefig("Exercise_5.png", dpi = 200)

show()
