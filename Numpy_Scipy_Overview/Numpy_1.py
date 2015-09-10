from numpy import *

arr = arange(1e7) # arr -> ndarray

larr = arr.tolist() # larr -> list

def list_times(alist, scalar):
    for i, val in enumerate(alist):
        alist[i] = val * scalar
    return alist

arr * 1.1

list_times(larr, 1.1)
