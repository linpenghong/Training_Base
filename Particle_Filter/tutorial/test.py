from scipy.stats import norm

S = 30
distribution = norm(0, S)
for i in range(-S, S):
    print i, distribution.pdf(i)

import numpy as np
x = [3, 2, 1]
print np.argmax(x)
