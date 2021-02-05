#include<bits/stdc++.h>
using namespace std;
string searchIn [] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"
};

string keypad[] = { " ", ".+@$","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void checkMatched(string str,int i){
    if(i == 11){
        return;
    }

    string b = searchIn[i];
    int k=0;

    for (int j = 0; j < b.length(); ++j)
    {
        if(b[j] == str[k]){
            k++;
        }        
    }
    if(k == str.length()){
        cout<<b<<endl;
        return;
    }

    checkMatched(str,i+1);
}

void comb(string input,string output){
    if(input.length() == 0){
        checkMatched(output,0);
        return;
    }

    int num = input[0] - '0';
    string ros = input.substr(1);
    string s = keypad[num];

    for (int i = 0; i < s.length(); ++i)
    {
        char ch = s[i];
        comb(ros,output + ch);
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cin >> str;
    comb(str,"");



    return 0;
}