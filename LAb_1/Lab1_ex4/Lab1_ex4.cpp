#include<iostream>
using namespace std;
#include <vector>
#include <bits/stdc++.h>
#include<stack>
std::vector<vector<int>> cac_max_rect(std::vector<vector<int>> Mat,int r,int c){
    std::vector<int> list ;
    for (int i = 0;i<c;i++){
        list.push_back(0);
    }
    Mat.insert(Mat.begin(),list);
    //std::vector<vector<int>> H = Mat;
    for (int i = 0;i<r+1;i++){
        for (int j = 0;j<c;j++)
            {if(Mat[i][j] == 0){
                for(int k = i+1;k<r+1;k++){
                    if (Mat[k][j] != 0){
                        Mat[k][j] = k - i;
                    }
                } 
                }
        }
    }
    Mat.erase(Mat.begin());
    return Mat;
}




int solve(std::vector<vector<int>> Mat,int r,int c){
    int Max_area = 0;   
    vector<int> heights(c);
    for (int i =0;i<r;i++){
        stack<int> stk;
        for (int j = 0;j<heights.size();j++){
            if(j<c){
                heights[j] = (Mat[i][j] ==1)?heights[j]+1:0;

            }
            while(!stk.empty()&& heights[j]<heights[stk.top()]){
                int cur = stk.top();
                stk.pop();
                Max_area = max(Max_area,heights[cur] * (stk.empty()?j:(j-1-stk.top())));


            }
            stk.push(j);
        }
    }
    return Max_area;
}

int main(){
    int r,c;
    std::vector<vector<int>> Mat;
    std::vector<int> list;
    cin>>r>>c;
    for (int i = 0;i<r;i++){
        for (int j = 0;j<c;j++){
            int q;
            cin>>q;
            list.push_back(q);
        }
        Mat.push_back(list);
        list.clear();

    } 
//Mat = cac_max_rect(Mat,r,c);


/*for (int i = 0;i<r+1;i++){
        for (int j = 0;j<c;j++){
            cout<<Mat[i][j]<<" ";
        }
        cout<<endl;
    } 
*/
//cout<<"F";
int ans = solve(Mat,r,c);
cout<<solve(Mat,r,c);

    return 0;
}
