import numpy as np


u0 = np.array([2, 3, 0])
h = 0.001
x_range = [0, 1]
num_steps = int((x_range[1] - x_range[0]) / h)
x_values = np.linspace(x_range[0], x_range[1], num_steps + 1)
