#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Queue{
    T*arr;
    int rear;
    int front;
    int currSize;
    int totalSize;
public:
    Queue(int defaultSize = 5){
        totalSize = defaultSize;
        arr = new T[totalSize];
        currSize = 0;
        front = 0;
        rear = totalSize -1; // we could keep rear at -1 also
    }

    bool isFull (){
        return currSize == totalSize;
    }


    bool isEmpty (){
        return currSize == 0;
    }

    void push(T ele){
        if(isFull()){
            cout<<"Queue is Full "<<endl;
            return;
        }
        rear = (rear+1)%totalSize;
        arr[rear] = ele;
        currSize++;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }

        front = (front+1)%totalSize;
        currSize--;

    }

    int getFront(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }

        return arr[front];
    }
};

int main(int argc, char const *argv[])
{

    Queue<char> q;
    q.push('2');
    q.push('3');

    for(auto i :q){
        cout<<i<<" ";
    }

    
    return 0;
}