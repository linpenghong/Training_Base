from pylab import *
from scipy.cluster import vq # vq -> vector quantization

# create data
c1 = np.random.randn(100, 2) + 5
c2 = np.random.randn(30, 2) - 5
c3 = np.random.randn(50, 2)
print "cluster 1:\n", c1
print "cluster 2:\n", c2
print "cluster 3:\n", c3

# pool all the data into one 180 x 2 array
data = vstack([c1, c2, c3])

figure(figsize = (10, 5), dpi = 800)

# calculate the cluster centroids and variance from k-means
centroids, variance = vq.kmeans(data, 3)

# seperate the data by assigning to its nearest centroid
identified, distance  = vq.vq(data, centroids)

vqc1 = data[identified == 0]
vqc2 = data[identified == 1]
vqc3 = data[identified == 2]

scatter(vqc1[:, 0], vqc1[:, 1], c = "red")
scatter(vqc2[:, 0], vqc2[:, 1], c = "blue")
scatter(vqc3[:, 0], vqc3[:, 1], c = "green")

savefig("Scipy_14.png", dpi = 800)
