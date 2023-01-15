#include<iostream>
#include<string>
using namespace std;

// USING GREEDY


int main()
{   int coins[5] = {100,25,10,5,1};
    int X;
    string Trade = "";
    cin>>X;
    for (int i = 0;i<5;i++){
        if (X/coins[i] >=1){
            Trade +=to_string(int(X/coins[i]));
            X -= coins[i]*int(X/coins[i]);
        }
        else {
            Trade +="0";
        }
    }
    cout<<Trade<<endl;

    return 0;
}




    
