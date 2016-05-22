from pylab import *

N = 150

r = 2 * np.random.rand(N)
theta = np.linspace(0, 2 * np.pi, N, endpoint = False)
area = 200 * r**2 * np.random.rand(N)
colors = theta

figure(figsize = (10, 10), dpi = 500)

subplot(111, projection = 'polar')
c = scatter(theta, r, c = colors, s = area, cmap = cm.hsv)
c.set_alpha(0.75)

savefig("Polar_Scatter.png", dpi = 500)
