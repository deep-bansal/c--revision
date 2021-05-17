#include <bits/stdc++.h>
using namespace std;

// template <typename T>
class graph
{
    unordered_map<string,list<string> >mp;
public:
    void addEdge(string x,string y){
        mp[x].push_back(y);
    }

    // void dfs_helper(string src,map<string,bool>&visited,list<string>&ordering){
    // 	visited[src] = true;

    // 	for(auto nbr: mp[src]){
    // 		if(!visited[nbr]) dfs_helper(nbr,visited,ordering);
    // 	}

    // 	ordering.push_front(src);
    // }

    // void topoSortDFS(){
    // 	map<string,bool>visited;
    // 	list<string>ordering;

    // 	for(auto vertex:mp){
    // 		if(!visited[vertex.first]){
    // 			dfs_helper(vertex.first,visited,ordering);
    // 		}
    // 	}

    // 	for(auto x:ordering){
    // 		cout<<x<<endl;
    // 	}

    // }


    void topo_sort(){
    	unordered_map<string,int>inDeg;
    	list<string>ans;
    	for(auto v:mp){
    		inDeg[v.first] = 0;
    	}
    	for(auto p : mp){
    		for(auto v: p.second){
    			inDeg[v]++;
    		}
    	}

    	queue<string>q;
    	for(auto p : inDeg){
    		if(inDeg[p.first] == 0) q.push(p.first); 
    	}

    	while(!q.empty()){
    		string front  = q.front();
    		q.pop();
    		ans.push_back(front);
    		for(auto nbr:mp[front]){
    			inDeg[nbr]--;
    			if(inDeg[nbr] == 0)q.push(nbr);
    		}
    	}

    	for(auto x:ans)cout<<x<<endl;

    }

 
    // void printList() {

    //     for (auto pr : mp)
    //     {
    //         string vertex = pr.first;

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

	g.topo_sort();
    return 0;
}