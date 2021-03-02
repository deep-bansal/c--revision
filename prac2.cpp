#include <bits/stdc++.h>

using namespace std;

int compress(vector<char>& chars) {
	vector<char>ans;
	int start = 0, i = 1;
	while (i < chars.size()) {
		int count = 1;
		while (i < chars.size() && chars[start] == chars[i]) {
			i++;
			count++;
		}
		if (count == 1) {
			ans.push_back(chars[start]);
			
		} else {
			ans.push_back(chars[start]);
			if (count < 10) {
				ans.push_back(count + '0');

			} else {

				string y = to_string(count);
				for (int i = 0; i < y.length(); i++) {

					ans.push_back(y[i]);
				}

			}
		}
		start = i;
			i++;
	}
	  chars =ans;
    return ans.size();
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}