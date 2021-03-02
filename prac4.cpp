#include <bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n){
    // Your code here
    stack<long long>st;
    
    vector<long long>ans(n);
    st.push(arr[n-1]);
    ans[n-1] = -1;
    for(int i =n-2;i>=0;i--){
        
        while(!st.empty() && st.top()<= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
       for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return ans;
 
}

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  vector<long long>arr();


  return 0;
}