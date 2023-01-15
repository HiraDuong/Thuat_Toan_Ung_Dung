
#include<iostream>
using namespace std;



int main()
{   int Q = 0;
    int I,C,T,H,U,S,K;
    int ICT,K62,HUST,N;
    int Arr[9] = {1,2,3,4,5,6,7,8,9};
    cin>>N;
    N+=62;
    //H*1000+(I-K+U)*100+(S+C)*10+2T = N
    if (N > 10898 || N%2==1) cout<<0;
    else{
        // case 1: N>10000 => H = max 9,
        if (N>=10000){
            H = 9;
            // pt <=> (I-K+U)*100+(S+C)*10+2T= N-H*1000
            //I-K+U >=10=> I+U>=10+K>=11=> I and U start is from 5
            // case 1.1 T =1,2,3,4
                T = (N%10)/2;
                // case 1.1.1 (S+C) =(( N-H*1000-2T)/10)%10
                    int SC = (( N-H*1000-2*T)/10)%10;
                    int IKU = ( N-H*1000-2*T)/10 - SC;
                    for (int j = 5;j<=8;j++){
                        I = j;
                         
                    }
            // case 1.2 T = 5,6,7,8,9


        }
    }

    return 0;
}
