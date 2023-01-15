#include <iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<int,int>a, pair<int,int>b)
    {return (a.second<b.second);}

int main()
{   
    int n;// Số cuộc họp
    std::vector<pair<int,int>> S;
    pair <int,int> Hop[n];
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>Hop[i].first;
        cin>>Hop[i].second;
    }
    
    
    sort(Hop,Hop+n,comp);

    int Last = -1;
    for(int i = 0;i<=n;i++){
        if(Hop[i].first >= Last){
            S.push_back(Hop[i]);
            Last = Hop[i].first;
        }
    }

    for (int i = 0;i<n;i++){
        cout<<S[i].first<<":"<<S[i].second<<endl;
    }
    

    return 0;
}
