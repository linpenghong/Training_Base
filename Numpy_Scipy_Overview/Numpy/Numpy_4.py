from numpy import *

recarr = zeros((2, ), dtype = ('i4, f4, a10'))
# i4 -> 32-bit integer
# f4 -> 32-bit float
# a10 -> 10 characters long string
print recarr

# create the columns to put in the recarray
col1 = arange(2) + 1
col2 = arange(2, dtype = 'f4')
col3 = ['Hello', 'World']

print col1
print col2
print col3

toadd = zip(col1, col2, col3)
print toadd

recarr[:] = toadd
print recarr

# assign names to each column
recarr.dtype.names = ('Integers', 'Floats', 'Strings')
print recarr

# call a column by its name
print recarr['Integers']
