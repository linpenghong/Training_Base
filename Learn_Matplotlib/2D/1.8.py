from pylab import *

n = 20
Z = np.ones(n)
Z[-1] *= 2

axes([0.025, 0.025, 0.95, 0.95])

pie(Z, explode = Z * 0.05, colors = ["%f" % (i / float(n)) for i in range(n)])
# pie --> plot a pie chart
# explode --> the size of spliting gap between each fraction
# colors --> which color to plot for each fraction
gca().set_aspect("equal");
# gca() --> get the current Axes
# gca().set_aspect("equal") --> same scaling from data to plot units for x and y

xticks([])
yticks([])

savefig("Exercise_6.png", dpi = 200)

show()
