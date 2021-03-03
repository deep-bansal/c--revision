#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 0;
        for(int end=0;end<nums.size();end++){
            auto upper = upper_bound(nums.begin(),nums.end(),nums[start]);            
            int x = upper - nums.begin(); 
            if(x != nums.end()){
               if(x - start >2){
                nums.erase(nums.begin()+start+2,nums.begin()+x);
               } 
            }
            auto upper = upper_bound(nums.begin(),nums.end(),nums[start]);            
            int x = upper - nums.begin(); 
            start = x;
            
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{

   vector<int> v = {1,1,1,2,2,3};
   Solution s;
   cout<<s.removeDuplicates(v);

    
    return 0;
}