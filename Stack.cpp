#include<iostream>
#include<string>
#include<vector>


using namespace std;

int push_v(string a,string b){
    
}

int main()
{   std::vector<char> Stack;

    string push = "PUSH";
    string pop = "POP";
    string cmd;
    getline(cin,cmd);
    while (cmd!= "#"){   
        if (cmd == pop){
            if(Stack.size() !=0) 
            {int n = Stack.size();
            cout<<Stack[n-1]<<endl;
            Stack.pop_back();}
            else cout<<"NULL";
        }   
        else{
            
            Stack.push_back(cmd[5]);
            // cout<<cmd[5]<<endl;
        }
        getline(cin,cmd);

        // cout<<cmd<<"(\n";
    }
  
    return 0;
}

