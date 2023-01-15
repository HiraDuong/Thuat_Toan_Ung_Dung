#include<iostream>
#include "graph.h"
#include"graph.cpp"
#include<list>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>

int main()
{
    graph g(6);
    g.addEgde(5,2);
    g.addEgde(5,0);
    g.addEgde(4,0);
    g.addEgde(4,1);
    g.addEgde(2,3);
    g.addEgde(3,1);
 
    cout << "Following is a Topological Sort of the given "
            "graph \n";
    g.topo_sort(); 

    return 0;
}
