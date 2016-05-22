from pylab import *

N = 20
theta = np.linspace(0, 2 * np.pi, N, endpoint = False)
radii = 10 * np.random.rand(N)
width = np.pi / 4 * np.random.rand(N)

figure(figsize = (10, 10), dpi = 500)

subplot(111, projection = 'polar')
bars = bar(theta, radii, width = width, bottom = 0)

for r, bar in zip(radii, bars):
    bar.set_facecolor(cm.jet(r / 10))
    bar.set_alpha(0.5)

savefig("Polar_Chart.png", dpi = 500)
