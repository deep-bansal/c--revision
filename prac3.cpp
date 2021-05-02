#include <bits/stdc++.h>
using namespace std;

void countSort(int* arr,int n,int param){
	int count[10] = {0};
	param = pow(10,param);
	for (int i = 0; i < n; ++i)
	{
		count[(arr[i]/param)%10]++;
	}

	for (int i = 1; i < 10; ++i)
	{
		count[i] += count[i-1];
	}

	int output[n];
	for (int i = n-1; i >= 0 ; --i)
	{
		output[count[(arr[i]/param)%10]-1] = arr[i];
		count[(arr[i]/param)%10]--;		
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i] = output[i];
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {319,212,6,8,100,50};
	int n = sizeof(arr)/sizeof(int);
	int maxNo = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		maxNo = max(maxNo,arr[i]);
	}

	int dig = 0;
	while(maxNo > 0){
		dig++;
		maxNo = maxNo/10;
	}

	for (int i = 0; i < dig; ++i)
	{
		countSort(arr,n,i);		
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;


    return 0;
}