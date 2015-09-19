from pylab import *

n = 12
X = np.arange(n)

Y1 = (1 - X / float(n)) * np.random.uniform(0.5, 1.0, n)
Y2 = (1 - X / float(n)) * np.random.uniform(0.5, 1.0, n)

bar(X, +Y1, facecolor = "blue", edgecolor = "white", alpha = 0.4)
bar(X, -Y2, facecolor = "red", edgecolor = "white", alpha = 0.4)

# zip function
# zip([1, 2, 3], [4, 5, 6])
# return:
# [(1, 4), (2, 5), (3, 6)]
for x, y in zip(X, Y1):
    text(x + 0.4, y + 0.05, "%0.2f" % y, ha = "center", va = "bottom")

for x, y in zip(X, Y2):
    text(x + 0.4, - y - 0.1, "%0.2f" % y, ha = "center", va = "bottom")

xlim(-0.5, n)
xticks([])

ylim(-1.25, 1.25)
yticks([])

savefig("exercise_3.png", dpi = 200)

show()
