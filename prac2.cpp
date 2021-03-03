#include <bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int>q1,q2;
	int currSize;
public:
	Stack(){
		currSize = 0;
	}

	bool empty(){
		return currSize == 0;
	}

	void push(int ele){
		q2.push(ele);
		while(!q1.empty()){
			q2.push(q1.front());
			q1.pop();
		}
		currSize++;
		queue<int>q = q1;
		q1 = q2;
		q2 = q;
	}
	void pop(){
		if(empty()){
			cout<<"stack is empty"<<endl;
			return;
		}
		q1.pop();
		currSize--;
	}

	int top(){
		if(q1.empty()){
			cout<<"Stack is Empty"<<endl;
			return -1;
		}

		return q1.front();
	}
	
};

int main(int argc, char const *argv[])
{

	Stack s;
	s.push(2);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();

	}
	cout<<s.top()<<endl;
	s.pop();
	return 0;
}