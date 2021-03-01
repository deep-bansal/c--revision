#include <bits/stdc++.h>
using namespace std;

void stockSpan(int* arr,int n){
    stack<int>st;
    st.push(0);
    cout<<1<<" ";

    for (int i = 1; i < n; ++i)
    {
        while(!st.empty() && arr[st.top()]<= arr[i]){
            st.pop();

        }        
        if(st.empty()){
            cout<<i+1<<" ";
        }else{
            cout<<(i-st.top())<<" ";
        }

        st.push(i);
    }

    cout<<"END";

    
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    stockSpan(arr,n);
    return 0;
}