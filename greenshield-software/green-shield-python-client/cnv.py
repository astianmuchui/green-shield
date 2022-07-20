from tkinter import *
from PIL import ImageTk, Image
root = Tk()

c = Canvas(root, width=500, height=500)
c.pack()

img = ImageTk.PhotoImage(Image.open(r"./16-162719_long-arrow-right-svg-png-icon-free-download.png"))
c.create_image(X,Y, image=img, anchor=NW)
root.mainloop()