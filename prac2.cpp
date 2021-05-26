#include <bits/stdc++.h>
using namespace std;

class graph{
    unordered_map<int,list<pair<int,int> > >mp;
public:
    void addEdge(int x,int y,int cost){
        mp[x].push_back({y,cost});
        mp[y].push_back({x,cost});
    }

    void mst(){
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
        bool* visited = new bool[100];
        int ans = 0;
        q.push({0,0});
        while(!q.empty()){
            auto edge = q.top();
            q.pop();
            int node = edge.second;
            int wt = edge.first;
            if(visited[node]) continue;

            visited[node] = true;
            ans += wt;
            for(auto x : mp[node]){
                if(!visited[x.first]){
                    q.push({x.second,x.first});
                }
            } 
        }
    }


};


int main(int argc, char const *argv[])
{
    
    return 0;
}