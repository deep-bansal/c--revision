#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s = "jquery";
    stringstream check1(s);
    string str;
    vector<string>st;
    while(getline(check1,str,' ')){
    	st.push_back(str);
    }
    for(auto x:st){
    	cout<<x<<endl;
    }
	return 0;
}