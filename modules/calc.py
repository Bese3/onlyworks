from calculator_1 import add , sub , mul , div 

def main():
     a , b = 10 , 5
     print("{:d} + {:d} = {:d}" .format(a , b , add(a , b)))
     print("{:d} - {:d} = {:d}" .format(a , b , sub(a , b))) 
     print("{:d} * {:d} = {:d}" .format(a , b , mul(a , b)))
     print("{:d} / {:d} = {:d}" .format(a , b , div(a , b)))
     return
if __name__ == "__main__":
   main() 


