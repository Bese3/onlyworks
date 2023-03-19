from math import sin , cos , tan , pi
def map_functions(x ,  functions):
    res = []
    for func in functions:
        res.append(func(x))

    return res
family = (sin , cos , tan)
print(map_functions(pi , family)) 