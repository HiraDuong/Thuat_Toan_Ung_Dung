#include<iostream>
#include<Graph.cpp>
#include<vector>
using namespace std;


void Graph::topo_sort(){
    memset(visited,false,sizeof(visited));
    stack<int> Stack;
    for (int s = 0;s<V;s++){
        if(visited[s] = false) DFS_topo(s,Stack);
        // in ket qua topo
        while (!Stack.empty())
        {
            cout<<Stack.top()<<" ";
            Stack.pop();
        }
        
    }

}

void Graph::DFS_topo(int s,stack<int>&Stack){
        visited[s] = true;
        list<int>::iterator i;

    for (i = adj[s].begin();i!= adj[s].end();++i){
        int v = *i;
        if (!visited[v]) {
            //cout<<v<<" ";
            
            DFS(v);
            
            }
    }
    
}

void Graph::topo_sort_xoadandinh(){
    
    
    std::vector<int> in_degree(V,0);
    for(int v = 0;v<V;v++){
        list <int>::iterator i;
        for(i = adj[v].begin();i!=adj[v].end();i++){
            in_degree[*i] ++;

        }
    }
    queue<int> Q;
    for(int v = 0;v<V;v++){
        if(in_degree[v] ==0) Q.push(v);
    }
    int num = 0;vector<int> topo_order;
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        num++;
        topo_order.push_back(v);
         list <int>::iterator i;
        for(i = adj[v].begin();i!=adj[v].end();i++){
            int u = *i;
            in_degree[u]--;
            if (in_degree[u] == 0) Q.push(u);
        }
    }
    
    for(int i = 0;i<topo_order.size();i++){
        cout<<topo_order[i]<<" ";
    }
}

int main()
{
    Graph g(5);

    g.addEgde(1,2);
    g.addEgde(1,3);
    g.addEgde(2,4);
    g.addEgde(4,0);
    g.addEgde(3,0);
    g.addEgde(0,2);

    int numV = g.numVertex();
    memset(visited,false,sizeof(visited));
    g.topo_sort_xoadandinh();


    return 0;
}
