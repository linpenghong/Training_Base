import sys
import numpy as np
from math import *

x = float(sys.argv[1])
y = float(sys.argv[2])
z = float(sys.argv[3])

x /= 180
y /= 180
z /= 180

x *= np.pi
y *= np.pi
z *= np.pi

cx = cos(x)
cy = cos(y)
cz = cos(z)

sx = sin(x)
sy = sin(y)
sz = sin(z)

cc = cy * cx;
cs = cy * sx;
sc = sy * cx;
ss = sy * sx;

A = np.array([[cz * cc - sz * sx, cz * cs + sz * cx, -cz * sy],
              [-sz * cc - cz * sx, -sz * cs + cz * cx, sz * sy],
              [sc, ss, cy]])

v1 = np.array([0, 1, 0])
v2 = np.array([-0.5, -0.809017, 0.309017])
v3 = np.array([0.5, -0.809017, 0.309017])

print A

print A.dot(v1)
print A.dot(v2)
print A.dot(v3)
