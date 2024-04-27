import math
import matplotlib.pyplot as plt
import numpy as np


def f(x, y):
    u, v, w = y
    return np.array([u + v - w + math.sqrt(x),
                     -3 * u - 3 * v + 3 * w,
                     -2 * u - 2 * v + 2 * w + math.pow(x, 2)])


def display_data(x_values, y_values, title):
    u_values = y_values[:, 0]
    v_values = y_values[:, 1]
    w_values = y_values[:, 2]
    plt.figure(figsize=(10, 6))
    plt.plot(x_values, u_values, label='u(x)')
    plt.plot(x_values, v_values, label='v(x)')
    plt.plot(x_values, w_values, label='w(x)')
    plt.title(title)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.legend()
    plt.grid(True)
    plt.show()
