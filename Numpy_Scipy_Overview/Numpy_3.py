from numpy import *

arr1d = arange(1000)

# reshape the array to 10x10x10 3D array
print arr1d.reshape((10, 10, 10))

# reshape the array to 10x10x10 3D array
print reshape(arr1d, (10, 10, 10))

# flatten an array
print zeros((10, 10, 10, 10)).ravel()
