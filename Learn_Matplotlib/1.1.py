from pylab import *

figure(figsize = (8, 6), dpi = 80) # set the size and dpi of this plot
subplot(1, 1, 1)

X = np.linspace(-np.pi, np.pi, 256, endpoint = True)
C = np.cos(X)
S = np.sin(X)

plot(X, C, color = "blue", linewidth = 1.0, linestyle = "-")
plot(X, S, color = "green", linewidth = 1.0, linestyle = "-")

xlim(-4.0, 4.0) # set x limits
xticks(np.linspace(-4, 4, 9, endpoint = True)) # set x ticks

ylim(-1.0, 1.0) # set y limits
yticks(np.linspace(-1, 1, 5, endpoint = True)) # set y ticks

savefig("exercise_2.png", dpi = 80)

show()
