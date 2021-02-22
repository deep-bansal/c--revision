#include <bits/stdc++.h>

using namespace std;

void transfer(stack<int>&A, stack<int>&B,int n) {
	for(int i=0;i<n;i++) {
		B.push(A.top());
		A.pop();
	}

}

void reverse (stack<int>&st) {
	stack<int> st2;
	int n = st.size();
	for (int i = 0; i < n; i++) {
		int temp = st.top();
		st.pop();
		transfer(st,st2,n-1-i);
		st.push(temp);
		transfer(st2,st,n-1-i);
	}
}

int main(int argc, char const *argv[])
{
	stack<int> st;
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
}