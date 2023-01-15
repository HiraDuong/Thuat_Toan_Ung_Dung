#ifndef GRAPH_H
#define GRAPH_H
#include<list>
using namespace std;
class graph{
        int V;
        list<int> *adj;
    public:
        bool visited[1000];
        int numVertex();
        graph(int V);
        void addEgde(int v, int w);
        void addEgde_o(int v,int w);
        void BFS(int s);
        void DFS(int s);
        void DFS_topo(int s, stack<int>& Stack );
        void topo_sort();
};


#endif