#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  string str[n];
  int q;
  cin>>q;
  cin.ignore();
  for (int i = 0; i < n; ++i)
  {
    getline(cin,str[i]);    
  }

  for (int i = 0; i < q; ++i)
  {
    string query;
    getline(cin,query);
    int x = 0;
    for (int i = 0; i < query.length(); ++i)
    {

      if(query[i] == '.'){
        x+=1;
      }
      else if(query[i] == '~'){
        i=i+1;
        string ros = query.substr(i);
        size_t found = str[x].find(ros);
        if(found != string::npos){
          
          string y = str[x].substr(found+ ros.length()+4);
          int length = y.length();
          
          cout<<y.substr(0,length-2)<<endl;
        }else{
          cout<<"Not Found!"<<endl;
        }
      }
    }
  }
  return 0;
}