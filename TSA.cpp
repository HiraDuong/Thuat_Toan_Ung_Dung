// Name: Bài 1: Top signal analysis

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i = 0;i<n;i++){
        cin>>A[i];
    }

    int Q=0;
    for (int i = 1;i<n;i++){
        if (A[i]>A[i-1]&& A[i+1]){
            Q++;
            i++;
        }
    }

    cout<<Q;
    return 0;
}

