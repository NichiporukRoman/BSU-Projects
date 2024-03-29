import numpy as np
from Lab_4.Lab_4_1 import utilities


x = np.array([[0, 0, 1],
              [0, 1, 1],
              [1, 0, 1],
              [1, 1, 1]])
y = np.array([[0, 0, 1, 1]]).T

np.random.seed(1)

syn0 = 2 * np.random.random((3, 4)) - 1
syn1 = 2 * np.random.random((4, 4)) - 1
syn2 = 2 * np.random.random((4, 1)) - 1

for iter in range(1000):
    l0 = x
    l1 = utilities.nonlin(np.dot(l0, syn0))
    l2 = utilities.nonlin(np.dot(l1, syn1))
    l3 = utilities.nonlin(np.dot(l2, syn2))

    l3_error = y - l3
    l3_delta = l3_error * utilities.nonlin(l3, True)

    l2_error = l3_delta.dot(syn2.T)
    l2_delta = l2_error * utilities.nonlin(l2, True)

    l1_error = l2_delta.dot(syn1.T)
    l1_delta = l1_error * utilities.nonlin(l1, True)

    syn2 += l2.T.dot(l3_delta)
    syn1 += l1.T.dot(l2_delta)
    syn0 += l0.T.dot(l1_delta)


print("Output After Training:")
print(l3)

print("Error After Training:")
print(l3_error)
