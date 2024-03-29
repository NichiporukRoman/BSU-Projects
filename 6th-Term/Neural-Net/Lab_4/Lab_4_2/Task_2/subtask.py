import numpy as np
from Lab_4.Lab_4_2 import utilities
from Lab_4.Lab_4_2.Task_2 import prepared_data

x = prepared_data.data_cars_input_for_learning
y = prepared_data.data_cars_output_for_learning

np.random.seed(1)

syn0 = 2 * np.random.random((4, 3)) - 1

for iter in range(60000):
    l0 = x
    l1 = utilities.nonlin(np.dot(l0, syn0))

    l1_error = y - l1
    l1_delta = l1_error * utilities.nonlin(l1, True)
    syn0 += l0.T.dot(l1_delta)


l0 = prepared_data.data_cars_input_test
l11 = np.dot(l0, syn0)
l1 = utilities.nonlin(l11)

print('Prognosis: ', l1)
