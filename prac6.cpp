#include<bits/stdc++.h>
using namespace std;

int findMax(int n,int* arr){
    int ans = 0;
    for (int i = 0; i < n-2; ++i)
    {
        int num1 = arr[i],num2 =arr[i+1],num3=arr[i+2];

        int val = abs(num1-num2) + abs(num2-num3) + abs(num3-num1);

        ans = max(ans,val);

        
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }

        cout<<findMax(n,arr)<<endl;
    }
    return 0;
}