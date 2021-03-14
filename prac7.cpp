#include<bits/stdc++.h>
using namespace std;

int getPrec(char ch){
  if(ch == '^'){
    return 3;
  }
  else if (ch == '*' || ch=='/'){
    return 2;
  }
  else if(ch == '+' || ch=='-'){
    return 1;
  }
  else if(ch == ')' || ch == '('){
    return 0;
  }
  return -1;
}

void convertInfixToPrefix(string str){
  reverse(str.begin(),str.end());
  stack<char>st;
  string output;

  for(int i=0;i<str.length();i++){
    if(getPrec(str[i]) == -1){
      output+=str[i];
    }else{
      if(str[i] == ')'){
        st.push(str[i]);
      }
      else if(str[i] == '('){
        while(!st.empty() && st.top()!= ')'){
          output += st.top();
          st.pop();
        }
        st.pop();
      }else{
        while(!st.empty() && getPrec(st.top())>getPrec(str[i]) && st.top()!= ')'){
        output += st.top();
        st.pop();
      }
      st.push(str[i]);

      }
      
    }
  }
  while(!st.empty()){
    output += st.top();
    st.pop();
  }
  reverse(output.begin(),output.end());
  cout<<output<<endl;

}

int main(int argc, char const *argv[])
{
  string str = "(A+B)*(C-D)*E";
  convertInfixToPrefix(str);
  return 0;
}