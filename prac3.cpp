#include<bits/stdc++.h>
using namespace std;
int ans = -1;
void foundAt(int*arr,int i,int m){
	if(i < 0){
		return;
	}

	if(arr[i] == m){
		 ans =  i;
		 return;
	}

	foundAt(arr,i-1,m);
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int m;
	cin>>m;
	foundAt(arr,n-1,m);
	cout<<ans<<endl;
	return 0;
}