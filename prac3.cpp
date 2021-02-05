#include<bits/stdc++.h>
using namespace std;

int friendsPairing(int n){
	if(n == 0 || n == 1){
		return 1;
	}
	int count  = friendsPairing(n-1) + (n-1)*friendsPairing(n-2);
	return count;
}

void subseq(string input,string output){
	if(input.length() == 0){
		cout<<output<<endl;
		return;
	}
	char ch = input[0];
	string x2 = to_string(int(ch));


	string ros = input.substr(1);
	subseq(ros,output + ch + x2 );
	subseq(ros,output);

}

// void subseqChar(char* input,char* output,int i ,int j){
// 	if(input[i] == '\0'){
// 		output[j] = '\0';
// 		cout<<output<<endl;
// 		return;
// 	}

// 	output[j] = input[i];
// 	subseqChar(input,output,i+1,j+1);
// 	subseqChar(input,output,i+1,j);

// }

void print1256(string input, string output){

	if(input.length() == 0){
		cout<<output<<endl;
		return;
	}

	int one = input[0] - '0' ;
	int two = 0;
	if(input.length() >= 2){
		two = stoi(input.substr(0,2));
	}

	if(input.length() > 1&& two <= 26 ){
		string ros = input.substr(1);
		char ch = one + 'a' - 1;
		print1256(ros,output + ch);

		ros = input.substr(2);
		ch = two + 'a' - 1;
		print1256(ros,output + ch);
	}
	else{
		string ros = input.substr(1);
		char ch = one + 'a' - 1;
		print1256(ros,output + ch);
	}
}

void printPerm(string input,string output){
	if(input.length() == 0){
		cout<<output<<endl;
		return;
	}

	for (int i = 0; i < input.length(); ++i)
	{
		char ch = input[i];
		string ros = input.substr(0,i) + input.substr(i+1);
		printPerm(ros,output + ch );
	}
}

int main(int argc, char const *argv[])
{
	// int n;
 //    cin>>n;
 //    cout<<friendsPairing(n)<<endl;
	string input;

	cin>>input;
	// subseq(input,"");
	// 	char output[100];
	// subseqChar(input,output,0,0);
	// print1256(input,"");
	printPerm(input,"");

	return 0;
}