def inherits_from(obj, a_class):
    a = False
    for i in a_class.__mro__:
        if i.__name__ == obj.__class__.__name__:
            a = True
            #print ("in the")
    i = isinstance(obj, a_class) and issubclass(obj.__class__, a_class)
    return ( (not a) and i)
