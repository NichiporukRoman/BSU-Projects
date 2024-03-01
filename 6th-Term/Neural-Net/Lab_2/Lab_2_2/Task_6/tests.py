import math

from Lab_2.Lab_2_2.Task_6.task import count_vowels_consonants, capitalize_sentence, \
    count_words_start_end_same_letter, rearrange_list, get_positive_elements_at_even_positions

print("\033[32m{}".format("Entering tests"))


def test_count_vowels_consonants():
    print("Testing count_vowels_consonants")
    temp_1, temp_2 = count_vowels_consonants("Hello, World!")
    assert [temp_1, temp_2] == [3, 7], "Expected [3, 7], but get " + str([temp_1, temp_2])
    print(" *Test 1 passed")
    print("All count_vowels_consonants tests passed")


def test_capitalize_sentence():
    print("Testing capitalize_sentence")
    temp = capitalize_sentence("hello world.")
    assert temp == "Hello. World.", "Expected 'Hello. World.', but get " + str(temp)
    print(" *Test 1 passed")
    print("All capitalize_sentence tests passed")


def test_count_words_start_end_same_letter():
    print("Testing count_words_start_end_same_letter")
    temp = count_words_start_end_same_letter("ror wqs qwq ew")
    assert temp == 2, "Expected 2, but get " + str(temp)
    print(" *Test 1 passed")
    print("All count_words_start_end_same_letter tests passed")


def test_get_positive_elements_at_even_positions():
    print("Testing get_positive_elements_at_even_positions")
    temp = get_positive_elements_at_even_positions([2, -1, 5, 3, -4, 6, 0, -2])
    assert temp == [2, 5], "Expected  [2, 5], but get " + str(temp)
    print(" *Test 1 passed")
    print("All get_positive_elements_at_even_positions tests passed")


test_count_vowels_consonants()
test_capitalize_sentence()
test_count_words_start_end_same_letter()
test_get_positive_elements_at_even_positions()
