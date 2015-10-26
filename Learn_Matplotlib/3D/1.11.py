from pylab import *
from mpl_toolkits.mplot3d import *

class Sphere:

    def __init__(self, radius, theta, phi):
        self.radius = radius
        self.theta = theta
        self.phi = phi

    def toCartesian(self):
        x = self.radius * sin(self.theta) * cos(self.phi)
        y = self.radius * sin(self.theta) * sin(self.phi)
        z = self.radius * cos(self.theta)
        return x, y, z

def seperateSphere(limit):

    sphere = Sphere(1, 0, 0)

    n = int(ceil(sqrt((limit - 2) / 4)))

    deltaTheta = 0.5 * pi / n

    for a in range(-n, n + 1):

        sphere.phi = 0
        size = (n - abs(a)) * 4 or 1
        deltaPhi = 2 * pi / size

        for i in range(size):
            yield sphere.toCartesian()
            sphere.phi += deltaPhi

        sphere.theta += deltaTheta 

x = []
y = []
z = []
for point in seperateSphere(1000):
    x.append(point[0])
    y.append(point[1])
    z.append(point[2])

fig = figure(figsize = (10, 10), dpi = 300)
ax = fig.add_subplot(111, projection = '3d')
ax.scatter(x, y, z)

ax.set_xlim(-1.5, 1.5)
ax.set_ylim(-1.5, 1.5)
ax.set_zlim(-1.5, 1.5)

ax.set_title("Pseudo-Even Sphere Seperation")

savefig("Sphere_Seperation.png", dpi = 300)
