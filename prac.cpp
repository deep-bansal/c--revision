#include <bits/stdc++.h>
using namespace std;

void throughSort(int*arr,int n,int target){

	//time complexity o(nlogn)

		int a = -1,b = -1;
		sort(arr,arr+n);

		int left = 0,right = n-1;
		while(left<right){
			if(arr[left] + arr[right] == target){
				a=left;
				b = right;
				break;
			}
			else if (arr[left] + arr[right] < target){
				left++;
			}
			else{
				right--;
			}
		}
		if(a != -1 and b!= -1){
		cout<<a<<" "<<b<<endl;	
		}
		else{
			cout<<"No Pair possible"<<endl;
		}
	
}
int main(int argc, char const *argv[])
{
	int arr[] = {2,7,11,15};
	int n = sizeof(arr)/sizeof(int);
	int target = 9;

	throughSort(arr,n,target); 


	return 0;
}