from pylab import *

n = 8
X, Y = np.mgrid[0:n, 0:n] # mgrid is a more compact form of meshgrid

T = np.arctan2(Y - n / 2.0, X - n / 2.0) # stand for the angle
R = 10 + np.sqrt((X - n / 2.0) ** 2 + (Y - n / 2.0) ** 2) # stand for the length
U = R * np.cos(T) # stand for the horizontal length
V = R * np.sin(T) # stand for the vertical length

quiver(X, Y, U, V, R, alpha = 0.5)
# quiver(X, Y, U, V, C) --> plot a 2D field of arrows
# X, Y --> location of the arrows
# U, V --> X and Y component of the arrows
# C --> color

xlim(-1, n)
ylim(-1, n)
xticks([])
yticks([])

savefig("Exercise_6.png", dpi = 200)

show()
