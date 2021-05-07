#include <bits/stdc++.h>
using namespace std;


vector<int>heap;

void upheapify(int idx){
    if(idx == 0) return;
    int parent = (idx-1)/2;
    if(heap[idx] > heap[parent]){
        swap(heap[idx],heap[parent]);
        upheapify(parent);
    }
    return;
}
void downheapify(int idx){
    int leftChild = (2*idx)+1;
    int rightChild = (2*idx)+2;

    if(leftChild >= heap.size() && rightChild >= heap.size()) return;

    int largerChild = idx;
    if(leftChild < heap.size() && heap[leftChild] > heap[largerChild] )
        largerChild = leftChild;

    if(rightChild < heap.size() && heap[rightChild] > heap[largerChild])
        largerChild = rightChild;

    if(largerChild == idx)return;
    swap(heap[idx],heap[largerChild]);
    downheapify(largerChild);
}

void push(int d){
    heap.push_back(d);
    upheapify(heap.size()-1);
}
void popRoot(){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downheapify(0);
}

void popNode(int idx){
    heap[idx] = INT_MAX;
    upheapify(idx);
    popRoot();
}

void displayHeap(){
    for (int i = 0; i < heap.size(); ++i)
    {
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

void buildHeap(){
    for (int i = 0; i < heap.size(); ++i)
    {
        upheapify(i);
    }
}

void buildHeapOpt(){
    for (int i = (heap.size())/2; i >= 0 ; --i)
    {
        downheapify(i);
    }
}

int main()
{
    int n = 7;
    for (int i = 1; i <= n; ++i)
    {
        heap.push_back(i*10);
    }
    displayHeap();
    buildHeapOpt();
    displayHeap();



    return 0;
}