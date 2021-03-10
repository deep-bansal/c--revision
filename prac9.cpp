#include<bits/stdc++.h>
using namespace std;

   int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int start = 0,end = 0;
        int count =0,maxCount = 0,idx = -1;
        while(end<customers.size()){
            
            if(grumpy[end] == 0){
                count += customers[end];  
                end++;
            }            
            else if(grumpy[end] == 1 && customers[end] == 0){

                end++;
                continue;
            }
            else if(grumpy[end] == 1 && customers[end] > 0 && X>0){
                idx = end;
                while(X>0 && end < customers.size()){
                    count += customers[end];
                    X--;
                    end++;
                }

            
            }
            else if (grumpy[end] == 1 && customers[end] > 0 && X == 0){
                maxCount = max(maxCount,count);
                
                while(start <= idx){
                    if(grumpy[start] == 1){
                        count -= customers[start];
                        start++;
                    }
                }
                  X = X+1;              
                
            }
            else if (grumpy[end] == 1 && customers[end] == 0 && X == 0){
                end++;                
            }
            maxCount =max(maxCount,count);
        
        }       
        return maxCount;
        
    }

 int main(int argc, char const *argv[])
 {
 	vector<int> v ={1,0,1,3,2,1,7,5};
 	vector<int> v2 = {0,1,0,1,0,1,0,1};
 	cout<<maxSatisfied(v,v2,3);
 	
 	return 0;
 }