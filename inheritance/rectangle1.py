from base_geometry2 import BaseGeometry

class Rectangle(BaseGeometry):
    def __init__(self, width, height):
        self.__width = width
        self.__height = height
        self.integer_validator("width", width)
        self.integer_validator("height" , height)
    def area(self):
        return self.__width * self.__height
    def __str__(self):
        return F"[Rectangle] {self.__width}/{self.__height}"