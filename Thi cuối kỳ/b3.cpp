#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

typedef pair<int,int> iPair;

class Graph{
    int V,E;
    
    vector<pair<int,iPair>> edges;
    public:
        Graph(int V,int E);
        void addEgdes(int v, int u,int w);
        //  Kruskal Khung cay nho nhat
        
        int KruskalMST();
        vector<pair<int,iPair>> Graph_tp(int arr[],int n);
    
    
};

Graph:: Graph(int V,int E){
    this->V = V;
    this->E = E;
}


void Graph :: addEgdes(int u,int v,int w){
    edges.push_back({w,{u,v}});
}

struct DisjointSets
{
    int *parent, *rnk;
    int n;
  
    // Constructor.
    DisjointSets(int n)
    {
        // Allocate memory
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
  
        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
  
            //every element is parent of itself
            parent[i] = i;
        }
    }
  
    // Find the parent of a node 'u'
    // Path Compression
    int find(int u)
    {
        /* Make the parent of the nodes in the path
        from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  
    // Union by rank
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        /* Make tree with smaller height
        a subtree of the other tree */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;
  
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};
  
/* Functions returns weight of the MST*/
  
int Graph::KruskalMST()
{
    int mst_wt = 0; // Initialize result
  
    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());
  
    // Create disjoint sets
    DisjointSets ds(V);
  
    // Iterate through all sorted edges
    vector< pair<int, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            //cout << u << " - " << v << endl;
  
            // Update MST weight
            mst_wt += it->first;
  
            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }
  
    return mst_wt;
}

vector<pair<int,iPair>> Graph:: Graph_tp(int arr[],int n){
    vector<pair<int,iPair>> canh;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = 0;k<edges.size();k++)
            {if(arr[i] == edges[k].second.first &&  arr[j] == edges[k].second.second){
                canh.push_back(edges[k]);
            }}
        }
    }

    return canh;
}

int main()
{
    int V,E;
    int u,v,w;
    int K;

    cin>>V>>E;
    Graph G(V,E);
    for(int i = 0;i<E;i++){
        cin>>u>>v>>w;
        G.addEgdes(u,v,w);
    }

    cin>>K;
    int arr[K];

    for(int i = 0;i<K;i++){
        cin>>arr[i];
    }

    vector<pair<int,iPair>> A;
    A = G.Graph_tp(arr,K);

//    for(int i = 0;i<A.size();i++){
//     cout<<A[i].first<<" "<<A[i].second.first<<" "<<A[i].second.second<<" "<<endl;
//    }
    Graph G_tp(K,A.size());
    for(int i = 0;i<A.size();i++){
        G_tp.addEgdes(A[i].second.first,A[i].second.second,A[i].first);
    }
    cout<<G_tp.KruskalMST();

    return 0;
}
