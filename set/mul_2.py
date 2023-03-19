def multiply_by_2(a_dictionary):
    new_dict = {}
    # keys = set(list(a_dictionary.keys()))
    # for i in keys:
    #     new_dict[i] = 2 * a_dictionary[i]
    # return new_dict
    updated = list(map(lambda x: 2 * x , a_dictionary.values()))
    for i , j in zip(a_dictionary.keys() , updated):
        new_dict[i] = j
    return new_dict