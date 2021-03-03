#include<bits/stdc++.h>
using namespace std;
class Queue
{
	stack<int>s1,s2;
	int currSize;
public:
	Queue(){
		currSize = 0;
	}

	void push(int ele){
		s1.push(ele);
		currSize++;
	}

	bool empty(){
		return currSize == 0;
	}

	void pop(){
		if(s1.empty()){
			cout<<"Queue is Empty"<<endl;
			return;
		}
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		currSize--;
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
	int front(){
		if(s1.empty()){
			cout<<"Queue is Empty"<<endl;
			return -1;
		}

		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
		int x = s2.top();
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		return x;
	}
};
int main(int argc, char const *argv[])
{
	Queue q;
	q.push(2);
	q.push(4);
	q.push(6);
	q.push(7);
	q.push(8);
	q.push(9);

	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}

	
	return 0;
}