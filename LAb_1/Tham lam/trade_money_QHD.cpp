#include<iostream>
#include<cstring>
#include<algorithm>
using namespace  std;



int mem[10][1000];
int d[10];
int otp(int i,int x){
    if (i==1) return 999999;
    if (x == 0) return 0;
    if (x<0) return 9999999;
    if (mem[i][x] !=1) return mem[i][x];
    int ans = 999999;
    ans = min(ans,1+otp(i,x-d[i]));
    ans = min(ans,otp(i-1,x));
}

void trade(int i, int X){
    if ( i == -1 ) return;
    if (X<=0) return ;
    if (mem[i][X] == 1 + otp(i,X-d[i])){
        cout<<d[i]<<" ";
        trade(i,X-d[i]);
    }
    else{
        trade(i-1,X);
    }
}

int main()
{
    memset(mem,-1,sizeof(mem));
    /* code */
    return 0;
}
