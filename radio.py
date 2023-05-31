from tkinter import *
from PIL import ImageTk , Image
from tkinter import messagebox   #showinfo  showwarning showerror askquestion askcancel askyesno



root = Tk()
root.title("Radio Button")
root.geometry("400x400")
def popup():
    response = messagebox.askyesno("Danger Zone!!!", "are you sure?")
    my_label = Label(root , text = response).pack()
    # if response == 1:
    #     messagebox.showinfo("Info" , "You clicked Yes")
    #     my_label = Label(root , text = "Yes is being executed").pack()
    #     return
    # messagebox.showinfo("Info" , "You clicked NO")
    # my_label = Label(root , text = "No is being executed").pack() 


modes = [
   ("peperoni" , "peperoni"),
   ("cheese" , "cheese"),
   ("onion" , "onion")
   ]




button1 = Button(root , text = "popup" , command = popup).pack()
pizza = StringVar()
pizza.set("onion")
def click(value):
    label = Label(root , text = pizza.get())
    label.pack()

for text , mode in modes:
    Radiobutton(root , text = text , variable = pizza , value = mode).pack()
button = Button(root , text ="click" , command = lambda : click(pizza.get())).pack()




label = Label(root , text = pizza.get())
label.pack()



root.mainloop()