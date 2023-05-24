class BaseGeometry:
    def __init__(self):
        pass
    def area(self):
        raise Exception("area() is not implemented")
    def integer_validator(self, name, value):
        if  not isinstance(value, int):
            raise TypeError(F"{name} must be an integer")
        if value <= 0:
            raise ValueError(F"{name} must be greater than 0")

