def divisible_by_2(my_list=[]):
    new_list = []
    for i in my_list:
        new_list.append(True) if i % 2 == 0 else new_list.append(False)
    return new_list
