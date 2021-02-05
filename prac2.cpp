#include<bits/stdc++.h>
using namespace std;

int rotatedBinarySearch(int arr[], int s,int e,int key){
    if(s>e){
        return -1;
    }

    int mid = (s+e)/2;

    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] <= arr[e]){
        if(arr[mid] < key && key <= arr[e]){
           return rotatedBinarySearch(arr,mid+1,e,key);
        }
        else{
             return rotatedBinarySearch(arr,s,mid-1,key);

        }
    }
    else{
        if(arr[s]<= key && key < arr[mid]){
            return rotatedBinarySearch(arr,s,mid-1,key);
        }else{
             return rotatedBinarySearch(arr,mid+1,e,key);
        }
    }

}

int countBinary(int n,string input){
    if(n == 0){
        return 1;
    }
    int count  = 0;
    int length = input.length();
    if(input[length - 1] == '0'){
        count  = countBinary(n-1,input + "1") + countBinary(n-1,input + "0");
    }
    else{
        count  =  countBinary (n-1, input + "0"); 
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int ans = countBinary(n-1,"0") + countBinary(n-1,"1");
    cout<<ans<<endl;
    return 0;
}