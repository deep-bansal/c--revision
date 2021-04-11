#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int>v = {1,2,3,4,5,67,11};
    int max_ele = *(max_element(v.begin(),v.end()));
    auto it = find(v.begin(),v.end(),max_ele);
    int i = it - v.begin();
    cout<<max_ele<<" "<<i<<endl;
    return 0;
}