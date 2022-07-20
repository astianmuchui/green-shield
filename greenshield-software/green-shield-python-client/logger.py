import os

class Log:
    def __init__(self, file_name, data):
        self.file_name = file_name

        with open("./log/"+self.file_name, 'a') as log_file:
            log_file.write(data)

        log_file.close()
        
