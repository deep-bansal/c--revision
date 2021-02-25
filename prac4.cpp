#include <bits/stdc++.h>
using namespace std;
class Stack
{
  vector<int>v;
  int minimum;
public:
  bool isEmpty(){
    if(v.size() == 0){
      return true;
    }
    return false;
  }

  void push(int num){
    if(isEmpty()){
      minimum =num;
      v.push_back(num);
    }
    else if (num < minimum){
      v.push_back(2*num -minimum);
      minimum = num;
    }
   else{
     v.push_back(num);
   }
  }

  int top(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return 0;
    }

    int top = v[v.size()-1];
    if(top<minimum){
      top = minimum;
    }
    return top;
  }

  void pop(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return;
    }

    int topEle = v[v.size()-1];
    if(topEle<minimum){
      minimum = 2*minimum -topEle;
    }
    v.pop_back();

  }
  int getMin(){
    return minimum;
  }

  
};
int main(int argc, char const *argv[])
{
  Stack st;

  st.push(2);

  st.push(3);

  st.push(4);

  st.push(1);

  st.push(5);

  st.push(-1);

  st.push(4);

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  cout << st.top() << " " << st.getMin() << endl;

  st.pop();

  return 0;
}