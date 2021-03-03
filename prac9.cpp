#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string a = "abcadabbxcyxz";
	int visited[256];
	memset(visited,-1,256);

	int currLen = 1;
	int maxLen = 1;
	visited[a[0]] = 0;

	for (int i = 1; i < a.length() ; ++i)
	{
		int last_occ = visited[a[i]];

		if(last_occ == -1 || i-currLen > last_occ){ 
		// last_occ of character is smaller than curr window size
			currLen += 1;
		}else{
			maxLen = max(maxLen,currLen);
			currLen = i - last_occ;
			visited[a[i]] = i;
		}
		
	}
	maxLen = max(maxLen,currLen);
	cout<<maxLen<<endl;

	return 0;
}