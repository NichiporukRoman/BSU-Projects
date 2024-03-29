import numpy as np
from Lab_4.Lab_4_1 import utilities


X = np.array([[0, 0, 1],
              [0, 1, 1],
              [1, 0, 1],
              [1, 1, 1]])
y = np.array([[0, 0, 1, 1]]).T

np.random.seed(1)

syn0 = 2 * np.random.random((3, 1)) - 1

for iter in range(1000):
    l0 = X
    l1 = utilities.nonlin(np.dot(l0, syn0))
    l1_error = y - l1
    l1_delta = l1_error * utilities.nonlin(l1, True)
    syn0 += np.dot(l0.T, l1_delta)


print("Output After Training:")
print(l1)
