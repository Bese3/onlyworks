from tkinter import *
from PIL import ImageTk , Image


root  = Tk()
root.title("Image")
root.geometry("500x500")
# root.iconbitmap()

img = ImageTk.PhotoImage(Image.open("c.JPG"))
label = Label( image = img , padx= 5 , pady = 5)
label.grid(row = 0 , column = 0 , columnspan=3)

button_quit = Button(root , text = "Exit" , command = root.quit)
button_quit.grid(row = 1 , column = 1)

root.mainloop()