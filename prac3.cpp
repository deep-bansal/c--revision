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

int replaceWithSumDesc(node* &root){
    if(root == NULL) return 0;
    int leftData=0,rightData=0;
    if(root->left) leftData = replaceWithSumDesc(root->left);
    if(root->right) rightData = replaceWithSumDesc(root->right);

    root->data += leftData + rightData;

    return root->data;
}
void mirror(node* root){
    if(root == NULL) return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
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

// void leftViewPrint(node* root) {
//     queue<node*> q;
//     q.push(root);
//     q.push(NULL);
//     cout<<q.front()->data<<" ";
//     while (q.size() > 1) {
//         node* front = q.front();
//         if (front == NULL) {
//             q.pop();
//             cout<<q.front()->data<<" ";
//             q.push(NULL);
//             continue;
//         }
//         else {
//             if (front->left) {
//                 q.push(front->left);
//             }
//             if (front->right) {
//                 q.push(front->right);
//             }
//         }
//         q.pop();
//     }
//     cout<<endl;
// }

void leftView(node* root,int level,int &maxLevel){
    if(root == NULL) return;
    if(level>maxLevel){
        maxLevel = level;
        cout<<root->data<<" ";
    }
    leftView(root->left,level+1,maxLevel);
    leftView(root->right,level+1,maxLevel);
}

class Pair
{
public:
    int height;
    bool isBal;
    
};

Pair isHeightBalanced(node* root){
    Pair P;
    if(root == NULL)
    {
        P.height = -1;
        P.isBal = true;
        return P;
    }

    Pair leftT = isHeightBalanced(root->left);
    Pair rightT = isHeightBalanced(root->right);
    P.height = max(leftT.height,rightT.height) + 1;
    if( abs(leftT.height-rightT.height)<=1 && leftT.isBal && rightT.isBal){
        P.isBal = true;
    }else P.isBal = false;
    
    return P;
}

node* buildHBal(int*arr,int start,int end){
    if(start>end){
        return NULL;
    }
     int mid=start+((end-start)/2);
    node* root = new node(arr[mid]);
    root->left = buildHBal(arr,start,mid-1);
    root->right = buildHBal(arr,mid+1,end);
    return root;
}

int main(int argc, char const *argv[])
{
    // node* root = buildTree();
    // printTree(root);
    // cout<<endl;
    // replaceWithSumDesc(root);
    // bfs(root);
    // cout<<endl;
    // mirror(root);
    // bfs(root);
    // cout<<endl;
    // leftViewPrint(root);
    // int maxLevel = -1;
    // leftView(root,0,maxLevel);

   // Pair ans = isHeightBalanced(root);
   // if(ans.isBal){
   //  cout<<"true"<<endl;
   // }
   // else{
   //  cout<<"false"<<endl;
   // }

    int arr[] = {1,2,3,4,5,6,7,8,9};
    node* root = buildHBal(arr,0,8);
    bfs(root);
    cout<<endl;

   
    return 0;
}