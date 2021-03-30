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
  int child;
  cin>>child;
  node* root = new node(d);
  if(child == 2){
    root->left = buildTree();
    root->right = buildTree();
  }else if(child == 1){
    root->left = buildTree();
    root->right = NULL;
  }else{
    root->left = NULL;
    root->right = NULL;
  }
  return root;
}

int bfs(node* root,int k) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int sum  = 0;
    k--;
    while (q.size() > 1) {

        node* front = q.front();
        if (front == NULL) {
            q.push(NULL);
            k--;
        }
        else {
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        if(k < 0){
          q.pop();          
          while(q.front() !=NULL){
            sum+=q.front()->data;
            q.pop();
          }
          break;
        }
        q.pop();
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    node* root = buildTree();
    int k;
    cin>>k;
    cout<<bfs(root,k)<<endl;
   
    return 0;
}