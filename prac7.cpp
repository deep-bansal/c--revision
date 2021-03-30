#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* levelOrder(){
    int d;
    cin>>d;
    node*root = new node(d);
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        int x,y;
        cin>>x>>y;
        node* front = q.front();
        if(x != -1){
            front->left = new node(x);
            q.push(front->left);
        }else{
            front->left = NULL;
        }
        if(y != -1){
            front->right = new node(y);
            q.push(front->right);   
        }else{
            front->right = NULL;
        }
        q.pop();
    }
    return root;
}

void printBottomView(node* root){
    if(root == NULL){
        return;
    }

    


}


int main(int argc, char const *argv[])
{
    node* root = buildTree();
    printBottomView(root);

   
    return 0;
}