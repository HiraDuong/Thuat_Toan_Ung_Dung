#include <iostream>
#include<cstring>
#include<stack>
#include<string>
using namespace std;
  
  
string a = "bananinn";
string b= "kaninan";
int mem[1000][1000];


int lcs(int i ,int j){
    int res = 0;
    if(i == -1 ||  j == -1) 
        return 0;
    if (mem[i][j]!= -1) 
        return mem[i][j];
    if (a[i] == b[j]) res = max(res,lcs(i-1,j-1)+1); 
    else {
        res = max (res,lcs(i,j-1));
        res  = max (res,lcs(i-1,j));
    }
    mem[i][j] = res;
    return res;
} 


int main()
{   memset(mem,-1,sizeof(mem));
    
    int m = a.length();int n = b.length();
    //cout<<m<<" "<<n<<endl;
    int  k = lcs(m-1,n-1);
    cout<<k<<endl;
    stack<int> s;
    for (int i = m-1, j=n-1,dem = 1;dem<=k;++dem){
        if (a[i] == b[j] && mem[i][j] == 1+mem[i-1][j-1]){
            s.push(a[i]);
            --i;
            --j;
            continue;
        }

        if (mem[i][j] == mem[i-1][j]){
            --i;
            continue;
        }
        if (mem[i][j] == mem [i][j-1]){
            --j;
            continue;
        }
    }

    while(!s.empty()){
        printf("%c",s.top());
        s.pop();
    }
    return 0;
}
