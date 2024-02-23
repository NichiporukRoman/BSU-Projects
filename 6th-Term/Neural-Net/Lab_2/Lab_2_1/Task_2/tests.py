from Lab_2.Lab_2_1.Task_2.task import smallest_divisor, calculate_day, calculate_years, fibonacci_number_index

print("\033[32m{}".format("Entering tests"))


def test_smallest_divisor():
    print("Testing smallest_divisor")
    temp = smallest_divisor(12)
    assert temp == 2, "Expected 2, but get " + str(temp)
    print(" *Test 1 passed")
    temp = smallest_divisor(15)
    assert temp == 3, "Expected 3, but get " + str(temp)
    print(" *Test 2 passed")
    temp = smallest_divisor(17)
    assert temp == 17, "Expected 17, but get " + str(temp)
    print(" *Test 3 passed")
    print("All smallest_divisor tests passed")


def tests_calculate_day():
    print("Testing calculate_day")
    temp = calculate_day(10, 200)
    assert temp == 33, "Expected 33, but get " + str(temp)
    print(" *Test 1 passed")
    temp = calculate_day(10, 11)
    assert temp == 2, "Expected 1, but get " + str(temp)
    print(" *Test 2 passed")
    temp = calculate_day(10, 1)
    assert temp == 1, "Expected 0, but get " + str(temp)
    print(" *Test 3 passed")
    print("\033[32m{}".format("All calculate_day tests passed"))


def tests_calculate_years():
    print("Testing is_leap_year")
    temp = calculate_years(10, 10, 100)
    assert temp == 25, "Expected 25, but get " + str(temp)
    print(" *Test 1 passed")
    temp = calculate_years(10, 11, 100)
    assert temp == 23, "Expected 23, but get " + str(temp)
    print(" *Test 2 passed")
    temp = calculate_years(10, 11, 10)
    assert temp == 0, "Expected 0, but get " + str(temp)
    print(" *Test 3 passed")
    print("\033[32m{}".format("All calculate_years tests passed"))


def tests_fibonacci_number_index():
    print("Testing can_rook_move")
    temp = fibonacci_number_index(55)
    assert temp == 10, "Expected 10, but get " + str(temp)
    print(" *Test 1 passed")
    temp = fibonacci_number_index(2)
    assert temp == 3, "Expected 3, but get " + str(temp)
    print(" *Test 2 passed")
    temp = fibonacci_number_index(1)
    assert temp == 1, "Expected 1, but get " + str(temp)
    print(" *Test 3 passed")
    print("\033[32m{}".format("All fibonacci_number_index tests passed"))


test_smallest_divisor()
tests_calculate_day()
tests_calculate_years()
tests_fibonacci_number_index()
