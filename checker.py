# !/usr/bin/python3

delete_at = __import__('work9').delete_at

my_list = [1, 2, 3, 4, 5]
idx = 1
new_list = delete_at(my_list, idx)
print(new_list)
print(my_list)
