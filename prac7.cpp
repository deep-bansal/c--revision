#include <bits/stdc++.h>

using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,1,1,2,2,2,3,3};
	auto upper = upper_bound(v.begin(), v.end(),2);
	cout<<upper-v.begin()<<endl;
	return 0;
}