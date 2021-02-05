#include<bits/stdc++.h>
using namespace std;

int arr[] = {2,3,5,7,11,13,17,19,23,29};

int main(int argc, char const *argv[])
{   
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<string>v;
    int z = sizeof(arr)/sizeof(int);
    for (int i = 0; i < s.length(); ++i)
    {
        for (int j = 0; j <= s.length(); ++j)
        {
            int x;
            if(s.substr(i,j) != ""){
                x = stoi(s.substr(i,j));

            }
            if(x != 0 && x != 1 ){
                bool notDivisible = true;
                for (int l = 0; l < z; ++l)
                {
                    if(x == arr[l]){
                        break;
                    }
                    if(x % arr[l] == 0){
                        notDivisible = false;
                        break;
                    }
                }
                if(notDivisible == true){
                   
                        v.push_back(s.substr(i,j));
                    
                    
                }

            }

        }
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size(); ++i)
     {
         cout<<v[i]<<endl;
     } 
      int count  = 0;

   for (int i = 0; i < v.size() ; ++i)
   {
       for (int j = i+1; j < v.size() ; ++j)
       {
          size_t found = v[i].find(v[j]);
          cout<<v[i]<<"    "<<found<<endl;
          // size_t found2  = v[j].find(v[i]);
          //  if(found != string::npos and found2 != string::npos ) {
          //   count++;

          //  }
       }
   }
   cout<<count<<endl;


    return 0;
}