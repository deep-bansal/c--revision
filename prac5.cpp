#include <bits/stdc++.h>
using namespace std;
string Reduced_String(int k,string s){
        // Your code goes here
        string ans = "";
        stack<char>st;
        for(int i=0;i<s.length();i++){
        	int count = 0;
            while(!st.empty() && count<k && s[i] == st.top()){
                st.pop();
                count++;
            }
            st.push(s[i]);

            
        }
        
        while(!st.empty()){
            ans += st.top();
            cout<<st.top()<<endl;
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
      
        return ans;
    }
int main(int argc, char const *argv[])
{
	int k;
	cin>>k;
	string s;
	cin>>s;
	cout<<Reduced_String(k,s)<<endl;
	
	return 0;
}