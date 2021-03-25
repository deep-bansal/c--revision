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
            cout << front->data << ", ";
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

int replaceWithSumDesc(node* &root){
    if(root == NULL) return 0;
    int leftData=0,rightData=0;
    if(root->left) leftData = replaceWithSumDesc(root->left);
    if(root->right) rightData = replaceWithSumDesc(root->right);

    root->data += leftData + rightData;

    return root->data;
}


int main(int argc, char const *argv[])
{
    node* root = buildTree();
    printTree(root);
    cout<<endl;
    // replaceWithSumDesc(root);
    bfs(root);
    cout<<endl;
   
    return 0;
}