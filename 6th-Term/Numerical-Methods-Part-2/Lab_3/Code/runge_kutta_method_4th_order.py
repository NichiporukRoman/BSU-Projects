import numpy as np


def runge_kutta_fourth_order(f, h, y0, x_values):
    y_values = np.zeros((len(x_values), len(y0)))
    y_values[0] = y0
    for i in range(1, len(x_values)):
        xi = x_values[i]
        yi_prev = y_values[i - 1]
        ki0 = f(xi, yi_prev)
        ki1 = f(xi + h / 2, yi_prev + h / 2 * ki0)
        ki2 = f(xi + h / 2, yi_prev + h / 2 * ki1)
        ki3 = f(xi + h, yi_prev + h * ki2)
        yi_new = yi_prev + h / 6 * (ki0 + 2 * ki1 + 2 * ki2 + ki3)
        y_values[i] = yi_new
    return x_values, y_values
