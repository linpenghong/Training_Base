from pylab import *
from scipy import stats

# generate a normal distribution sample with 100 elements
sample = np.random.randn(100)

# harmonic mean
out = stats.hmean(sample[sample > 0])
print "Harmonic mean = " + str(out)

# the mean, where values below -1 and above 1 are removed
out = stats.tmean(sample, limits = (-1, 1))
print "Trimmed mean = " + str(out)

# calculate the skewness of the sample
out = stats.skew(sample)
print "Skewness = " + str(out)

out = stats.describe(sample)
print out
