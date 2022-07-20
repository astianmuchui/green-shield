import serial

class Connect():
	"""create connection to arduino R3 board"""
	def __init__(self, port, ):
		super(Connect, self).__init__()
		self.port = port
		self.board = board
		self.init_connection(port, board)

	def init_connection(self, self.port, self.board):
		"""
		Params: none
		Return: true if connected to specified port, false is failed connection
		"""
		self.ser = Serial(self.port, 9600)
		if self.ser:
			flag = "Connection OK..."
		else:
			flag = "Connection failed..."
		 
		return flag


