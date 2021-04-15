#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for(auto ch:text){
            mp[ch]++;
        }
        string str = "balloon";
        int count =0;
        while(1){
            for(int i=0;i<str.length();i++){
                if(!mp.count(str[i]))return count;
                mp[str[i]]--;
            }
            count++;
        }
        return count;
        
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    cout<<sol.maxNumberOfBalloons("nlaebolko")<<endl;

    return 0;
}