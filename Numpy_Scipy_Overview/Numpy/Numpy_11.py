from numpy import *

A = matrix([[3, 6, -5],
            [1, -3, 2],
            [5, -1, 4]])
print A

B = matrix([[12],
            [-2],
            [10]])
print B

print A ** (-1) * B
