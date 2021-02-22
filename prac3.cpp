#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack <int> &st,int val){

	if(st.empty()){
		st.push(val);
		return;
	}

	int temp = st.top();
	st.pop();
	insertAtBottom(st,val);
	st.push(temp);

}
void reverse(stack<int>&st){
	if(st.empty()){
		return;
	}

	int temp = st.top();
	st.pop();
	reverse(st);
	insertAtBottom(st,temp);

	return;

}
int main(int argc, char const *argv[])
{
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	reverse(st);
	cout << st.top() << " ";
	st.pop();
	cout << st.top() << " ";
	st.pop();
	cout << st.top() << " ";
	st.pop();
	cout << st.top() << " ";
	st.pop();
	return 0;
}