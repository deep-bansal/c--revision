#include <bits/stdc++.h>
using namespace std;

set<vector<int> >s;
void helper(vector<int>nums,int sum,int target,vector<int>v,int j){
    if(sum == target && v.size() == 4){
        s.insert(v);
        v.pop_back();
        return;            
    }
    if(v.size() == 4){
        v.pop_back();
        return;
    }
    
    for(int k=j;k<nums.size();k++){
        v.push_back(nums[k]);
        if(v.size()+(nums.size()-k-1)>=4)
        helper(nums,sum+nums[k],target,v,k+1);
        v.pop_back();
    }
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> > ans;
    if(nums.size()<4) return ans;
    for(int i=0;i<=nums.size()-4;i++){
        vector<int>v;
        v.push_back(nums[i]);
        helper(nums,nums[i],target,v,i+1);
        v.pop_back();
    }
    for(auto x:s){
        ans.push_back(x);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>z = {-500,-481,-480,-469,-437,-423,
        -408,-403};
    int target = 2139;

	vector<vector<int>> ans = fourSum(z,target);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

	return 0;
}