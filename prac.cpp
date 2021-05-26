#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int,list<pair<int,int>> >mp;
public:
    void addEdge(int x,int y,int cost){
        mp[x].push_back({y,cost});
        mp[y].push_back({x,cost});
    }

    void dijkstra(int src){
        unordered_map<int,int>dist;
        set<pair<int,int>>s;
        for(auto x : mp){
            dist[x.first] = INT_MAX;
        }
        dist[src] = 0;
        s.insert({0,src});
        while(!s.empty()){
            pair<int,int>front = *(s.begin());
            int node = front.second;
            int distance = front.first;
            s.erase(s.begin());
            for(auto nbr : mp[node]){
                if(dist[nbr.first] > distance + nbr.second){
                    dist[nbr.first] = distance + nbr.second;
                    auto findInSet = s.find({dist[nbr.first],nbr.first});
                    if(findInSet != s.end()){
                        s.erase(findInSet);
                    }
                    s.insert({dist[nbr.first],nbr.first});
                }

            }
        }
        for(auto vr : dist){
                cout<<vr.first<<" "<<vr.second<<endl;
            }


    }

};

int main(int argc, char const *argv[])
{
    graph g;
    g.addEdge(0,1,3);
    g.addEdge(0,3,2);
    g.addEdge(0,2,1);
    g.addEdge(1,2,2);
    g.addEdge(3,2,3);
    g.addEdge(2,5,2);
    g.addEdge(2,4,1);
    g.addEdge(4,5,2);
    // g.addEdge(0, 1, 2);
    // g.addEdge(1, 2, 2);
    // g.addEdge(2, 3, 2);
    // g.addEdge(0, 3, 7);
    // g.addEdge(0, 2, 5);
    // g.addEdge(3, 4, 3);

    g.dijkstra(0);


    return 0;
}