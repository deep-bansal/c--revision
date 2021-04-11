#include <bits/stdc++.h>
using namespace std;

void sumZero(int arr[],int n){
    unordered_map<int,int>mp;
    for (int i = 0; i < n; ++i)
    {
        mp[arr[i]] == i;
    }

    for (int i = 0; i < n; ++i)
    {
        if(mp.count(0-arr[i])){
            cout<<arr[i]<<" + " <<0-arr[i]<<" = 0"<<endl;
             break;
        }

    }

    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }


}

int main(int argc, char const *argv[])
{
    int arr[6] = {3,2,4,-3,9,5};
    int n = sizeof(arr)/sizeof(int);

    sumZero(arr,n);
    
    return 0;
}