import numpy as np
import sys

high, low, close = np.loadtxt("data.csv", delimiter = ",", usecols = (4, 5, 6), unpack = True)

N = int(sys.argv[1])

high = high[:N]
low = low[:N]

print "high price", high
print "low price", low

# a = high makes a and high object points to the same location in memory
""""
a = high
a.fillill(1.5)
print "high price", high
print "filled", a
"""

a = high.copy()
a.fill(1.5)
print "high price", high
print "filled", a

# clip(lowest, highest)
# any element lower than lowest will change to lowest
# any element higher than highest will change to highest
a = high.copy()
print a.clip(10, 20)
"""
In this case, a itself can NOT modified
clip function only return an array
"""

# compress will return an array compressed by a specific condition
print "Compressed", a.compress(a > 500)
