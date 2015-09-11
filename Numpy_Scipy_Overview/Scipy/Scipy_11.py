from pylab import *
from scipy.stats import norm

x = linspace(-5, 5, 1000)

# set up a norm distribution
# loc -> mean
# scale -> stddev
dist = norm(loc = 0, scale = 1)

# retrieve PDF and CFD of dist
# PDF -> probability density function
# CDF -> cumulative distribution function
pdf = dist.pdf(x)
cdf = dist.cdf(x)

# draw 500 random values from the norm
sample = dist.rvs(500)
print sample
