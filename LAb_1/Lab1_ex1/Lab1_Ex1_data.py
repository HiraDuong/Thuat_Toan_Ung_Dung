

class Data_log:
    def __init__(self) :
        self.Data = []

    def get_data(self):
        while True:
            data_input = input()

            if data_input == '#':
                break
            else:
                self.Data.append(data_input.split(" "))
        
