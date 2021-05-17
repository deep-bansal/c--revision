#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{
    unordered_map<T,list<T> >mp;
public:
    void addEdge(T x,T y,bool bidirectional = true){
        mp[x].push_back(y);
        if(bidirectional){
            mp[y].push_back(x);
        }
    }

    // bool undirectedCycleDetectHelper(string src,unordered_map<T,bool> &visited,string parent){
    //     visited[src] = true;
    //     for(auto nbr : mp[src]){
    //         if(!visited[nbr]){
    //             if(undirectedCycleDetectHelper(nbr,visited,src)) return true;
    //         }
    //         else if(nbr != parent) return true;
    //     }
    //     return false;
    // }

    // void undirectedCycleDetect(string src){
    //     unordered_map<T,bool>visited;
    //     if(undirectedCycleDetectHelper(src,visited,""))cout<<"Cycle found"<<endl;
    //     else cout<<"cycle not found"<<endl;
    // }

    // bool cycleDetectUsingBfs(string src){
    //     unordered_map<string,bool>visited;
    //     unordered_map<string,string>parent;
    //     queue<string>q;
    //     q.push(src);
    //     visited[src] = true;
    //     parent[src] = "";
    //     while(!q.empty()){
    //         string front = q.front();
    //         q.pop();
    //         for(auto nbr:mp[front]){
    //             if(!visited[nbr]){
    //                 visited[nbr] = true;
    //                 q.push(nbr);
    //                 parent[nbr] = front;
    //             }else if(nbr != parent[front]){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }

    void printList() {

        for (auto pr : mp)
        {
            T vertex = pr.first;

            cout << vertex << " --> ";
            for (auto nbr : pr.second)
            {
                cout << nbr << ", ";
            }

            cout << endl;
        }

    }
};


int main(int argc, char const *argv[])
{
    graph<string> g;
    g.addEdge("A", "B");
    g.addEdge("A", "C");
    g.addEdge("B", "D");
    g.addEdge("C", "D");
    g.addEdge("C", "E");
    g.addEdge("E", "F");

    if(g.cycleDetectUsingBfs("A"))cout<<"true"<<endl;

    g.printList();
    return 0;
}