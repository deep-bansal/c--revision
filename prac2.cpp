#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,int> > node;
 vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>res;
        priority_queue<node,vector<node>,greater<node> >pq;
        int i = 0;
        while(i<K){
            node ele = make_pair(arr[i][0],make_pair(i,0));
            pq.push(ele);
            i++;
        }
        
        while(!pq.empty()){
            node topEle = pq.top();
            pq.pop();
            int ele = topEle.first;
            int arrNumber = topEle.second.first;
            int index = topEle.second.second;
            res.push_back(ele);
            if(index+1 < arr[arrNumber].size()){
            node nextEle = make_pair(arr[arrNumber][index+1],make_pair(arrNumber,index+1));
            pq.push(nextEle);
            }
        }
        return res;
    }

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>k>>n;

	vector <vector<int> >vec;

	for(int i=0;i<k;i++)
	{
		vector<int> v1;
		for(int j=0; j<n; j++)
		{
			int data;
			cin>>data;
			v1.push_back(data);
		}
		vec.push_back(v1);
	}	
	vector<int>ans = mergeKArrays(vec,k);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}

	
	return 0;
}