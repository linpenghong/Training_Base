from pylab import *

figure(figsize = (8, 6), dpi = 80)
subplot(1, 1, 1)

n = 256
X = linspace(-np.pi, np.pi, n, endpoint = True)
Y = np.sin(2 * X)

xlim(-np.pi, np.pi)
ylim(-3, 3)

xticks([])
yticks([])

plot(X, Y + 1, color = "blue", alpha = 1.0)
plot(X, Y - 1, color = "blue", alpha = 1.0)

fill_between(X, Y + 1, y2 = 1, color = "blue", alpha = 0.3)
fill_between(X, Y - 1, y2 = -1, color = "red", alpha = 0.3)

savefig("Exercise_2", dpi = 200)

show()
