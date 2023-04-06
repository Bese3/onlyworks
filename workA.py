# a = 89
# b = 10

# a , b = b , a  
# print("a={:d} - b={:d}".format(a, b))

from functools import reduce
def main():
    a = reduce(lambda x , y : x + y , range(0 , 101) )
    print(a)
    return a


if __name__ == "__main__":
    main()