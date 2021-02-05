#include<bits/stdc++.h>
using namespace std;
static int MOD= 10000003;
#define ll long long
int ans = 0;

void stringToInt(string input,int l){
  if(input.length() == 0){
    return;
  }

  int n = input[0] - '0';
  ans += n* pow(10,l);
  

  stringToInt(input.substr(1),l-1);

}

int main(int argc, char const *argv[])
{
  string str;
  cin>>str;
  // cout<<str.length()<<endl;
  stringToInt(str,str.length()-1);
  cout<<ans<<endl;

  return 0;
}