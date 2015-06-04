from pylab import *

# X = [1, 2, 3]
# Y = [4, 5, 6]
# np.meshgrid(X, Y) will be:
# [1 2 3]   [4 4 4]
# [1 2 3]   [5 5 5]
# [1 2 3]   [6 6 6]
# it represents the coordinate of each grid in the map:
# [(1, 4) (2, 4) (3, 4)]
# [(1, 5) (2, 5) (2, 5)]
# [(1, 6) (2, 6) (3, 6)]

def f(x, y):
    return (1 - x / 2 + x ** 5 + y ** 3) * np.exp(-x ** 2 - y ** 2)

n = 256
x = np.linspace(-3, 3, n)
y = np.linspace(-3, 3, n)
X, Y = np.meshgrid(x, y)

# contour() and contourf() draw contour lines and filled contours, respectively.
# cmap -> color map
# cm contains variosus color maps
# contour() and contouf() --> (X, Y, Z, V)
# V --> draw contour lines at the values specified in sequence V
contourf(X, Y, f(X, Y), 8, alpha = 0.75, cmap = cm.hot)
C = contour(X, Y, f(X, Y), 8, colors = "black", linewidth = 0.5)
# contour() returns a QuadContourSet object
clabel(C)
# clabel(C, **kwargs)
# C is a ContourSet object returned by contour
# inline --> controls whether the underlying contour is removed or not

xticks([])
yticks([])

savefig("Exercise_4", dpi = 200)

show()
