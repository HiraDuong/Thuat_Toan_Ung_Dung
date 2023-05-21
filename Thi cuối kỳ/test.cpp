#include<iostream>
#include<vector>

using namespace std;

int sovle(int m,int n){
    vector<int>B;
    vector<vector<int>> Mat;
    vector<vector<int>> linh;
    for(int i = 0;i<m;i++){
        B.clear();
        for(int j = 0;j<n;j++){
            int a;
            cin>>a;
            B.push_back(a);

            // if (Mat[i][j] == 1){
            //     linh.push_back({i,j});
            // }
        }
        Mat.push_back(B);
    }


    //cout<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if (Mat[i][j] == 1){
                linh.push_back({i,j});
            }
            //cout<<Mat[i][j]<<" ";
        }
        //cout<<endl;
    }
    // for(int i = 0;i<linh.size();i++){
    //     cout<<linh[i][0]<<" "<<linh[i][1]<<endl;
    // }

    for(int i = 0;i<linh.size();i++){
        int x = linh[i][0];
        int y = linh[i][1];
        for(int j = 0;j<m;j++){
            Mat[j][y] = 1;
        }

        for (int k = 0; k <n; k++)
        {
            Mat[x][k] = 1;
        }
        
    }



    int vang = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(Mat[i][j] == 0) vang++;
        }
    }

    return vang;
    //cout<<"done";

}

int main()
{
int T ;
int m,n;
cin>>T;
for(int i = 0;i<T;i++){
    cin>>m>>n;
    //sovle(m,n);
    int result = sovle(m,n);
    cout<<"#"<<i+1<<" "<<result<<endl;
}
    return 0;
}
