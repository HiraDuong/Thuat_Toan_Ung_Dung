

from datetime import datetime,timedelta
from Lab1_Ex1_data import *
#self.Data = []

class Check_data:
    def __init__(self) :
        
       
        self.Query = []
        
        #self.data_command.get_data()
        #self.get_query_command()


    def get_query_command(self):
        while True:
            query_input = input()

            if query_input == '#':
                break
            else:
                self.Query.append(query_input.split(" ")) 
         
    def get_time(self,date_str,time_str):
        time = time_str.split(":")
        date = date_str.split("-")
        return datetime(int(date[0]),int(date[1]),int(date[2]),int(time[0]),int(time[1]),int(time[2]))




    def check_phone_number(self,Data):
       for i in range (len(Data)):
        if len(Data[i][1]) != 10 or len(Data[i][2]) != 10:
            print("-10000")
            break
        elif Data[i][1].isdigit() == False or Data[i][2].isdigit() == False:
            print("-20000")
            break
        else :
            print("1")
            break  

        

    def number_calls_from(self,Data,number):
        count = 0
        for i in range (len(Data)) :
            if Data[i][1]== number :
                count+=1
        print( str(count))

    def number_total_calls(self,Data):
        print(str(len(Data)))

    def count_time_calls_from(self,Data,number):
        total_time =0
        for i in range(len(Data)):
            if Data[i][1] == number:
             
                start_time = self.get_time(Data[i][3] ,Data[i][4]) 
                end_time = self.get_time(Data[i][3] ,Data[i][5])               

                a = timedelta(
                    hours=start_time.hour,
                    minutes=start_time.minute,
                    seconds=start_time.second

                )
                tmp = end_time - a
                b = timedelta(
                    hours=tmp.hour,
                    minutes=tmp.minute,
                    seconds=tmp.second
                )
                total_time += b.total_seconds()
                #print(str(start_time) + " " + str(end_time)+"\n")
        print(total_time)
            
        #print("\n"+str(total_time))

