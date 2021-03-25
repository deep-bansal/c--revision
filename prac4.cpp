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
// int i = 0;
// node* buildTreePreandIn(int* pre, int* in,int start,int end){
//     if(start>end){
//         return NULL;
//     }

//     node* root = new node(pre[i]);
//     int idx = -1;
//     for (int k = start; k <= end ; ++k)
//     {
//         if(pre[i] == in[k]){
//             idx = k;
//             break;
//         }
//     }
//     i++;
//     root->left = buildTreePreandIn(pre,in,start,idx-1);
//     root->right = buildTreePreandIn(pre,in,idx+1,end);

//     return root;
// }

// int i = 8;
// node* buildTreePostandIn(int* post,int* in,int start,int end){
//     if(start > end) return NULL;

//     node* root = new node(post[i]);
//     int idx = -1;
//     for(int k= end;k>=start;k--){
//         if(in[k] == post[i]){
//             idx = k;
//             break;
//         }
//     }
//     i--;
//     root->right = buildTreePostandIn(post,in,idx +1,end);
//     root->left = buildTreePostandIn(post,in,start,idx-1);
//     return root;
// }

int i = 0;
node* buildTreePreandPost(int* pre,int* post,int start,int end){
    if(start > end){
        return NULL;
    }

    node* root = new node(pre[i]);
    int idx = -1;
    for(int k = start;k<=end;k++){
        if(pre[k] == post[end-1]){
            idx = k;
            break;
        }
    }
    i++;
    root->left = buildTreePreandPost(pre,post,i,idx-1);
    root->right= buildTreePreandPost(pre,post,idx,end);

    return root;
    
}

int main(int argc, char const *argv[])
{
    // node* root = buildTree();
    // cout<<endl;
    int post[] = {3,5,6,4,2,9,8,7,1};
    int pre[] = {1,2,3,4,5,6,7,8,9};
    // node* root =  buildTreePostandIn(post,in,0,8);   
    node*root = buildTreePreandPost(pre,post,0,8);
    bfs(root);
    cout<<endl;

   
    return 0;
}