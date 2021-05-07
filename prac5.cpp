#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> >maxHeap;
priority_queue<int>minHeap;

void add(int n){
    if(!maxHeap.empty() && n > maxHeap.top())maxHeap.push(n);
    else minHeap.push(n);

    if(fabs(minHeap.size()-maxHeap.size())>1){
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else{
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
}

float getMedian(){
    if(maxHeap.size()>minHeap.size()) return maxHeap.top();
    else if(maxHeap.size()<minHeap.size()) return minHeap.top();
    else return ((float)maxHeap.top()+minHeap.top())/2;
}


int main(int argc, char const *argv[])
{
    priority_queue<int>pq;
    pq.push(10);
    pq.push(10);
    pq.push(10);
    cout<<pq.size()<<endl;
}