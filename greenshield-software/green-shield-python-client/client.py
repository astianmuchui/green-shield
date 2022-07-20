from tkinter import *
from core import Connect
from logger import Log

from tkinter import font
class App:
	"""GUI class for App"""
	def __init__(self, parent):
		super(App, self).__init__()
		self.parent = parent
		

		# labels config dict
		self.lbl_config = {
			"relief": RIDGE,
			"font":   ("Verdana", 12)
		}

		# entry config dict
		self.entry_config = {
			"length": 15,
			"ipady": 10
		}

		self.create_widgets()
		self.create_connection()

		Log("log.txt", "test point 1")

	def create_widgets(self):
		"""Create GUI widgets"""
		self.cmd_lbl = Label(self.parent, text="Command: ",font=("bold",12))
		self.cmd_lbl.grid(row=1, column=1)
		self.cmd_lbl.place(x=40,y=50)
		self.cmd_lbl.configure(background="gray50")
		#todo
		# create entry for command
		self.cmd_entr = Entry(self.parent)
		self.cmd_entr.grid(row=1, column=2)
		self.cmd_entr.place(x=150,y=50,width=180,height=35)
		#create button to send command

		self.cmd_send_btn = Button(self.parent,text="Send",background="gray60",foreground="black",width=5,height=1,font=("bold",12),relief=RIDGE)
		self.cmd_send_btn.place(x=350,y=50)

		# create response label
		self.cmd_res = Label(self.parent,text="Response:",font=("bold",12))
		self.cmd_res.place(x=40,y=100)
		self.cmd_res.configure(background="gray50")

		#create response entr
		self.cmd_res_entr = Entry(self.parent)
		self.cmd_res_entr.place(x=150,y=100,height=35,width=180)

		# make it not resizable

	def create_connection(self):
		"""Establish connection with the hardware"""
		# Connect.init_connection() # todo: provide user with a way to select the port, board and baud rate
		pass

		
if __name__ == '__main__':
	root = Tk()
	#Dimensions
	root.geometry("500x200")

	#Remove resizability
	root.resizable(False,False)

	#Window background

	root.configure(background="gray50")


	root.title("Green-shield Client")
	# add resizable false option here	
	app = App(root)
	root.mainloop()
