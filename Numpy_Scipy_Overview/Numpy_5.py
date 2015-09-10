from numpy import *

arr = array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print arr

# [0, 1] element -> 0 : row, 1 : column
print arr[0, 1]

# slice a column
print arr[:, 1]

# slice a row
print arr[1, :]
