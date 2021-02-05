#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int* arr,int n){

	for (int i = 0; i < n; ++i)
	{
		bool isSorted = true;
		for (int j = 0; j < n - i -1  ; ++j)
		{
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
				isSorted = false;
			}
		}
		if(isSorted == true){
			return;
		}
	}
}
void iSort(int* arr,int n){

	for (int i = 1; i < n; ++i)
	{
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;

	}
}

// int* fun(){
// 	int a[] = {2,4,8,9};
// 	cout<<"value of a "<<a<<endl;
// 	cout<<"value of a[0] "<<a[0]<<endl;
// 	return a;
// }
// int main(int argc, char const *argv[])
// {
// 	int* b = fun();
// 	cout<<"value of b "<<b<<endl;
// 	cout<<"value of b[0] "<<b[0]<<endl;
// 	return 0;
// }

void bubbleSort2(char** strings,int n){

	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if(strcmp(strings[j],strings[j+1]) > 0 ){
				swap(strings[j],strings[j+1]);
			}
		}
		
	}


}

int main(int argc, char const *argv[])
{
	char ** strings;
	int n;
	cin>>n;
	strings = new char*[n];
	for (int i = 0; i < n; ++i)
	{
		
		strings[i] = new char [30];
		cin>>strings[i];
	}
	bubbleSort2(strings,n);
	for (int i = 0; i < n; ++i)
	{
		int j = 0;
		while(strings[i][j] != '\0'){
			cout<<strings[i][j];
			j++;
		}
		cout<<endl;
	}
	return 0;
}