import math
from functools import partial
from typing import List


def newton_interpolation(x, y):
    n = len(x)
    divided_differences = y[:]
    res = []
    for i in range(1, n + 1):
        next_divided_differences = []
        for j in range(n - i):
            divided_difference = (divided_differences[j + 1] - divided_differences[j]) / (x[j + i] - x[j])
            next_divided_differences.append(divided_difference)
        res.append(divided_differences[0])
        divided_differences = next_divided_differences
    return res


def create_polynomial(x: List[float], y: List[float]):
    coeffs = newton_interpolation(x, y)
    if len(x) == 3:
        print("\nAnalytical representation of the 2nd-degree polynomial: ", end="")
        print(f"{coeffs[0]} + {coeffs[1]} * (x - {x[0]}) + {coeffs[2]} * (x - {x[0]}) * (x - {x[1]})")

    def polynomial(point):
        res = 0
        for i in range(len(x)):
            term = coeffs[i]
            for j in range(i):
                term *= (point - x[j])
            res += term
        return res

    return partial(polynomial)


def get_equal_points(n, a, b):
    step = (b - a) / n
    points = []
    for i in range(n + 1):
        points.append(a + i * step)
    return points


def get_chebyshev_points(n, a, b):
    step = (b - a) / 2
    middle = (a + b) / 2
    points = []
    for i in range(n + 1):
        point = middle + step * math.cos(((2 * i + 1) * math.pi) / (2 * (n + 1)))
        points.append(point)
    return points



