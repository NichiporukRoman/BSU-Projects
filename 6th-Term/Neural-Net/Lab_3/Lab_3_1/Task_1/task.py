def add_element_to_list_in_tuple(tuple_, element):
    element2 = list(tuple_[1])
    element2.append(element)
    return tuple_[0], element2


def add_list_to_tuple(tuple_, list_):
    return tuple_[0], tuple_[1], list_


def add_string_to_tuple(tuple_, string):
    return tuple_[0], tuple_[1], string


def copy_add_element_to_list_in_tuple(tuple_):
    element = list(tuple_[1])
    element1 = list(element)
    for x in element:
        element1.append(x)
    return tuple_[0], element1


tuple1 = (1, [2, 3])
print(add_element_to_list_in_tuple(tuple1, 4))
print(add_list_to_tuple(tuple1, [1, 2, 3]))
print(add_string_to_tuple(tuple1, 'str'))
print(copy_add_element_to_list_in_tuple(tuple1))


