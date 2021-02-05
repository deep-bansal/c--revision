#include <bits/stdc++.h>
using namespace std;
int counting = 0;

void subseq (string input,string output){
	if(input.length() == 0){
		counting++;
		cout<<output<<" ";
		return;
	}

	char ch = input[0];
	string ros = input.substr(1);
	subseq(ros,output);
	subseq(ros,output + ch);
	
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	subseq(str,"");
	cout<<endl<<counting;
	return 0;
}