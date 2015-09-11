from numpy import *

# create an array of random numbers
# Gaussian distribution, mean = 0, stddev = 1
# AKA, standard Gaussian distribution
a = random.randn(100)
print a

# filter
b = a[a > 0.2]
print b

# execute some operation on b
b = b ** 2 - 2
print b

# put the modified elements back into the original array
a[a > 0.2] = b
