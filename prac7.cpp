#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int* maxOfk(int*arr,int n,int k){
	int* ans = new int[n-k+1];
	deque<int>dq(k);
	int i,j=0;

	for(i=0;i<k;i++){
		while(!dq.empty() && arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for (i = k; i < n; ++i)
	{
		ans[j] = dq.front();
		j++;
		while(!dq.empty() && dq.front()< i-k+1){
			dq.pop_front();
		}

		while(!dq.empty() && arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}		
		dq.push_back(i);
	}

	ans[j++] = dq.front();
	return ans;
}

int main(int argc, char const *argv[])
{
	int arr[] = {10,1,8,0,6,9,15};
	int n = sizeof(arr)/sizeof(int);
	int k = 3;

	int* result  = maxOfk(arr,n,k);
	for (int i = 0; i < (n-k+1); ++i)
	{
		cout<<arr[result[i]]<<endl;
	}
	return 0;
}