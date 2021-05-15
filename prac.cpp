#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int>* arr;
public:
    graph(int V){
        this->V = V;
        arr = new list<int>[V];
    }

    void addEdge(int x,int y,bool bidirectional = true){
        arr[x].push_back(y);
        if(bidirectional){
            arr[y].push_back(x);
        }
    }

    void printList(){
        for(int i=0;i<V;i++){
            cout<<i<<"-> ";
            for(int nbr : arr[i]){
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
    
};

int main(int argc, char const *argv[])
{
    graph g(5);
    g.addEdge(0,2);
    g.addEdge(3,4);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.printList();
    
    return 0;
}