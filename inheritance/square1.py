from rectangle1 import Rectangle
class Square(Rectangle):
    def __init__(self , size):
        self.integer_validator("size", size)
        self.__size = size
        #super().__init__(width  = size , height = size)
        
    def area(self):
        return self.__size**2
    def __str__(self):
        return F"[Square] {self.__size}/{self.__size}"

    
