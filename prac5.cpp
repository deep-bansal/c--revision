#include <bits/stdc++.h>

using namespace std;
void allidx (int*arr ,int m,int n,int i,int* store,int j)
{
    if(i==n)
    {
        return;
    }
    if(i<n && arr[i]==m)
    {
        store[j]=i;
        allidx(arr,m,n,i+1,store,j+1);
    }
    else
    {
        allidx(arr,m,n,i+1,store,j);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int store[n];
    memset(store,-1,sizeof(arr));
    // for (int i = 0; i < n; ++i)
    // {
    //   cout<<store[i]<<endl;
    // }
    allidx(arr,m,n,0,store,0);

    for(int k=0;store[k]!=-1;k++)
    {
        cout<<store[k]<<" ";
    }

    return 0;
}