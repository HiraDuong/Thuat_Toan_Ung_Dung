#include<iostream>
#include "graph.h"
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;

// create object graph 
graph::graph(int V){
    this->V = V;
    adj = new list <int>[V];
}

// return graph vertex number
int graph::numVertex(){
    return V;
}

// add egde for directed graph
void graph::addEgde(int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u)
}

// add egde for undirected graph
void graph::addEgde_o(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// BFS search
void graph:: BFS(int s){
    int n  = sizeof(adj);
    memset(visited,false,sizeof(visited));
    queue<int> Q;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        cout<<u<<" ";
        list<int> ::iterator i;
        for (i = adj[u].begin();i!=adj[u].end();i++){
            int v = *i;
            if (visited[v] ==false){
                visited[v] = true;
                Q.push(v);
            }
        }
    }


}

// DFS search
void graph::DFS(int s){
    visited[s] = true;
    cout<<s<<" ";
    list<int>::iterator i;

    for (i = adj[s].begin();i!= adj[s].end();++i){
        int v = *i;
        if (!visited[v]) {
            //cout<<v<<" ";
            
            DFS(v);
            
            }
    }
}

// topo sort using dfs
void graph ::DFS_topo(int s, stack<int> &Stack){
    visited[s] = true;
    list<int> ::iterator i;

    for(i = adj[s].begin();i!= adj[s].end();++i){
        int v = *i;
        if(!visited[v]){
            DFS_topo(v,Stack);
        }
    }
}

void graph:: topo_sort(){
    memset(visited,false,sizeof(visited));

    stack<int> Stack;
    for(int s = 0;s< V ;s++){
        if(visited[s] = false) DFS_topo(s,Stack);

        // in ket qua topo
        while (!Stack.empty()){

            cout << Stack.top()<<" ";
            Stack.pop();
        }
    }
}