#include <bits/stdc++.h>
using namespace std;

class graph{
    int V;
    int connectedComponents;
    vector<int>parent;
    int* rank;
public:
    graph(int n){
        V= n;
        connectedComponents = n;
        parent.reserve(n);
        rank = new int[n];
        for (int i = 0; i < V; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int getparent(int x){
        if(parent[x] == x) return x;

        parent[x] = getparent(parent[x]);
        return parent[x]; 
    }

    void unite( int x,int y){
        int parU = getparent(x);
        int parV = getparent(y);
        if(parU != parV ){
            if(rank[parU] < rank[parV]){
                parent[parU] = parV;
                rank[parV] += rank[parU];
            }else{
                parent[parV] = parU;
                rank[parU] += rank[parV];
            }            
            connectedComponents--;
        }
    }
};


int main(int argc, char const *argv[])
{
    int n = 7;
    graph g(6);
    int numEdges = 9;
    vector<vector<int> > edges;
    edges.reserve(numEdges);
    vector<int> x(3);
    x = {1, 0, 1 };
    edges.push_back(x);
    x = {4, 0, 3};
    edges.push_back(x);
    x = {3, 0, 4};
    edges.push_back(x);
    x = {4, 1, 3};
    edges.push_back(x);
    x = {2, 1, 4};
    edges.push_back(x);
    x = {4, 4, 2};
    edges.push_back(x);
    x = {7, 4, 5};
    edges.push_back(x);
    x = {5, 2, 5};
    edges.push_back(x);
    x = {4, 4, 3};
    edges.push_back(x);

    sort(edges.begin(), edges.end());
    int totalCost = 0;
    for (int i = 0; i < numEdges; ++i)
    {
        int x= edges[i][1];
        int y = edges[i][2];
        int wt = edges[i][0];

        if (g.getparent(x) != g.getparent(y)) {
            g.unite(x, y);
            totalCost += wt;
        }

    }
    cout<<totalCost<<endl;

    return 0;
}