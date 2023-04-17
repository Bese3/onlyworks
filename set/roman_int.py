# Roman to integer converter 
"""
>>> roman_to_int('L')
50
>>> roman_to_int('LCI')
5

"""
import doctest
def roman_to_int(roman_string):
    if roman_string != str(roman_string) or roman_string is None or \
               roman_string == "":
        return None
    R_string  = {'I': 1 , 'V': 5 , 'X': 10 , 'L': 50 , 'C': 100 , 'D': 500 , 'M': 1000}
    sum = 0
    i =  0
    while i < len(roman_string):
        if i + 1  < len(roman_string) and R_string[roman_string[i]] < R_string[roman_string[i + 1]]:
            sum += (R_string[roman_string[i + 1]] - R_string[roman_string[i]])
            i = i + 2
            continue
        sum += R_string[roman_string[i]]
        i = i + 1
    return sum
if __name__ == "__main__":
    doctest.testmod()
        
