from sys import argv
def main():
    if len(argv) - 1 == 0:
        print("{:d}: arguments" .format(len(argv) - 1))
    elif len(argv) - 1 == 1:
        print("{:d} argument: " .format(len(argv) - 1))
        print("{:d} {}" .format((len(argv) - 1) , argv[1]) ) 
    else:
         print("{:d} arguments: " .format(len(argv) - 1))
         for i in range(len(argv) - 1):
              print("{:d}: {}" .format( i + 1 , argv[i + 1]))
              
                       




if __name__ == "__main__":
      main()