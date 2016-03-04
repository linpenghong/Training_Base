import numpy as np
import random
import copy

from scipy.stats import norm

import pylab as pl

# Upper Case -> Actual State
# Lower Case -> Observation

K = 20

X = np.zeros(K)
Y = np.zeros(K)

V_X = np.zeros(K)
V_Y = np.zeros(K)

A_X = 1
A_Y = 1

def move(i):
    X[i] = X[i - 1] + V_X[i] + random.gauss(0, V_X[i] / 2)
    Y[i] = Y[i - 1] + V_Y[i] + random.gauss(0, V_Y[i] / 2)

def acc(i):
    V_X[i] = V_X[i - 1] + A_X + random.gauss(0, A_X / 2)
    V_Y[i] = V_Y[i - 1] + A_Y + random.gauss(0, A_Y / 2)

for i in range(1, K):
    acc(i)
    move(i)

fig = pl.figure(figsize = (10, 10), dpi = 500)

pl.scatter(X, Y, color = "red", label = "Actual Location")

x = [u + random.gauss(0, 5) for u in X]
y = [u + random.gauss(0, 5) for u in Y]

pl.scatter(x, y, color = "blue", label = "Observed Location")

pl.title("Actual Location & Observed Location")

pl.legend()

fig.savefig("Figures/Actual_Location_Observed_Location.png", dpi = 500)

### Using Generic Particle Filter to Track the Path ###

N = 500 # Number of Particles

p = [] # Particles
for i in range(N):
    p.append((random.uniform(-200, 200), \
              random.uniform(-200, 200), \
              random.uniform(-K, K), \
              random.uniform(-K, K)))
w = np.full(N, 1.0 / N) # Weights of Particles

distribution = norm(0, 20)

def possib(u, x, y):
    return distribution.pdf(u[0] - x) * distribution.pdf(u[1] - y)

def resample():
    global p
    c = np.zeros(N)
    u = np.zeros(N)
    y = copy.deepcopy(p)
    c[0] = w[0]
    for i in range(1, N):
        c[i] = c[i - 1] + w[i]
    # print c
    u[0] = random.uniform(0, 1.0 / N)
    for i in range(N):
        u[i] = u[0] + 1.0 / N * i
    # print u
    i = 0
    # print "Index of Max Particle is " + str(np.argmax(w))
    for j in range(N):
        while (u[j] > c[i]):
            i += 1
        # print "u[j] = " + str(u[j])
        # print "c[i] = " + str(c[i])
        # print "assign particle " + str(i) + " to particle " + str(j)
        y[j] = p[i]
        w[j] = 1.0 / N
    p = copy.deepcopy(y)

distur = 5

for k in range(1, K):
    # Re-draw Particles
    p = [(u[0] + u[2] + random.gauss(0, distur), \
          u[1] + u[3] + random.gauss(0, distur), \
          u[2] + 1 + random.gauss(0, distur), \
          u[3] + 1 + random.gauss(0, distur)) for u in p]
    # Re-assign Weights
    for i in range(N):
        w[i] *= possib(p[i], x[k], y[k])
    w /= sum(w)
    # Plot the Particles
    fig_p = pl.figure(figsize = (10, 10), dpi = 500)
    pl.scatter([u[0] for u in p], [u[1] for u in p], \
               s = 5 * N * w, \
               color = "green", \
               alpha = "0.6", \
               label = "Particles")
    pl.scatter(X[k], Y[k], color = "red", label = "Actual Location")
    pl.scatter(x[k], y[k], color = "blue", label = "Observed Location")
    pl.legend()
    fig_p.savefig("Figures/Particles_" + str(k) + ".png", dpi = 500)
    # Calculate Neff
    Neff = 1.0 / sum(w * w)
    print "Neff = ", Neff
    if (Neff < 3):
        print "Perform Resampling in Turn " + str(k)
        resample()
