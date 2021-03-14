#include<bits/stdc++.h>
using namespace std;
 bool checkInclusion(string s1, string s2) {
        int freq[26] ={0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }        
        int start = 0,end = 0;
        for(int i=0;i<s2.length();i++){
            int len = 0;
            while(freq[s2[i]-'a']>0 && i<s2.length()){
                len++;
                i++;                
            }
            if(len == s1.length()){
                return true;
            }
            
        
        }
        return false;
}

int main(int argc, char const *argv[])
{
	string s1 = "adc";
	string s2 = "dfcda";
	if(checkInclusion(s1,s2)){
		cout<<"true";
	}
	return 0;
}