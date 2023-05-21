//vu huy hoang 20204981

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector<string> input1;
vector<string> input2;
vector<string> input3;
vector<vector<string>> data;
// input 1 là ngày tháng, 2 là thông tin, 3 là truy vấn
//vector<string> tripcode, customercode,date,time;
vector<int> qty;

//split

std::vector<string> split(string a){
    std:: vector<string> split_vector;
    string b = "";
    for(int i = 0;i<a.size();i++){
        if ( a[i]!=' '){
            b+= a[i];
        }
        else{
             (split_vector.push_back(b));
             b = "";
             }

    }
        split_vector.push_back(b);
    return split_vector;
}

void truyvan(){
    //split input 2
vector<string> split_vec;
    for(int i = 0;i<input2.size();i++){
        split_vec = split(input2[i]);
        data.push_back(split_vec);
    }

    for(int i = 0;i<input3.size();i++){
        // total_qty
        if (input3[i] == "TOTAL_QTY"){
            int qty_sum =0;
            
            for(int j = 0;j<data.size();j++){
                qty_sum+= stoi(data[j][4]);
            }
            cout<<qty_sum<<endl;
        }
        //qtycus
        if (input3[i].find("QTY_CUSTOMER") == 0){
            string qty_cus = input3[i] ;
            int qty_cus_total = 0;
            qty_cus.erase(0,13);
            //cout<<qty_cus;
            for(int i = 0;i<data.size();i++){
                if(data[i][1] == qty_cus){
                    qty_cus_total+= stoi(data[i][4]);
                }
            }
            cout<<qty_cus_total<<endl;
        }
        //qty max per
        if (input3[i].find ("QTY_MAX_PERIOD")==0){
            
        }
        //TOTAL TRIP
        if (input3[i] == "TOTAL_TRIPS"){
            vector<string> total_trips;
            for(int i = 0;i<data.size();i++){
                if(find(total_trips.begin(),total_trips.end(),data[i][0]) == total_trips.end()){
                    total_trips.push_back(data[i][0]);
                }
            }
            cout<<total_trips.size()<<endl;
        }
        //TRAVEL TIME TRIP
        if (input3[i].find("TRAVEL_TIME_TRIP")){

        }
        // MAX CONFLICT_TRIP
        if (input3[i] == "MAX_CONFLICT_TRIP"){
            cout<<1;
        }



    }
}

// Input
void getInput1(){
    string Input1;
    
    
    // get input 1 : Chuỗi các ngày liên tiếp 
    do {
        getline(cin,Input1);
        if(Input1 == "*") break;
        input1.push_back(Input1);
    }
    while(Input1!="*");
    // get input 2 : Thông tin về các chuyến giao hàng
}
void getInput2(){
        string Input2;

        do {
        string Input2;
        getline(cin,Input2);
        if(Input2 == "***") break;
        input2.push_back(Input2);
    }
    while(Input2!="***");
}
    // get input 3 : Thong tin cac cau truy van
void getInput3(){
        string Input3;
    
    do {
        string Input3;
        getline(cin,Input3);
        if(Input3 == "***") break;
        if(Input3!="***" ){
            //cout<<Input3;
            input3.push_back(Input3);
            }
        
    }
    while(Input3!="***");

}


int main()
{
    getInput1();
    getInput2();
    getInput3();
    truyvan();
   
  


    return 0;
}
