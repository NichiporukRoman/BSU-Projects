import math


def distance(x1, y1, x2, y2):
    try:
        return math.sqrt(math.pow(x2 - x1, 2) + math.pow(y2 - y1, 2))
    except ValueError:
        raise ValueError("Error: incorrect value")
    except TypeError:
        raise TypeError("Error: incorrect data type")


def power(value, level):
    res = 1
    for i in range(level):
        res *= value

    return res


def capitalize(word):
    first_letter = word[0]
    capitalized_word = chr(ord(first_letter) - 32) + word[1:]
    return capitalized_word


def maximum(*args):
    if len(args) == 0:
        raise ValueError("Error: no arguments provided")

    max_value = args[0]
    for value in args:
        if value > max_value:
            max_value = value

    return max_value


print(distance(-2, -1.5, 2, 1.5))
print(power(1.5, 3))
print(capitalize("boom"))
print(maximum(1.5, 3, 3, -12, 213))
str1 = "Sdsda"
