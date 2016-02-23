import numpy as np
import random

from scipy.stats import norm

K = 20

N = 100

NT = 30

X = np.zeros(K)

stdnorm = norm(0, 1)

X = np.random.normal(0, 0.1, K)
print X

# Initialise Particles
x = np.random.random_sample(N)
# Initialise Weight
w = np.full(N, 1.0 / N)

sigma = 0.5

def resample():
    global x
    c = np.zeros(N)
    u = np.zeros(N)
    y = np.zeros(N)
    c[0] = w[0]
    for i in range(1, N):
        c[i] = c[i - 1] + w[i]
    print c
    u[0] = random.uniform(0, 1.0 / N)
    for i in range(N):
        u[i] = u[0] + 1.0 / N * i
    i = 0
    for j in range(N):
        while (u[j] > c[i]):
            i += 1
        y[j] = x[i]
        w[j] = 1.0 / N
    x = y[:]

for k in range(K):
    global sigma
    # Renew Samples
    x = [u + random.gauss(0, 100 * sigma) for u in x]
    # Update Weight
    for i in range(0, N):
        w[i] *= stdnorm.pdf(x[i] - X[k])
    w /= sum(w)
    # print estimation
    print "estimation = ", sum(w * x)
    # Calculate neff
    neff = 1.0 / sum(w * w)
    print "neff = ", neff
    # Update sigma
    sigma = np.var(w)
    print "sigma = ", sigma
    if (neff < NT):
        resample()
