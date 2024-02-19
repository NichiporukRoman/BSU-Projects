from Lab_2.Lab_2_1.Task_1.task import max_of_3, how_many_numbers_are_equals


print("\033[32m{}".format("Entering tests"))


def test_max_of_3():
    print("Testing test_max_of_3")
    assert max_of_3(1, 2, 3) == 3, "Should be 3"
    print("Test 1 passed")
    assert max_of_3(2, 23, 3) == 23, "Should be 23"
    print("Test 2 passed")
    assert max_of_3(1, -2, -3) == 1, "Should be 1"
    print("Test 3 passed")
    print("All test_max_of_3 tests passed")


def tests_how_many_numbers_are_equals():
    print("Testing how_many_numbers_are_equals")
    assert how_many_numbers_are_equals(1, 2, 3) == 0, "Should be 0"
    print("Test 1 passed")
    assert how_many_numbers_are_equals(1, 1, 0) == 2, "Should be 2"
    print("Test 2 passed")
    assert how_many_numbers_are_equals(32, 32, 32) == 3, "Should be 3"
    print("Test 3 passed")
    print("\033[32m{}".format("All how_many_numbers_are_equals tests passed"))


test_max_of_3()
tests_how_many_numbers_are_equals()
