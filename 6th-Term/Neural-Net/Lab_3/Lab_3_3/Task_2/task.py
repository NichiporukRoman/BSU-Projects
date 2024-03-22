import math
import random


def log_base_2(number):
    return math.log(number) / math.log(2)


def generate_uniform_number():
    random.seed(45)
    return random.uniform(0, 1)


# next is cringe
def generate_same_numbers():
    for _ in range(4):
        print(generate_uniform_number())


def module_name(name):
    return dir(name)


print('Log base 2:', log_base_2(32))
print('Generate same numbers:'), generate_same_numbers()
print(module_name('matematic_module'))
