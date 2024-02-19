import numpy as np


def sig(x):
    return 1 / (1 + np.exp(-x))


def logical_xor(str1, str2):
    if str1 != str2:
        return 1
    else:
        return 0
