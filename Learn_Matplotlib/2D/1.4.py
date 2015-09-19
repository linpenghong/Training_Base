from pylab import *

n = 1024
X = np.random.normal(0, 1, n)
Y = np.random.normal(0, 1, n)
T = np.arctan2(Y, X)

# point out the working area
axes([0.025, 0.025, 0.95, 0.95])
# add an axes to the figure; axes(rect), rect in normalized (0, 1) unit

scatter(X, Y, s = 75, c = T, alpha = 0.5)
# scatter, option:
# s -> shape, default is 20
# c -> color, can be a single color format string, or a sequence of N numbers

xlim(-1.5, 1.5)
xticks([])
ylim(-1.5, 1.5)
yticks([])

savefig("Exercise_3.png", dpi = 200)

show()
