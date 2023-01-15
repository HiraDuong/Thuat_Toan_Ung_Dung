#include<iostream>
using namespace std;
#include<vector>
/*
  ________________________________
                        |*******************************|
                        |*******************************|
                        |***       Vũ Huy Hoàng      ***|
                        |***         20204981        ***|
                        |***         IT_E6-05        ***|
                        |*******************************|
                        |*******************************|
*/

int rmq_min(std::vector<int> A,int x,int y){
    int min = A[x];
    for (int i = x;i<=y;i++){
        if( min > A[i]) min = A[i];
    }
    return min;
}

int main(){
    std::vector<int>A;

    int n,m ;
    int Q = 0;
    int x,y;
    cin>>n;
    
    for (int i = 0;i<n;i++){
        int c;
        cin>>c;
        A.push_back(c);
    }

    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>x;
        cin>>y;
        Q+=rmq_min(A,x,y);
        
    }

    cout<<Q<<endl;

return 0;
}