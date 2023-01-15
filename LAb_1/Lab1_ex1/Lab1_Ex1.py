from datetime import datetime,timedelta


Data = []
Query = []

def get_data():
        while True:
            data_input = input()

            if data_input == '#':
                break
            else:
                Data.append(data_input.split(" "))

def get_query_command():
        while True:
            query_input = input()

            if query_input == '#':
                break
            else:
                Query.append(query_input.split(" ")) 
         
def get_time(date_str,time_str):
        time = time_str.split(":")
        date = date_str.split("-")
        return datetime(int(date[0]),int(date[1]),int(date[2]),int(time[0]),int(time[1]),int(time[2]))




def check_phone_number(Data):
       for i in range (len(Data)):
        if len(Data[i][1]) != 10 or len(Data[i][2]) != 10:
            print("")
            break
        elif Data[i][1].isdigit() == False or Data[i][2].isdigit() == False:
            print("")
            break
        else :
            print("1")
            break  

        

def number_calls_from(Data,number):
        count = 0
        for i in range (len(Data)) :
            if Data[i][1]== number :
                count+=1
        print( str(count))

def number_total_calls(Data):
        print(str(len(Data)))

def count_time_calls_from(Data,number):
        total_time =0
        for i in range(len(Data)):
            if Data[i][1] == number:
             
                start_time = get_time(Data[i][3] ,Data[i][4]) 
                end_time = get_time(Data[i][3] ,Data[i][5])               

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
        print(int(total_time))

def main ():
        
        get_data()
        get_query_command()
        def search_query_command():
        
            for i in range (len(Query)):
                if Query[i][0] == "?check_phone_number" :
                    check_phone_number(Data)
                    
                   
                    
                elif Query[i][0] == "?number_total_calls":
                    number_total_calls(Data)
                    
                    
                elif Query[i][0] == "?number_calls_from":
                    number_calls_from(Data,Query[i][1])
                    
                    
                    
                elif Query[i][0] == "?count_time_calls_from":
                    
                    count_time_calls_from(Data,Query[i][1])
                    
                    
                else:
                    print(1000)
        #print("")
        search_query_command()

main()