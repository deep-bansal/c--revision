#include<bits/stdc++.h>
using namespace std;

int mergeSorted(int* arr,int s, int e){
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k =0;
    int length = e -s +1;
    int temp[length] = {0};
    int cnt = 0;

    while(i <= mid && j <= e){
        if(arr[i]<arr[j]){
            temp[k]= arr[i];
            i++;
            k++;
        }
        else{
            temp[k] =arr[j];
            j++;
            k++;
            cnt  += mid - i + 1;
        }
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j<= e){
        temp[k] = arr[j];
        k++;
        j++;
    }
    i = 0;
    while (s <= e) {
        arr[s] = temp[i];
        s++;
        i++;
    }
    return cnt;
} 


int inversionCount (int* arr,int s,int e){
    if(s >= e){
        return 0; 
    }

    int mid = (s+e)/2;

   int x =  inversionCount(arr,s,mid);
   int y =  inversionCount(arr,mid+1,e);
   int z =  mergeSorted(arr,s,e);
   return x+y+z;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }

    cout<<inversionCount(arr,0,n-1)<<endl;
    // for (int i = 0; i < n; ++i)
    // {
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}