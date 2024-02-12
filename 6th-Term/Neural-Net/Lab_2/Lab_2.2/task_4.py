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


print(word_count("One two three four"))
print(replace_two_words("first second"))
print(replace_1_with_one("1 1 1 1 1"))
print(delete_between_2h("abcdefghijkhlmnopqhrstuvwxyz"))
