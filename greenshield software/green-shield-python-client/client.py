from tkinter import *

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

	def create_widgets(self):
		"""Create GUI widgets"""
		self.cmd_lbl = Label(self.parent, text="Command: ")
		self.cmd_lbl.grid(row=1, column=1)

		#todo
		# create entry for command
		self.cmd_entr = Entry(self.parent)
		self.cmd_entr.grid(row=1, column=2)

		# create response label
		# create a button called connect
		# make it not resizable
		#



	def widget_pack(self):
		"""Pack widgets"""
		pass
		

if __name__ == '__main__':
	root = Tk()
	root.geometry("500x200")
	root.title("Green-shield Client")
	# add resizable false option here	
	app = App(root)
	root.mainloop()
