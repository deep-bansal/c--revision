#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    unordered_map<int,list<pair<int,int> > >mp;
public:
    graph(int v){
        this->V = v;
    }

    void addEdge(int x,int y,int cost){
        mp[x].push_back({y,cost});
    }

    void shortestPath(int src){
        unordered_map<int,int>inDeg;
        for(auto x:mp){
            inDeg[x.first] = 0;
        }
        for(auto x:mp){
            for(auto y: x.second)inDeg[y.first]++;
        }

        list<int>ans;
        queue<int>q;
        for(auto z:mp){
            if(inDeg[z.first] == 0)q.push(z.first);
        }

        while(!q.empty()){
            int frnt  = q.front();
            ans.push_back(frnt);
            q.pop();
            for(auto nbr : mp[frnt]){
                inDeg[nbr.first]--;
                if(inDeg[nbr.first] == 0) q.push(nbr.first);
            }
        }
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;

        unordered_map<int,int>dist;
        for(auto x:ans) dist[x] = INT_MAX;
        dist[src] = 0;
        for(auto x:ans){
            if(dist[x] != INT_MAX){
                for(auto i:mp[x]){
                    if(dist[i.first] > dist[x] + i.second){
                        dist[i.first] = dist[x] + i.second;
                    }
                }
            }
        }

        for(auto x:dist){
            cout<<x.first<<"--->"<<x.second<<endl;
        }

    }
};

int main(int argc, char const *argv[])
{
    graph g(5);
    g.addEdge(0,1,2);
    g.addEdge(0,4,1);
    g.addEdge(1,2,3);
    g.addEdge(2,3,6);
    g.addEdge(4,2,2);
    g.addEdge(4,5,4);
    g.addEdge(5,3,1);
    g.shortestPath(0);
    return 0;
}