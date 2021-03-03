#include <bits/stdc++.h>
using namespace std;

class Stack
{
	queue<int>q1,q2;
	int currentSize;
public:
	Stack(){
		currentSize = 0;
	}

	bool isEmpty(){
		return currentSize == 0;
	}


	void push(int ele){
		q1.push(ele);
		currentSize++;
	}

	void pop(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return;
		}

		while(q1.size()!= 1 ){
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop();
		currentSize--;
		queue<int>qu = q1;
		q1 = q2;
		q2 = qu;
	}

	int top(){
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return -1;
		}

		while(q1.size()!= 1 ){
			q2.push(q1.front());
			q1.pop();
		}

		int x = q1.front();
		q1.pop();
		q2.push(x);

		queue<int>q = q1;
		q1 = q2;
		q2 = q;

		return x;
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

	while(!s.isEmpty()){
		cout<<s.top()<<endl;
		s.pop();

	}
	
}