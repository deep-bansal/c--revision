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

void bfs(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1) {
        node* front = q.front();
        if (front == NULL) {
            cout << endl;
            q.push(NULL);
        }
        else {
            cout << front->data << " ";
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        q.pop();
    }
}

bool identical (node* A,node* B){
    if(A== NULL && B == NULL) return true;

    if(A!=NULL && B!=NULL){
        bool leftSubTree = identical(A->left,B->left);
        bool rightSubTree = identical(A->right,B->right);

        if( leftSubTree && rightSubTree){
            return true;
        }
    }
    return false;
}

void printNodesInSub(node* root, int k){
    if(root == NULL || k < 0) return;

    if(k == 0) cout<<root->data<<" ";

    printNodesInSub(root->left,k-1);
    printNodesInSub(root->right,k-1);
}

int printNodesAtDistK(node* root,node* target,int k){
    if(root == NULL){
        return -1;
    }

    if(root == target){
        printNodesInSub(root,k);
        return 0;
    }

    int Dleft = printNodesAtDistK(root->left,target,k);
    if(Dleft != -1){
        if(Dleft+1 == k){
            cout<<root->data<<" ";
        }else{
            printNodesInSub(root->right,k-2-Dleft);
        }
        return Dleft +1;
    }
    int Dright = printNodesAtDistK(root->right,target,k);
    if(Dright != -1){
        if(Dright+1 == k){
            cout<<root->data<<" ";
        }else{
            printNodesInSub(root->left,k-2-Dright);
        }
        return Dright +1;
    }
    return -1;
}

int minDepthLeafNode(node* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;

    int leftMin = 0,rightMin = 0;
    if(root->left){
        leftMin = minDepthLeafNode(root->left);
    }
    if(root->right){
        rightMin = minDepthLeafNode(root->right);
    }

    return min(leftMin,rightMin)+1;
}




int main(int argc, char const *argv[])
{
    node* root = buildTree();
    bfs(root);
    cout<<endl;
    // printNodesAtDistK(root,root->left->left->right,3);
    // cout<<endl;
    // cout<<minDepthLeafNode(root)<<endl;
    cout<<maxSumPath(root)<<endl;

   
    return 0;
}