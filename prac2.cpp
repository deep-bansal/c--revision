#include <bits/stdc++.h>
using namespace std;

class graph
{
    // int V;
    unordered_map<int,list<pair<int,int> > >mp;   
public:
    void addEdge(int x,int y,int cost){
        mp[x].push_back({y,cost});
    }

    void getTopSort(list<int>&ans){
        unordered_map<int,int>inDeg;
        for(auto x:mp){
            inDeg[x.first] = 0;
        }
        for(auto x:mp){
            for(auto y:x.second){
                inDeg[y.first]++;
            }
        }

        queue<int>q;
        for(auto x:mp){
            if(inDeg[x.first] == 0) q.push(x.first);
        }

        while(!q.empty()){
            int frnt = q.front();
            ans.push_back(frnt);
            q.pop();
            for(auto nbr:mp[frnt]){
                inDeg[nbr.first]--;
                if(inDeg[nbr.first] == 0)
                    q.push(nbr.first);
            }
        }
    }

    void shortestPath(int src){
        list<int>ans;
        getTopSort(ans);
        unordered_map<int,int>dist;
        
        // for(auto x: ans)cout<<x<<" ";
        // cout<<endl;

        for(auto y:ans)dist[y] = INT_MAX;

        dist[src] = 0;

        for(auto x:ans){
            for(auto nbr: mp[x]){
                if(dist[nbr.first] > dist[x] + nbr.second){
                    dist[nbr.first] = dist[x] + nbr.second;
                }
            }
            cout<<endl;
        }
        for(auto x:dist){
            cout<<x.first<<"--->"<<x.second<<endl;
        }


    }    

};

int main(int argc, char const *argv[])
{
    graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,3);
    g.addEdge(2,3,4);
    g.addEdge(1,3,2);
    // g.addEdge(4,2,2);
    // g.addEdge(4,5,4);
    // g.addEdge(5,3,1);
    g.shortestPath(0);

    
    return 0;
}