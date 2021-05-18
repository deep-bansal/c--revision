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