#include<bits/stdc++.h>
using namespace std;

 
int main()
{
    int q;
    cin>>q;
    stack<int>st;
    while(q--){
        int num;
        cin>>num;
        if(num == 2){
            int price;
            cin>>price;
            st.push(price);
        }

        else if(num == 1){
            if(st.empty()){
                cout<<"No Code"<<endl;
            }
            else{
                cout<<st.top()<<endl;
                st.pop();
            }
        }
    }

    return 0;
}