#include <bits/stdc++.h>
using namespace std;
// template <typename T>
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
        mp[y].push_back({x,cost});
    }

    // bool dfs_helper(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&stack){
    //     visited[src] = true;
    //     stack[src] = true;
    //     for(auto nbr :mp[src]){
    //         if(stack[nbr]) return true;
    //         else if(!visited[nbr]){
    //             if(dfs_helper(nbr,visited,stack))return true;
    //         }
    //     }
    //     stack[src] = false;
    //     return false;
    // }

    int holi_helpler(int src,unordered_map<int,pair<bool,int> >&visited,int &maxDist){
        visited[src] = make_pair(true,1);

        for(auto nbr:mp[src]){
            int nbr_name = nbr.first;
            int cost = nbr.second;
            if(!visited[nbr_name].first){
                visited[src].second += holi_helpler(nbr_name,visited,maxDist);
                int nodesRight = visited[nbr_name].second;
                int nodesLeft = V-nodesRight;
                maxDist = 2*max(nodesRight,nodesLeft)*cost;
            } 
        }
        return visited[src].second;

    }

    void holi(){
        unordered_map<int,pair<bool,int> >visited;
        for(int i=0;i<V+1;i++){
            visited[i] = make_pair(false,0);
        }
        int maxDistTravelled = 0;
        holi_helpler(1,visited,maxDistTravelled);
        cout<<maxDistTravelled<<endl;

        
    }

    // void printList() {

    //     for (auto pr : mp)
    //     {
    //         int vertex = pr.first;

    //         cout << vertex << " --> ";
    //         for (auto nbr : pr.second)
    //         {
    //             cout << nbr << ", ";
    //         }

    //         cout << endl;
    //     }

    // }
};

int main(int argc, char const *argv[])
{
    graph g(6);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 8);
    g.addEdge(5, 6, 5);
    // g.addEdge(2, 4, 1);

    g.holi();
    return 0;
}