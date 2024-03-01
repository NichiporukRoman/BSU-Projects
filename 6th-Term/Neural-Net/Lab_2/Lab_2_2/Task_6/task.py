import random


def count_vowels_consonants(string_):
    vowels_ = 'aeiouAEIOU'
    consonants_ = 'bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ'
    vowel_count = 0
    consonant_count = 0

    for char in string_:
        if char in vowels_:
            vowel_count += 1
        elif char in consonants_:
            consonant_count += 1

    return vowel_count, consonant_count


def capitalize_sentence(sentence_):
    sentence_ = sentence_[:-1]
    words = sentence_.split()
    capitalized_words = [word.capitalize() + '.' for word in words]
    capitalized_sentence_ = ' '.join(capitalized_words)

    return capitalized_sentence_


def letter_frequency(string_):
    frequency_ = {}

    for letter_ in string_:
        if letter_.isalpha():
            if letter_ in frequency_:
                frequency_[letter_] += 1
            else:
                frequency_[letter_] = 1

    return frequency_


def count_words_start_end_same_letter(string_):
    words = string_.split()
    count_ = 0

    for word in words:
        if word[0].lower() == word[-1].lower():
            count_ += 1

    return count_


def find_max_min_elements(lst):
    max_value_ = max(lst)
    min_value_ = min(lst)
    max_indices_ = [i for i, val in enumerate(lst) if val == max_value_]
    min_indices_ = [i for i, val in enumerate(lst) if val == min_value_]

    return max_value_, max_indices_, min_value_, min_indices_


def rearrange_list(lst):
    non_zeros = [x for x in lst if x != 0]
    zeros = [x for x in lst if x == 0]
    result = non_zeros + zeros
    return result


def get_positive_elements_at_even_positions(lst):
    result = [x for i, x in enumerate(lst) if i % 2 == 0 and x > 0]
    return result


vowels, consonants = count_vowels_consonants("Hello, World!")
print("Vowels:", vowels)
print("Consonants:", consonants)

sentence = "hello world."
capitalized_sentence = capitalize_sentence(sentence)
print(capitalized_sentence)

string = "Hello, World!"
frequency = letter_frequency(string)
for letter, count in frequency.items():
    print(f"{letter}: {count}")


string = "ror wqs qwq ew"
count = count_words_start_end_same_letter(string)
print("Words that starts and ends with same letter:", count)


random_list = [random.randint(1, 100) for _ in range(10)]
max_value, max_indices, min_value, min_indices = find_max_min_elements(random_list)
print("List:", random_list)
print("Max Value:", max_value, "Index:", max_indices)
print("Min Value:", min_value, "Index:", min_indices)

my_list = [4, 0, 2, 0, 1, 0, 3, 0, 5]
print("List:", my_list)
rearrange_list = rearrange_list(my_list)
print("Rearranged List:", rearrange_list)

positive_elements = get_positive_elements_at_even_positions([2, -1, 5, 3, -4, 6, 0, -2])
print("List:", my_list)
print("Positive Elements At Even Positions:", positive_elements)
