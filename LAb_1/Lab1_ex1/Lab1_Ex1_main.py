from Lab1_Ex1_query import * 
from Lab1_Ex1_data import *

INFINITY = 10000

"""
                         ________________________________
                        |*******************************|
                        |*******************************|
                        |***       Vũ Huy Hoàng      ***|
                        |***         20204981        ***|
                        |***         IT_E6-05        ***|
                        |*******************************|
                        |*******************************|
                       
"""

class Main:
    
    def __init__(self) :
      
        self.query_command = Check_data()
        self.data_command = Data_log() 

    



    def main (self):
        query_command=self.query_command
        data_command=self.data_command
        Data = data_command.Data
        Query = query_command.Query

        data_command.get_data()
        query_command.get_query_command()
        
        def search_query_command():
        
            for i in range (len(Query)):
                if Query[i][0] == "?check_phone_number" :
                    query_command.check_phone_number(Data)
                    
                   
                    
                elif Query[i][0] == "?number_total_calls":
                    query_command.number_total_calls(Data)
                    
                    
                elif Query[i][0] == "?number_calls_from":
                    query_command.number_calls_from(Data,Query[i][1])
                    
                    
                    
                elif Query[i][0] == "?count_time_calls_from":
                    
                    query_command.count_time_calls_from(Data,Query[i][1])
                    
                    
                else:
                    print(INFINITY)
        print("")
        search_query_command()
        
        

        '''for i in range (len(Data)):
            print(Data[i])'''

        #print(Query)
       



sys = Main()
sys.main()

