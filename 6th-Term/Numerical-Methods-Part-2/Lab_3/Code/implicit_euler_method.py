import numpy as np


def implicit_euler(f, x_values, y0, h, num_iterations):
    x = np.zeros(num_iterations + 1)
    y = np.zeros((num_iterations + 1, len(y0)))
    y[0] = y0

    for i in range(num_iterations):
        x[i+1] = x[i] + h
        y_guess = y[i] + h * f(x[i+1], y[i])
        y[i+1] = y[i] + h * f(x[i+1], y_guess)

    return x, y
