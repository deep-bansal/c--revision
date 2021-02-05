#include <bits/stdc++.h>
using namespace std;
int num1,num2,num3;

void triplet(int* a1,int* a2,int* a3,int size1,int size2,int size3){
    
    int i=0,j=0,k=0;
    int maxDiff = INT_MAX;

    while(i<= size1 && j<= size2 && k<= size3){
        // int diff = max(max(abs(num1 - num2),abs(num2 - num3)),abs(num3-num2));
        int minimum = min(a3[k],min(a1[i],a2[j]));
        int maximum = max (max (a1[i],a2[j]),a3[k]);
        int diff = maximum - minimum;
        if(diff <= maxDiff){
            maxDiff = diff;
            num1 = a1[i];
            num2 = a2[j];
            num3  = a3[k];
        }
        if(maxDiff == 0){
            break;
        }
        if(minimum == a1[i]){
            i++;
        }
        else if(minimum == a2[j]){
            j++;
        }
        else{
            k++;
        }


    }

}

int main(int argc, char const *argv[])
{
    int j,k,l;
    cin>>j>>k>>l;
    int a1[j],a2[k],a3[l];
    for (int i = 0; i < j; ++i)
    {
        cin>>a1[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin>>a2[i];
    }
    for (int i = 0; i < l; ++i)
    {
        cin>>a3[i];
    }

    triplet(a1,a2,a3,j,k,l);
    cout<<num1<<num2<<num3;
    return 0;
}