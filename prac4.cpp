#include <bits/stdc++.h>
using namespace std;

int cuttingCost(vector<int>v){
    int totalcost = 0;
    priority_queue<int,vector<int>,greater<int> >pq(v.begin(),v.end());
    int  y = pq.top();
    pq.pop();
    while(!pq.empty()){
        y += pq.top();
        totalcost += y;
        pq.pop();
    }
    return totalcost;
}

int main(int argc, char const *argv[])
{
    vector<int>v = {2,3,4,5,7};
    cout<<cuttingCost(v)<<endl;
    return 0;
}