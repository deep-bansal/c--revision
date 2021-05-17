#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<int,list<int> >mp;
public:
    void addEdge(int x,int y){
        mp[x].push_back(y);
    }

    void dfs_helper(int src,map<int,bool>&visited,int &cnt){
        visited[src] = true;
        cnt++;
        for(auto nbr:mp[src]){
            if(!visited[nbr]) dfs_helper(nbr,visited,cnt);
        }
    }

    int toMoon(int n){
        int totalPairs = (n*(n-1))/2;

        map<int,bool>visited;

        for(auto x : mp){
            int sameCnt = 0;
            if(!visited[x.first]){
                dfs_helper(x.first,visited,sameCnt);
            }
            int pairsfromSame = (sameCnt*(sameCnt-1))/2;
            totalPairs -= pairsfromSame;
        }
        return totalPairs;
    }
    
};

int main(int argc, char const *argv[])
{
    int n,p;
    cin>>n>>p;
    graph g;
    while(p--){
        int first,second;
        cin>>first>>second;
        g.addEdge(first,second);

    }

    cout<<g.toMoon(n)<<endl;
    
}