#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll int hisTogram(ll int* arr,int n){
	stack<int>st;
	st.push(0);
	ll int maxArea = INT_MIN;
	int i;
	for (i = 1; i < n; ++i)
	{
		
		if(arr[i] >= arr[st.top()]){
			st.push(i);
		}
		else{
			ll int x = st.top();
			st.pop();

			ll int currArea=0;
			if(!st.empty()){
				currArea = arr[x]* (i - st.top() -1);
				maxArea = max(maxArea,currArea);
			}
			else{
				currArea = arr[x]*i;
				maxArea = max(maxArea,currArea);
			}
			st.push(i);
		}
	}

	while(!st.empty()){
		ll int x = st.top();
		st.pop();
			ll int currArea=0;
			if(!st.empty()){
				currArea = arr[x]* (i - st.top() -1);
				maxArea = max(maxArea,currArea);
			}
			else{
				currArea = arr[x]*i;
				maxArea = max(maxArea,currArea);
			}

	}
	return maxArea;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	ll int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cout<<hisTogram(arr,n)<<endl;
	return 0;
}