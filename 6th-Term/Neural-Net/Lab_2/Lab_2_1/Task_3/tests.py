import math

from Lab_2.Lab_2_1.Task_3.task import get_last_digit, get_fractional_part, get_first_decimal_digit, round_ru

print("\033[32m{}".format("Entering tests"))


def test_get_last_digit():
    print("Testing get_last_digit")
    temp = get_last_digit(111412)
    assert temp == 2, "Expected 2, but get " + str(temp)
    print(" *Test 1 passed")
    temp = get_last_digit(14245)
    assert temp == 5, "Expected 5, but get " + str(temp)
    print(" *Test 2 passed")
    temp = get_last_digit(1)
    assert temp == 1, "Expected 1, but get " + str(temp)
    print(" *Test 3 passed")
    print("All test_get_last_digit tests passed")


def test_get_fractional_part():
    print("Testing get_fractional_part")
    temp = get_fractional_part(1.11)
    assert math.isclose(temp, 0.11), "Expected 0.11, but get " + str(temp)
    print(" *Test 1 passed")
    temp = get_fractional_part(12.312321312)
    assert math.isclose(temp, 0.312321312), "Expected 0.312321312, but get " + str(temp)
    print(" *Test 2 passed")
    temp = get_fractional_part(1)
    assert math.isclose(temp, 0), "Expected 0, but get " + str(temp)
    print(" *Test 3 passed")
    print("All get_fractional_part tests passed")


def test_get_first_decimal_digit():
    print("Testing get_first_decimal_digit")
    temp = get_first_decimal_digit(112.24)
    assert temp == 2, "Expected 2, but get " + str(temp)
    print(" *Test 1 passed")
    temp = get_first_decimal_digit(1424.543)
    assert temp == 5, "Expected 5, but get " + str(temp)
    print(" *Test 2 passed")
    temp = get_first_decimal_digit(1.13214)
    assert temp == 1, "Expected 1, but get " + str(temp)
    print(" *Test 3 passed")
    print("All get_first_decimal_digit tests passed")


def test_round_ru():
    print("Testing get_first_decimal_digit")
    temp = round_ru(112.24)
    assert temp == 112, "Expected 112, but get " + str(temp)
    print(" *Test 1 passed")
    temp = round_ru(1424.543)
    assert temp == 1425, "Expected 1425, but get " + str(temp)
    print(" *Test 2 passed")
    temp = round_ru(1.13214)
    assert temp == 1, "Expected 1, but get " + str(temp)
    print(" *Test 3 passed")
    print("All round_ru tests passed")


test_get_last_digit()
test_get_fractional_part()
test_get_first_decimal_digit()
test_round_ru()
