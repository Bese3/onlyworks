from functools import reduce
def uniq_add(my_list=[]):
    uniq = []
    summation  = 0
    for i in my_list:
        if i not in uniq:
            uniq.append(i)
            summation += i
    return summation