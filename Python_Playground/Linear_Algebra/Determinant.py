import numpy as np

A1 = np.array([[0, 0, 1],
               [1, 0, 0],
               [0, 1, 0]])

A2 = np.array([[0, 1, 0],
               [0, 0, 1],
               [1, 0, 0]])

print np.linalg.det(A1)
print np.linalg.det(A2)

print A1.dot(A2)

B1 = np.array([[0, -1, 0],
               [1, 0, 0],
               [0, 0, 1]])

B2 = np.array([[-1, 0, 0],
               [0, -1, 0],
               [0, 0, 1]])

B3 = np.array([[0, 1, 0],
               [-1, 0, 0],
               [0, 0, 1]])

print np.linalg.det(B1)
print np.linalg.det(B2)
print np.linalg.det(B3)

#print "B2 * B3 = \n", B2.dot(B3)
#print "B3 * B1 = \n", B3.dot(B1)
#print "B1 * B2 = \n", B1.dot(B2)

print "A1 * B1 = \n", A1.dot(B1)
print "A1 * B2 = \n", A1.dot(B2)
print "A1 * B3 = \n", A1.dot(B3)
print "A2 * B1 = \n", A2.dot(B1)
print "A2 * B2 = \n", A2.dot(B2)
print "A2 * B3 = \n", A2.dot(B3)

A = np.array([[0, 0, -1],
              [0, 1, 0],
              [1, 0, 0]])

print np.linalg.det(A)

print A.dot(np.array([0, 1, 0]))
