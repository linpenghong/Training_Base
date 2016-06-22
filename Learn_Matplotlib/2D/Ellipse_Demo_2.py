from pylab import *
from matplotlib.patches import Ellipse

NUM = 250

ells = [Ellipse((0, 0),
                width = 5,
                height = 3,
                angle = 0)]

figure(figsize = (10, 10), dpi = 300)

ax = subplot(111, aspect = "equal")

for e in ells:
    ax.add_artist(e)
    e.set_clip_box(ax.bbox)
    e.set_alpha(0.5)
    #e.set_facecolor((1, 0, 0))
    e.set_facecolor((0, 0, 0))

ax.set_xlim(-10, 10)
ax.set_ylim(-10, 10)

savefig("Ellipse_Demo_2.png", dpi = 300)
