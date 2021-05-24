#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    int E;
    vector<vector<int> >edges;  
public:
    graph(int v,int e){
        this->V = v;
        E = e;
        edges.reserve(e);
    }

    void addEdge(int x,int y,int cost,int edgeNum){
        edges[edgeNum] = {x,y,cost};
    }
    void bellman_ford(int src){
        vector<int>dist(V);
        for (int i = 0; i < V; ++i)
        {
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        for(int i=0;i<V-1;i++){
            for(int j=0;j<E;j++){
                int src = edges[j][0];
                int dest = edges[j][1];
                int cost = edges[j][2];
                if(dist[dest] > dist[src] + cost){
                    dist[dest] = dist[src] + cost;
                }
            }
        }
        for(int j=0;j<E;j++){
                int src = edges[j][0];
                int dest = edges[j][1];
                int cost = edges[j][2];
                if(dist[dest] > dist[src] + cost){
                    cout<<"negative cycle";
                }
        }

        for(int i=0;i<V;i++){
            cout<<i<<"--->"<<dist[i]<<endl;
        }



    }
};

int main(int argc, char const *argv[])
{
    int vertices = 7, edges = 8;
    graph g(vertices, edges);

    g.addEdge(0, 1, 4, 0);
    g.addEdge(0, 6, 2, 1);
    g.addEdge(1, 2, 3, 2);
    g.addEdge(2, 3, 3, 3);
    g.addEdge(3, 4, -5, 4);
    g.addEdge(4, 5, 2, 5);
    g.addEdge(2, 4, 1, 6);
    g.addEdge(6, 4, 2, 7);

    g.bellman_ford(0);
    

    
    return 0;
}