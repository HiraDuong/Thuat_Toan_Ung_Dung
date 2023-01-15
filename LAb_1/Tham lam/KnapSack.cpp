#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int mem[1000][1000];

int main()
{   
    freopen("input.txt", "r", stdin);
    memset(mem,-1,sizeof(mem));
    int n,b;
    int c[n],w[n];
    cin>>n>>b;
    for(int i = 1;i<=n;i++){
        cin>>c[i]>>w[i];
    }

    for (int i = 1;i<=n;i++){
        for(int s=0;s<=b;s++){
            if(i==1||s == 0) mem[i][s]= 0;
            if(s<w[i])mem[i][s] = mem[i-1][s];
            else mem[i][s] = max(c[i]+mem[i-1][s-w[i]],mem[i-1][s]);
        }
    }
   
    cout<<mem[n][b];

    return 0;
}
