from Lab_2.Lab_2_1.Task_1.task import max_of_3, how_many_numbers_are_equals, is_leap_year, can_rook_move

print("\033[32m{}".format("Entering tests"))


def test_max_of_3():
    print("Testing test_max_of_3")
    temp = max_of_3(1, 2, 3)
    assert temp == 3, "Expected 3, but get " + str(temp)
    print(" *Test 1 passed")
    temp = max_of_3(2, 23, 3)
    assert temp == 23, "Expected 23, but get " + str(temp)
    print(" *Test 2 passed")
    temp = max_of_3(1, -2, -3)
    assert temp == 1, "Expected 1, but get " + str(temp)
    print(" *Test 3 passed")
    print("All test_max_of_3 tests passed")


def tests_how_many_numbers_are_equals():
    print("Testing how_many_numbers_are_equals")
    temp = how_many_numbers_are_equals(1, 2, 3)
    assert temp == 0, "Expected 0, but get " + str(temp)
    print(" *Test 1 passed")
    temp = how_many_numbers_are_equals(1, 1, 0)
    assert temp == 2, "Expected 2, but get " + str(temp)
    print(" *Test 2 passed")
    temp = how_many_numbers_are_equals(32, 32, 32)
    assert temp == 3, "Expected 3, but get " + str(temp)
    print(" *Test 3 passed")
    print("\033[32m{}".format("All how_many_numbers_are_equals tests passed"))


def tests_is_leap_year():
    print("Testing is_leap_year")
    temp = is_leap_year(1000)
    assert temp == False, "Expected False, but get " + str(temp)
    print(" *Test 1 passed")
    temp = is_leap_year(1111)
    assert temp == False, "Expected False, but get " + str(temp)
    print(" *Test 2 passed")
    temp = is_leap_year(400)
    assert temp, "Expected True, but get " + str(temp)
    print(" *Test 3 passed")
    print("\033[32m{}".format("All is_leap_year tests passed"))


def tests_can_rook_move():
    print("Testing can_rook_move")
    temp = can_rook_move(1, 2, 3, 2)
    assert temp == "YES", "Expected YES, but get " + str(temp)
    print(" *Test 1 passed")
    temp = can_rook_move(1, 2, 3, 1)
    assert temp == "NO", "Expected NO, but get " + str(temp)
    print(" *Test 2 passed")
    temp = can_rook_move(1, 2, 1, 2)
    assert temp == "YES", "Expected YES, but get " + str(temp)
    print(" *Test 3 passed")
    print("\033[32m{}".format("All can_rook_move tests passed"))


test_max_of_3()
tests_how_many_numbers_are_equals()
tests_is_leap_year()
tests_can_rook_move()
