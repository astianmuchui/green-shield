from serial import Serial


class Connect():
	"""create connection to arduino R3 board"""
	def __init__(self, port, board, baud):
		super(Connect, self).__init__()
		self.port = port
		self.board = board
		self.baud = baud
		self.init_connection(self.port, self.board, self.baud)

	def init_connection(self, port, board, baud):
		"""
		Params: port -> port to create serial connection
				board -> Arduino board being used with the shield
				baud -> communication speed for the board
		Return: true if connected to specified port, false is failed connection
		"""
		self.ser = Serial(port, baud)
		
		if self.ser:
			flag = "Connection OK..."
		else:
			flag = "Connection failed..."
		 
		return flag


