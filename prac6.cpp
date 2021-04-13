#include <bits/stdc++.h>
using namespace std;

void longestConsSeq(int* arr, int n) {

  unordered_map<int, int>mp;

  for (int i = 0; i < n; ++i)
  {
    int no = arr[i];
    if (!mp.count(no - 1) and !mp.count(no + 1)) {
      mp[no] = 1;
    } else if (mp.count(no - 1) && mp.count(no + 1)) {
      int len1  = mp[no - 1];
      int len2 = mp[no + 1];
      int streak_len = len1 + 1 + len2;

      mp[no - len1] = streak_len;
      mp[no + len2] = streak_len;
    }
    else if (!mp.count(no - 1) && mp.count(no + 1)) {
      int len = mp[no + 1];
      mp[no] = 1 + len;
      mp[no + len] = 1 + len;
    } else {
      int len = mp[no - 1];
      mp[no] = 1 + len;
      mp[no - len] = 1 + len;
    }
  }
  int ans = 0;
  for(auto m:mp){
    ans = max(ans,m.second);
  }
  cout<<ans<<endl;

}

int main(int argc, char const *argv[])
{
  int arr[] = {8,6,1,2,1,9,3,4,2,6};
  int n = sizeof(arr) / sizeof(n);
  longestConsSeq(arr, n);
  return 0;
}