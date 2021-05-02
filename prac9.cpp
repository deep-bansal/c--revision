#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* arr,int n){
	for (int i = 0; i < n-1; ++i)
	{
		int j = i+1;
		int temp = arr[j];
		while(j>0 && temp< arr[j-1]){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;
		for (int i = 0; i < n; ++i)
    {
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
	}
}

int merge(int* arr,int s,int mid,int e){
	int temp[e-s+1];
	int i = s,j = mid+1,k = 0;
	int cnt = 0;
	while(i<=mid && j<=e){
		if(arr[i] < arr[j]){
			temp[k] = arr[i];
			i++;
		}else{
			temp[k] = arr[j];
			j++;
			cnt += mid-i+1;
		}
		k++;
	}

	while(i<=mid){
		temp[k] = arr[i];
		k++; i++;
	}
	while(j<=e){
		temp[k] = arr[j];
		k++;j++;
	}

	for (int i = s, j = 0 ; i <= e, j< e-s+1; ++i,++j)
	{
		arr[i] = temp[j];
	}
	return cnt;
		
}

int mergeSort(int* arr,int s,int e){
	if(s>=e) return 0;

	int mid = s + (e-s)/2;
	int x = mergeSort(arr,s,mid);
	int y = mergeSort(arr,mid+1,e);
	int z = merge(arr,s,mid,e);
	return x+y+z;

}

void swap(int*arr,int n,int pivot ){
	int i = -1;
	for (int j = 0; j < n; ++j)
	{
		if(arr[j]<= pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
}
int main(int argc, char const *argv[])
{
    int arr[] = {70,60,80,40,30};
    int n = sizeof(arr)/sizeof(int);
    swap(arr,n,30);
    for (int i = 0; i < n; ++i)
    {
    	cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}