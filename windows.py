from tkinter import *
from PIL import ImageTk , Image
from tkinter import messagebox
from tkinter import filedialog



root = Tk()

root.title("file access")
root.geometry("300x300")
def add():
    global response
    global img
    response = root.filename = filedialog.askopenfilename(initialdir="onlyworks\pics" ,\
      title = "Select a document" , filetypes=(("all files" , "*.*") , ("png files" , "*.png")))
    img = ImageTk.PhotoImage(Image.open(str(response)))
    label1 = Label(root , image=img).pack()


button = Button(root , text = "Click to add picture" , command = add).pack()



root.mainloop()
