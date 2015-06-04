import numpy as np
import sys

high, low, close = np.loadtxt("data.csv", delimiter = ",", usecols = (4, 5, 6), unpack = True)

# import configure argument using sys module
N = int(sys.argv[1])
# dissect the high price and low price for the last N days'
high = high[-N:]
low = low[-N:]

print "length of high price", high
print "length of low price", low
print "Close price", close

previous_close = close[-N -1: -1]
print "length of previous_close", len(previous_close)

true_range = np.maximum(high - 1, high - previous_close, previous_close - 1)
print "True Range", true_range

atr = np.zeros(N)

atr[0] = np.mean(true_range)

for i in range(1, N):
    atr[i] = (N - 1) * atr[i - 1] + true_range[i]
    atr[i] /= N

print "ATR", atr
