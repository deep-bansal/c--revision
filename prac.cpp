#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<string,list<string> >mp;
public:
    void addEdge(string x,string y,bool bidirectional =false){
        mp[x].push_back(y);
        if(bidirectional)mp[y].push_back(x);
    }

    // void bfsShortestPath(int src){
    //     unordered_map<int,int>dist;
    //     queue<int>q;
    //     q.push(src);
    //     dist[src] = 0;
    //     while(!q.empty()){
    //         int front = q.front();
    //         q.pop();
    //         for(auto nbr : mp[front]){
    //             if(dist.count(nbr) == 0){
    //                 dist[nbr] = dist[front]+1;
    //                 q.push(nbr);
    //             }
    //         }
    //     }

    //     for(auto x:dist){
    //         cout<<x.first<<"--->"<<x.second<<endl;
    //     }

    // }

    void dfs_helper(string src,unordered_map<string,bool>&visited,list<string>&ans){
        visited[src] = true;

        for(auto nbr:mp[src]){
            if(!visited[nbr]){
              dfs_helper(nbr,visited,ans);
            }

        }
        ans.push_front(src);

    }

    void dfs(){
        unordered_map<string,bool>visited;

        list<string>ans;
        for(auto x:mp){
            if(!visited[x.first]){
                dfs_helper(x.first,visited,ans);
            }
        }
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    void printList(){
        for(auto v: mp){
            cout<<v.first<<"--->";
            for(auto x:v.second){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    graph g;
    g.addEdge("10", "diploma");
    g.addEdge("10", "11");
    g.addEdge("11", "12");
    g.addEdge("12", "drop");
    g.addEdge("12", "JEE");
    g.addEdge("12", "DU");
    g.addEdge("drop", "JEE");
    g.addEdge("JEE", "B.Tech");
    g.addEdge("JEE", "B.E.");
    g.addEdge("diploma", "B.Tech");
    g.addEdge("extraordinary", "B.Tech");
    g.printList();
    g.dfs();
    
    return 0;
}