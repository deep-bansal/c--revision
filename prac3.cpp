#include<bits/stdc++.h>
using namespace std;

int countSetBitsFast(int n){
	int ans = 0;
	while(n>0){
		n = n&(n-1);
		ans++;

	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<countSetBitsFast(n)<<endl;
	return 0;
}