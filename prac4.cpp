#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Pair{
public:
    bool leftP;
    bool rightP;
    Pair(){
        leftP = false;
        rightP = false;
    }    
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        stack<pair<TreeNode*,Pair>>st;
        Pair p;
        st.push(make_pair(root,p));
        while(!st.empty()){
            pair top = st.top();
            if((top.first)->left!= NULL && !top.second.leftP){
                Pair p1;
                top.second.leftP = true;
                st.push(make_pair((top.first)->left,p1));
            }else{
                if((top.first)->right!=NULL && !top.second.rightP){
                    Pair p2;
                    top.second.rightP = true;
                    st.push(make_pair((top.first)->right,p2));
                }else{
                    st.pop();
                    ans.push_back((top.first)->val);
                }
            }
        }
        
        return ans;
        
    }
};