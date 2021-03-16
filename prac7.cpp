#include<bits/stdc++.h>
using namespace std;

bool isOperand(char x) {
    if (x >= '0' && x <= '9') {
        return true;
    }
    return false;
}

int evaluatePostfix(string s)
{
    // Your code here
    int ans  = 0;
    stack<int>st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (isOperand(ch)) {
            st.push(ch - '0');
        } 
        else {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if(ch == '+'){
                ans = b+a;
            }else if(ch == '-'){
                ans = b-a;
            }else if(ch == '*'){
                ans = b*a;
            }
            else if (ch == '/'){
                ans = b/a;
            }
            st.push(ans);
        }
    
}
return ans;
}
int main(int argc, char const *argv[])
{
    string s = "231*+9-";
    cout<<evaluatePostfix(s)<<endl;
    return 0;
}