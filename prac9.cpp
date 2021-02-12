#include<bits/stdc++.h>
using namespace std;

void towerofhanoi(int n , char start,char peg,char dest){
	if(n == 0){
		return;
	}

	towerofhanoi(n-1,start,dest,peg);
	cout<<"Moving ring "<<n << " from "<< start << " to "<<dest<<endl;

	towerofhanoi(n-1,peg,start,dest);

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	towerofhanoi(n,'A','C','B');
	return 0;
}