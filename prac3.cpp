#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    unordered_map<string,int>mp;
    pair<string,int>p = make_pair("ABC",30);
    mp.insert(p);
    mp.insert(make_pair("GHI",40));
    mp["ssas"] = 100;

    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    if(mp.find("ABC") != mp.end()){
        cout<<"found "<<mp["ABC"]<<endl;
    }else{
        cout<<"not found"<<endl;
    }

    cout<<mp.count("ABC")<<endl;

    return 0;
}