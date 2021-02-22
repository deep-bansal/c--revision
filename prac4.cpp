#include <bits/stdc++.h>
using namespace std;

int ans[7];

void stockSpan(int stocks[],int days){
  stack<int>st;
  for(int i=0;i<7;i++){
    while(!st.empty() and  stocks[st.top()]<= stocks[i]){
      st.pop();
    }
    ans[i] = st.empty()? i-i:i-st.top();
    st.push(i); 
  }
}

int main(int argc, char const *argv[])
{
  int stocks[7] = {100,90,70,80,85,60,90};
  int days = 7;
  stockSpan(stocks,days);
  for (int i = 0; i < 7; ++i)
  {
    cout<<ans[i]<<" ";;
  }
  cout<<endl;
  return 0;
}