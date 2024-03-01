import math
import random
import matematic_module as mat


def log_base_2(number):
    return math.log(number) / math.log(2)


def generate_uniform_number():
    return random.uniform(0, 1)


# next is cringe
def generate_same_numbers():
    random_number = generate_uniform_number()

    for _ in range(4):
        print(random_number)


# task 3 wtf is it


generate_same_numbers()
print(mat.log_base_a(10000, 10))
