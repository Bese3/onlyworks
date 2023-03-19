def simple_delete(a_dictionary, key=""):
    keys = list(a_dictionary.keys())
    for i in keys:
        if i == key:
            del a_dictionary[key]

    return a_dictionary