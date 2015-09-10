from numpy import *

alist = [1, 2, 3]

# wrap from a list
print array(alist)

# create an array of zeros
print zeros(5)

# create an array from 0 to 100
print arange(100)

# create an array from 10 to 100
print arange(10, 100)

# create an array from 0 to 1 in 100 steps linearly
print linspace(0, 1, 100)

# create an array from 0 to 1 in 100 steps in log
print logspace(0, 1, 100, base = 10.0)

# create a 5x5 array of zeros
print zeros((5, 5))

# create a 5x5x5 cube of ones as integer
print zeros((5, 5, 5)).astype(int) + 1 # astyle for setting data type

# create a 5x5x5 cube of ones as 16-bit float
print ones((5, 5, 5)).astype(float16)
