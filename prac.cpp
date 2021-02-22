#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Stack
{
	vector<T>v;
public:
	void push(T num){
		v.push_back(num);
	}
	bool isEmpty(){
		if(v.size() == 0){
			return true;
		}
		return false;
	}
	void pop (){
		if(isEmpty()){
			cout<<"Stack already empty"<<endl;
			return;
		}
		v.pop_back();
	}

	T top(){
		if(isEmpty()){
			cout<<"Stack is Empty"<<endl;
			return 0;
		}

		return v[v.size()-1];


	}
	
};

int main(int argc, char const *argv[])
{
	Stack<string> st;
	string str = "(((a+b))(c+d)))";

	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i]=='('){
			st.push("(");
		}
		else if (str[i] == ')'){
			st.pop();
		}
	}

	if (st.isEmpty()){
		cout<<"isBalanced"<<endl;
	}
	else{
		cout<<"not balanced"<<endl;
	}


	return 0;
}