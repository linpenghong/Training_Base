from pylab import *
from scipy import stats

# generate a normal distribution sample with 100 elements
sample = np.random.randn(100)

# normaltest -> test whether the sample is a normal distribution or not
out = stats.normaltest(sample)
print "normaltest:"
print "Z-score = " + str(out[0])
print "P-value = " + str(out[1])

# kstest is the Kolmogorov-Smirnov test for goodness of fit
out = stats.kstest(sample, "norm")
print "kstest for the normal distribution"
print "D = " + str(out[0])
print "P-value = " + str(out[1])

# kstest against Wald distributin
out = stats.kstest(sample, "wald")
print "kstest for the Wald distribution"
print "D = " + str(out[0])
print "P-value = " + str(out[1])
