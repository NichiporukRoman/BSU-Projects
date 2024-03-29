import numpy as np


def nonlin(x, deriv=False):
    if deriv:
        return x * (1 - x)
    return 1 / (1 + np.exp(-x))


def inverse_nonlin(y):
    return -np.log(1/y - 1)
