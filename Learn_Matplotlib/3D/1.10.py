from pylab import *
from mpl_toolkits.mplot3d import *

dphi = pi / 250
dtheta = pi / 250

[phi, theta] = mgrid[0 : pi + dphi * 1.5 : dphi,
                     0 : 2 * pi + dtheta * 1.5 : dtheta]

m0 = 4
m1 = 3
m2 = 2
m3 = 3
m4 = 6
m5 = 2
m6 = 6
m7 = 4

r = sin(m0 * phi) ** m1 + cos(m2 * phi) ** m3 \
  + sin(m4 * theta) ** m5 + cos(m6 * theta) ** m7

x = r * sin(theta) * cos(phi)
y = r * sin(theta) * cos(phi)
z = r * cos(theta)

fig = figure()
ax = fig.add_subplot(111, projection = '3d')
ax.scatter(x, y, z, c = sqrt(x ** 2 + y ** 2 + z ** 2), cmap = cm.coolwarm)
show()
