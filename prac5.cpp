#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    queue<int>dq;
    queue<int>q;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        dq.push(x);
    }
    
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    int totalCount = 0;
    while(!q.empty()){
        if(dq.front() == q.front()){
            totalCount++;
            dq.pop();
            q.pop();
        }
        else{
            while(dq.front() != q.front()){
                dq.push(dq.front());
                dq.pop();
                totalCount++;
            }
        }
    }
    cout<<totalCount<<endl;
    return 0;
}