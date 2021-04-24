#include <bits/stdc++.h>
using namespace std;

string showLen(string str,string pat){
    unordered_map<char,int>hash_str;
    unordered_map<char,int>hash_pat;

    for (int i = 0; i < pat.length(); ++i)hash_pat[pat[i]]++;

    if(str.length()< pat.length())return "No String";

    int start = 0,end = 0,minLen=INT_MAX,count=0,startidx = -1;

    for (; end < str.length(); ++end)
    {
        if(hash_pat.count(str[end])){
            hash_str[str[end]]++;

            if(hash_str[str[end]] <= hash_pat[str[end]])count++;
        }
        

        if(count == pat.length()){
            while(!hash_pat.count(str[start]) || hash_str[str[start]]>hash_pat[str[start]]){

                if(hash_str[str[start]]>hash_pat[str[start]]){
                    hash_str[str[start]]--;
                }
                start++;
            }
            if(end-start+1<minLen){
                minLen = end-start+1;
                startidx = start;
            }
        }
    }

    if(startidx == -1) return "No String";
    return str.substr(startidx+1,minLen);
}


int main(int argc, char const *argv[])
{
    string str;
    string pat;
    getline(cin,str);
    getline(cin,pat);
    cout<<showLen(str,pat)<<endl;
    return 0;
}