#include<iostream>

using namespace std;

template <class T>
T square(T x)
{
   T result;
   result = x * x;
   return result;
};

int main(){
    int a=0,aa;
    float b=0,bb;
    double c=0,cc;
    cin>>a;
    aa=square(a);
    cout<<a<<" "<<aa<<'\n';
    cin>>b;
    bb=square(b);
    cout<<b<<" "<<bb<<'\n';
    cin>>c;
    cc=square(c);
    cout<<c<<" "<<cc<<'\n';
    return 0;
}