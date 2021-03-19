#include<bits/stdc++.h>
using namespace std;

void get(int*x){
    if(*x == 5){
        return;
    }
    get(x-1);
    while(*x != 11){
    x = x+1;    
    }
    
}

int main(int argc, char const *argv[])
{
    int x = 10;
    get(&x);
    cout<<x<<endl;
    return 0;
}