#include<bits/stdc++.h>
using namespace std;

class graph
{
	int vertices;
	unordered_map<int,list<pair<int,int> > >mp; 
public:
	graph(int v){
		this->vertices = v;
	}
	void addEdge(int x,int y,int cost,bool bidirectional = true){
		mp[x].push_back({y,cost});
		if(bidirectional) mp[y].push_back({x,cost});
	}

	void dijkstra(int src){
		unordered_map<int,int>dist;
		set<pair<int,int> >disSet;
		// dist,node

		for(auto v : mp){
			dist[v.first] = INT_MAX;
		}
		dist[src] = 0;
		disSet.insert({0,src});
		while(!disSet.empty()){
			auto minDisNode = *(disSet.begin());
			int node = minDisNode.second;
			int nodeDist = minDisNode.first;
			disSet.erase(disSet.begin());
			for(auto nbr : mp[node]){
				if(nbr.second + nodeDist < dist[nbr.first]){
					auto findInSet = disSet.find({dist[nbr.first],nbr.first});
					if(findInSet != disSet.end()){
						disSet.erase(findInSet);
					}

					disSet.insert({nbr.second + nodeDist,nbr.first});
					dist[nbr.first] = nbr.second + nodeDist;
				}

			}
		}

		for(auto v : dist){
			cout<<v.first<<"--->"<<v.second<<endl;
		}


	}
	
};

int main(int argc, char const *argv[])
{
	graph g(5);

	g.addEdge(0, 1, 2);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 3, 2);
	g.addEdge(0, 3, 7);
	g.addEdge(0, 2, 5);
	g.addEdge(3, 4, 3);

	g.dijkstra(0);
	
	return 0;
}