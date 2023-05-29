from tkinter import *


root = Tk()
root.title("Calculator")
# root.geometry("50x50")
entry = Entry(root ,width = 35 , borderwidth = 5)
entry.grid(row = 0  ,column = 0 , columnspan = 15 , padx = 10 , pady = 10)
# entry.insert(0 , "Enter your name")

bg = PhotoImage(file = "K:\\alx\\ALX\\B\\onlyworks\\pics\\spider.png")
  
# Show image using label
label1 = Label( root, image = bg)
label1.place(x = 0, y = 50)

def click(num):
    # entry.delete(0 , END)
    current = entry.get()
    entry.delete(0 , END)
    entry.insert(0 , str(current) + str(num))
def clear():
    entry.delete(0 , END)
def add():
    first = entry.get()
    global f
    f = int(first)
    global calc
    calc = "addition"
    entry.delete(0 , END)

def sub():
    first = entry.get()
    global f
    f = int(first)
    global calc
    calc = "substraction"
    entry.delete(0 , END)

def mul():
    first = entry.get()
    global f
    f = int(first)
    global calc
    calc = "multiplication"
    entry.delete(0 , END)

def div():
    first = entry.get()
    global f
    f = int(first) 
    global calc
    calc = "division"
    entry.delete(0 , END) 

def equals():
    # if entry.get() is None:
    #     return
    
    second = entry.get()    
    entry.delete(0 , END)

    if calc == "addition":
        entry.insert(0 , f + int(second))
    if calc == "substraction":
       
        entry.insert(0 , (f - int(second)))
    if calc == "multiplication":
        entry.insert(0 , (f * int(second)))
    if calc == "division":
        if int(second) == 0:
            entry.insert(0 , "Math ERROR")
            return
        else:
            entry.insert(0 , (f / int(second)))
           


# creating a button
button_0 = Button(root , text = "0" , padx = 20 , pady = 20 , command = lambda : click(0))
button_1 = Button(root , text = "1" , padx = 20 , pady = 20 , command = lambda : click(1))
button_2 = Button(root , text = "2" , padx = 20 , pady = 20 , command = lambda : click(2))
button_3 = Button(root , text = "3" , padx = 20 , pady = 20 , command = lambda : click(3))
button_4 = Button(root , text = "4" , padx = 20 , pady = 20 , command = lambda : click(4))
button_5 = Button(root , text = "5" , padx = 20 , pady = 20 , command = lambda : click(5))
button_6 = Button(root , text = "6" , padx = 20 , pady = 20 , command = lambda : click(6))
button_7 = Button(root , text = "7" , padx = 20 , pady = 20 , command = lambda : click(7))
button_8 = Button(root , text = "8" , padx = 20 , pady = 20 , command = lambda : click(8))
button_9 = Button(root , text = "9" , padx = 20 , pady = 20 , command = lambda : click(9))
button_add = Button(root , text = "+" , padx = 20 , pady = 20 , command = add)
button_result = Button(root , text = "=" , padx = 20 , pady = 149 , command = equals)
button_clear = Button(root , text = "clear" , padx = 10 , pady = 20 , command = lambda : clear())
button_sub = Button(root , text = "-" , padx = 20 , pady = 20 , command = sub)
button_mul = Button(root , text = "*" , padx = 20 , pady = 20 , command = mul)
button_div = Button(root , text = "/" , padx = 20 , pady = 20 , command = div)


# putting the  buttons to screen

button_0.grid(row = 4 , column = 1)
button_add.grid(row = 4 , column = 0)
button_result.grid(row = 1 , column  = 3 , rowspan = 10)
button_clear.grid(row = 4 , column = 2) 
button_sub.grid(row = 5  , column = 0)
button_mul.grid(row = 5 , column = 1)
button_div.grid(row = 5 , column  = 2)

button_1.grid(row = 3 , column = 0)
button_2.grid(row = 3 , column = 1)
button_3.grid(row = 3 , column = 2)

button_4.grid(row = 2 , column = 0)
button_5.grid(row = 2 , column = 1)
button_6.grid(row = 2 , column = 2)

button_7.grid(row = 1 , column = 0)
button_8.grid(row = 1 , column = 1)
button_9.grid(row = 1 , column = 2)

# mybutton = Button(root , text = "Enter!" , command = myclick , fg ="green" , bg = "black")
root.mainloop()                