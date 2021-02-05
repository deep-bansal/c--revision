#include<bits/stdc++.h>
using namespace std;
static int MOD= 10000003;
#define ll long long

bool isPossible(ll int n,int k,ll int mid){
    if(pow(mid,k) <= n){
        return true;
    }
    return false;
}

ll int kthRoot(ll int n,int k){
    if(k == 1){
        return n;
    }
    int start = 0, end = pow(n,0.5);
    ll int ans = 0;
    while(start <= end){
        ll int mid = start + (end-start)/2;
        if(isPossible(n,k,mid)){
            ans =mid;
            start = mid +1;
        }
        else{
            end = mid -1;
        }

    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        ll int n;
        int k;
        cin>>n>>k;

        cout<<kthRoot(n,k)<<endl;
    }
    return 0;
}