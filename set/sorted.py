def print_sorted_dictionary(a_dictionary):
    key = sorted(list(a_dictionary.keys()))
    for i in key:
        print("{}: {}" .format(i , a_dictionary[i]))