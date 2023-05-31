from tkinter import *
from PIL import ImageTk , Image
root  = Tk()
root.title("Image")
root.geometry("490x550")


img = ImageTk.PhotoImage(Image.open("K:\\alx\\ALX\\B\\onlyworks\\screen.jpg"))
img1 = ImageTk.PhotoImage(Image.open("K:\\alx\\ALX\\B\\onlyworks\\pics\\spider.png"))
img2= ImageTk.PhotoImage(Image.open("K:\\alx\\ALX\\B\\onlyworks\\pics\\clipart.png"))

list = [img , img1 , img2]

status = Label(root , text =F" Image 1 of {str(len(list))}" , bd = 1 , relief= SUNKEN)

label = Label(image = img)
label.grid(row = 0 , column = 1 , ipadx=1 , ipady=1)

def forward(number):
    global label
    global button_forward
    global button_back
   
    label.grid_forget()
    label = Label(image = list[number - 1])
    button_forward = Button(root , text = ">>" , command = lambda : forward(number + 1))
    button_back = Button(root , text = "<<" , command = lambda : back(number - 1))
    status = Label(root , text =F" Image {number} of {str(len(list))}" , bd = 1 , relief= SUNKEN)
    if number == len(list):
        button_forward = Button(root , text = ">>" , state = DISABLED)
       
    label.grid(row = 0 , column = 1)
    button_back.grid(row = 4, column = 0 , padx = 2 , pady = 2)
    button_forward.grid(row =  4 , column = 2 , padx = 2 , pady = 2)
    status.grid(row = 5 , column = 2 , sticky = E)
  


def back(number):
    global label
    global button_forward
    global button_back
    
    label.grid_forget()
    label = Label(image = list[number - 1])
    button_forward = Button(root , text = ">>" , command = lambda : forward(number + 1))
    button_back = Button(root , text = "<<" , command = lambda : back(number - 1))
    status = Label(root , text =F" Image {number} of {str(len(list))}" , bd = 1 , relief= SUNKEN)
    if  number == 1:
        button_back = Button(root , text = "<<" , state = DISABLED)
  
    
    button_back.grid(row = 4 , column = 0 , padx = 2 , pady = 2)
    button_forward.grid(row =  4 , column = 2 , padx = 2 , pady = 2)
    label.grid(row = 0 , column = 1)
    status.grid(row = 5 , column = 2 , sticky = E)


 




    

# buttons 
button_back = Button(root , text = "<<" , command = lambda : back(1))
button_forward = Button(root , text = ">>" , command  = lambda : forward(2))
button_quit = Button(root , text = "Exit" , command = root.quit)


button_quit.grid(row = 4 , column = 1 ,padx = 2 , pady = 2)
button_back.grid(row = 4 , column = 0 , padx = 2 , pady = 2)
button_forward.grid(row =  4 , column = 2 , padx = 2 , pady = 2)
status.grid(row = 5 , column = 2 , sticky = E)





# root.iconbitmap()







root.mainloop()