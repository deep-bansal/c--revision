#include<bits/stdc++.h>
using namespace std;

bool isvalid(string s){
	//we are checking if string is valid or not 
	//if char == '(' then we push it else  we check for ')' if !st.empty() and st.top = '('
	// then only we would pop 
	stack<char>st;
	for(int i=0;i<s.length();i++){
		if(s[i] == '('){
			st.push('(');
		}
		else if(!st.empty()){
			st.pop();
		}else{
			return false;
		}
	}
	return st.empty();
}



int validParen(string s){
	//generating all the substrings of minimum length 2 and length is even
	int maxlen = 0;
	for(int i=0;i<s.length();i++){
		for(int j= i+2;j<=s.length();j+=2){
			if(isvalid(s.substr(i,j))){
				maxlen = max(maxlen,j-i);
			}


		}
	}
	return maxlen;
}
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;

	cout<<validParen(s);
	return 0;
}