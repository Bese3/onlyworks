def max_integer(my_list=[]):
    if my_list is None or my_list == "":
        return None
    my_max = my_list[0]   #starting with zero to check the list
    for i in range(len(my_list)):
        if my_max < my_list[i]:
            my_max = my_list[i]
    return my_max
