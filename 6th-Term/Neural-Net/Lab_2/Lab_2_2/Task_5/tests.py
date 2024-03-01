import math

from Lab_2.Lab_2_2.Task_5.task import get_even_numbers_by_index, get_elements_greater_previous, \
    count_elements_greater_neighbors, swap_min_max

print("\033[32m{}".format("Entering tests"))


def test_get_even_numbers_by_index():
    print("Testing get_even_numbers_by_index")
    temp = get_even_numbers_by_index([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    assert temp == [0, 2, 4, 6, 8, 10], "Expected [0, 2, 4, 6, 8, 10], but get " + str(temp)
    print(" *Test 1 passed")
    print("All get_even_numbers_by_index tests passed")


def test_get_elements_greater_previous():
    print("Testing get_elements_greater_previous")
    temp = get_elements_greater_previous([1, 3, 5, 2, 4, 7, 6, 9])
    assert temp == [3, 5, 4, 7, 9], "Expected [3, 5, 4, 7, 9], but get " + str(temp)
    print(" *Test 1 passed")
    print("All get_elements_greater_previous tests passed")


def test_count_elements_greater_neighbors():
    print("Testing count_elements_greater_neighbors")
    temp = count_elements_greater_neighbors([1, 3, 5, 2, 4, 7, 6, 9])
    assert temp == [5, 7], "Expected [5, 7], but get " + str(temp)
    print(" *Test 1 passed")
    print("All count_elements_greater_neighbors tests passed")


def test_swap_min_max():
    print("Testing swap_min_max")
    temp = swap_min_max([1, 3, 5, 2, 10, 4, 7, 6, 9])
    assert temp == [10, 3, 5, 2, 1, 4, 7, 6, 9], "Expected [10, 3, 5, 2, 1, 4, 7, 6, 9], but get " + str(temp)
    print(" *Test 1 passed")
    print("All swap_min_max tests passed")


test_get_even_numbers_by_index()
test_get_elements_greater_previous()
test_get_even_numbers_by_index()
test_get_elements_greater_previous()
