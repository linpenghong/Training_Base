from pylab import *

figure(figsize = (8, 6), dpi = 80) # set the size and dpi of this plot
subplot(1, 1, 1)

X = np.linspace(-np.pi, np.pi, 256, endpoint = True)
C = np.cos(X)
S = np.sin(X)

plot(X, C, color = "blue", linewidth = 2.0, linestyle = "-", label = "cosine")
plot(X, S, color = "red", linewidth = 2.0, linestyle = "-", label = "sine")
legend(loc = "upper left")

xlim(-4.0, 4.0) # set x limits

xticks([-np.pi, -np.pi / 2, 0, np.pi /2 , np.pi],
       [r'$-\pi$', r'$-\pi/2$', r'$0$', r'$+\pi/2$', r'$+\pi$'])
# set x ticks in LaTeX format

ylim(-1.1, 1.1) # set y limits
yticks([-1, 1],
       [r'$-1$', r'$+1$'])
# set y ticks in LaTeX format

# set spines' location
ax = gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_position(('data', 0))
ax.spines['left'].set_position(('data', 0))
ax.xaxis.set_ticks_position('bottom')
ax.yaxis.set_ticks_position('left')

# add annotate points
t = 2 * np.pi / 3
ax.plot([t, t], [0, np.cos(t)], color = "blue", linewidth = 2.0, linestyle = "--")
ax.plot([t, t], [0, np.sin(t)], color = "red", linewidth = 2.0, linestyle =
"--")

ax.scatter([t, ], [np.cos(t), ], 50, color = "blue")
ax.scatter([t, ], [np.sin(t), ], 50, color = "red")

ax.annotate(r'$\cos(\frac{2\pi}{3})=-\frac{1}{2}$',
            xy = (t, np.cos(t)),
            xycoords = "data",
            xytext = (-90, -50),
            textcoords = "offset points",
            fontsize = 16,
            arrowprops = dict(arrowstyle = "->", connectionstyle =
                "arc3,rad=.0"))

ax.annotate(r'$\sin\frac{2\pi}{3})=\frac{\sqrt{3}}{2}$',
            xy = (t, np.sin(t)),
            xycoords = "data",
            xytext = (10, 30),
            textcoords = "offset points",
            fontsize = 16,
            arrowprops = dict(arrowstyle = "->", connectionstyle =
                "arc3,rad=.0"))

savefig("Example_1", dpi = 200)

show()
