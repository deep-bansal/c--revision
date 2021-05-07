#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
int findRooms(vector<vector<int> >&v){

	priority_queue<p,vector<p>,greater<p> >startTimeHeap;
	priority_queue<p,vector<p>,greater<p> >endTimeHeap;
	int i = 0;
	while(i < v.size()){
		startTimeHeap.push(make_pair(v[i][0],v[i][1]));
		i++;
	}

	int cnt = 0;
	if(!startTimeHeap.empty()){
		cnt++;
		p meet = startTimeHeap.top();
		endTimeHeap.push(make_pair(meet.second,meet.first));
		startTimeHeap.pop();
	}

	while(!startTimeHeap.empty()){
		p currMeet = startTimeHeap.top();
		startTimeHeap.pop();
		if(currMeet.first > endTimeHeap.top().first){
			int heapS = endTimeHeap.size();
			cnt = max(cnt,heapS);
			endTimeHeap.pop();
		}
			endTimeHeap.push(make_pair(currMeet.second,currMeet.first));
	}
	int size = endTimeHeap.size();
	cnt = max(cnt,size);
	return cnt;
}

int main(int argc, char const *argv[])
{
		vector<vector<int> >v = {{0,30},
								{5, 10},
								{7,10},
								{15,20},
								{20,15}};
	int roomsReq = findRooms(v);
	cout<<roomsReq<<endl;
	
	return 0;
}