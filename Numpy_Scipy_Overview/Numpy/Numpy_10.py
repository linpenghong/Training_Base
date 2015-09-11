from numpy import *

table = loadtxt("example.txt",
                dtype = {"names" : ('ID', 'Result', 'Type'),
                         "formats" : ('S4', 'f4', 'i2')})
print table
