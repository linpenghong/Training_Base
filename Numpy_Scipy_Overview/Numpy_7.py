from numpy import *

img1 = zeros((20, 20)) + 3
img1[4:-4, 4:-4] = 6
img1[7:-7, 7:-7] = 9
print img1

index1 = img1 > 2
print index1
index2 = img1 < 6
print index2
compound_index = index1 & index2 # boolean statement and operation
print compound_index

img2 = copy(img1)
img2[compound_index] = 0
print img2
