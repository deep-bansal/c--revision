#include<bits/stdc++.h>
using namespace std;

 void removeDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums.erase(nums.begin()+i);
}
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            cout<<nums[i]<<" ";
        }
        
    }

int main()
{
    //code
    vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    removeDuplicates(nums);

    return 0;
}