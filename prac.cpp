#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    
    int a, b, i, j, flag;
 
    
    
   a = 1;
    
    cin >> b;
 
  
    for (i = a; i <= b; i++) {
        if (i == 1 || i == 0)
            continue;

        flag = 1;
 
        for (j = 2; j <= i / 2; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
 
        if (flag == 1)
            cout << i << " ";
    }
    cout<<endl;
 
    return 0;
}