#include <bits/stdc++.h>
using namespace std;

 int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
      int left = 0,right = 0;
        int count =0,maxCount = 0,temp=X;
        while(right<customers.size()){
            if(grumpy[right] == 0){
                count+= customers[right];
                right++;
            }
            else if (grumpy[right] == 1 && customers[right] == 0){
                right++;
            }
            else if(grumpy[right] == 1 && customers[right] > 0 && X > 0){
                left = right;
                while(X!=0 && right<customers.size()){
                    count+=customers[right];
                    right++;
                    X--;
                }
            }
            else if(grumpy[right] == 1 && customers[right] > 0 && X == 0){
                maxCount = max(maxCount,count);
                 if(left < right-temp+1){
                     while(left<right-temp+1){
                         if(grumpy[left] == 1) count -= customers[left];                       
                         X++;
                         left++;
                     }                    
                 }              
            }
            maxCount = max(maxCount,count);
        
        }
        return maxCount;
        
    }

 int main(int argc, char const *argv[])
 {
 	vector<int>cust = {3,8,8,7,1};
 	vector<int>gr = {1,1,1,1,1};
 	cout<<maxSatisfied(cust,gr,3)<<endl;
 	return 0;
 }