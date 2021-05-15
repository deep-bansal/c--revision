#include <bits/stdc++.h>
using namespace std;

class graph
{
    unordered_map<string,list<string> >mp;
public:
    void addEdge(string x,string y,bool bidirectional = true){
        mp[x].push_back(y);
        if(bidirectional){
            mp[y].push_back(x);
        }
    }

    void dfs_helper(string src,map<string,bool>&visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto nbr: mp[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }

    void dfs(string src){
        map<string,bool>visited;
        for(auto x:mp){
            visited[x.first] = false;
        }

        dfs_helper(src,visited);
    }
    void printList ()
    {
        for(auto pr : mp )
        {
            string vertex = pr.first;
            list <string  > neighbours = pr.second;
            cout<< vertex <<"-->";

            for(auto nbr : neighbours)
            {
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    graph g;
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.addEdge("B", "C");
    g.addEdge("C", "E");

    g.dfs("A");
    cout << endl;
    g.printList();
    return 0;
}