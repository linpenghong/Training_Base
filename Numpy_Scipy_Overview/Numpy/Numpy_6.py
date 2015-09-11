from numpy import *

arr = arange(5)
print arr

# create an index array
index = where(arr > 2)
print index

# create the desired array by selecting
new_arr = arr[index]
print new_arr

# create the desired array by removing
new_arr = delete(arr, index)
print new_arr
