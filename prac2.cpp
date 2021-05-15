#include <bits/stdc++.h>
using namespace std;

class graph
{
    map<string,list<string > >l;   
public:
    void addEdge(string x,string y,bool bidir = true){
        l[x].push_back(y);
        if(bidir){
            l[y].push_back(x);
        }
    }

    void printList ()
    {
        for (auto pr : l )
        {
            string vertex = pr.first;
            list <string> neighbours = pr.second;
            cout << vertex << "--> ";

            for (auto nbr : neighbours)
            {
                cout << nbr <<" ";
            }
            cout << endl;
        }
    }

    void shortestDist(string src){
        map<string,int>dist;
        queue<string>q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            string fNode = q.front();
            q.pop();
            for(auto nbr:l[fNode]){
                if(dist.count(nbr) == 0){
                    dist[nbr] = dist[fNode] +1;
                    q.push(nbr);
                }
            }
        }

        for (auto d : dist)
        {
            string vertex = d.first;
            cout << vertex << " -> " << d.second<<" ";

        }
        cout << endl;
    }

};

int main(int argc, char const *argv[])
{
    graph g;
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.addEdge("B", "C");
    g.addEdge("D", "E");
    g.addEdge("C", "E");

    g.shortestDist("A");

    g.printList();

    
    return 0;
}