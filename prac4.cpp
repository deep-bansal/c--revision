#include<bits/stdc++.h>
using namespace std;

class graph
{
   int V;
   unordered_map<int,list<int> >mp;
public:
   graph(int V){
      this->V = V;
   }
   void addEdge(int x,int y){
      mp[x].push_back(y);
      mp[y].push_back(x);
   }

   void aPoint_helper(int i,bool visited[],bool ap[],int parent[],int disc[],int low[]){
      visited[i] = true;
      static int time = 0;
      int children = 0;
      disc[i] = low[i] = ++time;

      for(auto nbr : mp[i]){
         if(!visited[nbr]){
            children ++;
            parent[nbr] = i;
            aPoint_helper(nbr,visited,ap,parent,disc,low);

            low[i] = min(low[i],low[nbr]);
            if(parent[i] == -1 && children > 1) ap[i] = true;
            if(parent[i] != -1 && low[nbr] >= disc[i]){
               ap[i] = true;
            }
         }
         else if(nbr != parent[nbr]){
            low[i] = min(low[i],disc[nbr]);
         }
      }
   }

   void aPoint(){
      bool* visited = new bool[V];
      bool* ap = new bool[V];
      int* parent = new int[V];
      int*disc = new int[V];
      int* low = new int[V];

      for(int i=0;i<V;i++){
         parent[i] = -1;
         ap[i] = visited[i] = false;
      }

      for(int i=0;i<V;i++){
         if(!visited[i]){
            aPoint_helper(i,visited,ap,parent,disc,low);
         }
      }

      for(int i=0;i<V;i++){
         if(ap[i])cout<<i<<" ";
      }
      cout<<endl;
   }
   
};

int main(){
    graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.aPoint();
}