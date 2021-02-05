#include<bits/stdc++.h>
using namespace std;
static int MOD= 10000003;
#define ll long long

bool isPossible(int* arr,int n,int p,ll int mid){
   int pratasCooked = 0;
   for (int i = 0; i < n; ++i)
   {
       ll int time = 0,j = 1;
       while(time <= mid){
        time += arr[i]*j;
        if(time > mid){
            break;
        }
        j++;
        pratasCooked++;
       }
       if(pratasCooked >= p){
        return true;
       }
   }
   return false;
    
}

ll int pratas( int*arr, int n, int p){
     ll int start = 0,end = 0,total = 0;
    for (int i = 1; i <= p; ++i)
    {
        total += arr[0]*i;        
    }
    end = total;

    ll int ans = 0;

    while(start <= end){
        ll int mid=(start +(end-start)/2);
        if(isPossible(arr,n,p,mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){

    int p,n;
    cin>>p>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cout<<pratas(arr,n,p)<<endl;
    }
    return 0;
}