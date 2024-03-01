import math

from Lab_2.Lab_2_2.Task_4.task import word_count, replace_two_words, replace_1_with_one, delete_between_2h

print("\033[32m{}".format("Entering tests"))


def test_word_count():
    print("Testing word_count")
    temp = word_count("111412")
    assert temp == 1, "Expected 1, but get " + str(temp)
    print(" *Test 1 passed")
    temp = word_count("One two three four")
    assert temp == 4, "Expected 4, but get " + str(temp)
    print(" *Test 2 passed")
    temp = word_count("da da da")
    assert temp == 3, "Expected 3, but get " + str(temp)
    print(" *Test 3 passed")
    print("All word_count tests passed")


def test_replace_two_words():
    print("Testing replace_two_words")
    temp = replace_two_words("first second")
    assert temp == "second first", "Expected 'second first', but get " + str(temp)
    print(" *Test 1 passed")
    print("All replace_two_words tests passed")


def test_replace_1_with_one():
    print("Testing replace_1_with_one")
    temp = replace_1_with_one('1 1 1')
    assert temp == "one one one", "Expected 'one one one', but get " + str(temp)
    print(" *Test 1 passed")
    temp = replace_1_with_one("1")
    assert temp == "one", "Expected 'one', but get " + str(temp)
    print(" *Test 2 passed")
    print("All replace_1_with_one tests passed")


def test_delete_between_2h():
    print("Testing delete_between_2h")
    temp = delete_between_2h("abcdefghijkhlmnopqhrstuvwxyz")
    assert temp == "abcdefgrstuvwxyz", "Expected 'abcdefgrstuvwxyz', but get " + str(temp)
    print(" *Test 1 passed")
    print("All delete_between_2h tests passed")


test_word_count()
test_replace_two_words()
test_replace_1_with_one()
test_delete_between_2h()
