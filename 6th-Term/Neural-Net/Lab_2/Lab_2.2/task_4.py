def word_count(str_):
    return str_.count(" ") + 1


def replace_two_words(str_):
    words = str_.split()
    return " ".join(reversed(words))


def replace_1_with_one(str_):
    return str_.replace("1", "one")


def delete_between_2h(str_):
    first_h_index = str_.find("h")
    last_h_index = str_.rfind("h")
    return str_[:first_h_index] + str_[last_h_index + 1:]


print('Word Count:', word_count("One two three four"))
print('Replaced Words:', replace_two_words("first second"))
print('Replaced 1 With One:', replace_1_with_one("1 1 1 1 1"))
print('String Deleted Between 2h:', delete_between_2h("abcdefghijkhlmnopqhrstuvwxyz"))
