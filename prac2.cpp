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

node* lca(node* root,int A,int B){
    if(root == NULL) return NULL;

    if(root->data == A || root->data == B){
        return root;
    }

    node* leftAns = lca(root->left,A,B);
    node* rightAns = lca(root->right,A,B);
    if(leftAns != NULL && rightAns != NULL){
        return root;
    }else if (leftAns != NULL){
        return leftAns;
    }
    return rightAns;
}


int main(int argc, char const *argv[])
{
    node* root = buildTree();
    bfs(root);
    node* ans = lca(root,7,4);
    if(ans != NULL){
        cout<<ans->data<<endl;
    }
    return 0;
}