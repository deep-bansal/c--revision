#include <bits/stdc++.h>

using namespace std;
#define ll long long int

long long int primearray[100000] = {0} ;

void prime_seive(ll *p,ll N ){

   p[1]= p[0] = 0 ;
    p[2]=1;

    for(ll i=3 ;i<=N ;i+=2){
        p[i] = 1 ;
    }

    for(ll i=3 ;i<=N ; i+=2){
        if(p[i]==1){
            for(ll j=i*i ; j<=N ; j=j+2*i){
                p[j]=0;
            }
        }
    }
}	

void printStack(stack<int>&st){

	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
}


void playingwithcards (int q,stack<int>st,int iteration){

	if(iteration>q){

		return;
	}

	stack<int>A;
	stack<int>B;
	int prime = primearray[iteration];

	while(!st.empty()){
		if(st.top() % prime == 0){
			B.push(st.top());
		}else{
			A.push(st.top());
		}
		st.pop();
	}

	printStack(B);	
	playingwithcards(q,A,iteration+1);
	printStack(A);


}

int main()

{
    int N=100000;
	ll p[N] = {0} ;
    prime_seive(p,N) ;
	for(long long int i=1 ,k=1 ; i<=N && k<=N ; i++)
    {
		if(p[i]==1)
		{
			primearray[k]=i ;
			k++ ;
		}
	}

	// for(int i=0;i<5;i++){
	// 	cout<<primearray[i]<<" ";
	// }

  int n,q;
  cin>>n>>q;
  stack<int> A0;
  for(int i=0;i<n;i++)
  {
      int k;
      cin>>k;
      A0.push(k);
  }

  playingwithcards(q,A0,1);


    return 0;
}