#include <bits/stdc++.h>
using namespace std;

queue<char> firstUnique(string str) {
    queue<char>q;
    int freq[26] = {0};


    for (int i = 0; i < str.length(); i++) {

        freq[str[i] - 'a']++;

        if (freq[str[i] - 'a'] > 1) {
            while (!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
        } else {
            q.push(str[i]);
        }
    }
    return q;

}

int main(int argc, char const *argv[])
{
    string str = "abcadabbxcyxz";
    queue<char>ans = firstUnique(str);
    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();
    }

    return 0;
}