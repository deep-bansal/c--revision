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

node* buildTree(){
    int d;
    cin>>d;
    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void printTree(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
}

int countNodes(node* root){
    if(root == NULL) return 0;
    int count  = 1 + countNodes(root->left) + countNodes(root->right);
    return count;
}

int height(node* root){
    if(root == NULL) return -1;
    if(root->left == NULL and root->right == NULL) return 0;
    int h = 1 + max(height(root->left),height(root->right));
    return h;
}

void bfs(node* root){
    if(root == NULL) return;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1){
        if(q.front() != NULL){
            cout<<q.front()->data<<" ";
            if(q.front()->left){
            q.push(q.front()->left);
        }
        if(q.front()->right){
            q.push(q.front()->right);
        }

        }else{
            cout<<endl;;
            q.push(NULL);
        }
        q.pop();
    }
    cout<<endl;
}

int diameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int owndiameter=height(root->left)+height(root->right)+2;
    int leftdiameter=diameter(root->left);
    int rightdiameter=diameter(root->right);
    return max(owndiameter,max(leftdiameter,rightdiameter));
}

class Pair
{
public:
    int height;
    int diameter;    
};

Pair diameterOpt(node* root){
    Pair P;
    if(root == NULL){
        P.height = -1;
        P.diameter = 0;
        return P;
    }
    if(root->left == NULL && root->right == NULL){
        P.height = 0;
        P.diameter = 0;
        return P;
    }
    Pair Left = diameterOpt(root->left);
    Pair Right = diameterOpt(root->right);
    P.height = max(Left.height,Right.height)+1;
    int owndiameter = Left.height + Right.height +2;
    P.diameter = max(Left.diameter,max(Right.diameter,owndiameter));
    return P;
}


int main(int argc, char const *argv[])
{
    node* root = buildTree();
    printTree(root);
    cout<<endl;
    // bfs(root);
    // cout<<diameter(root)<<endl;
    // Pair ans  = diameterOpt(root);
    // cout<<ans.diameter<<endl;
    return 0;
}