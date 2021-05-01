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

node* buildtree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();

    return root;
}

void treeToARR(node*root,node* arr[],int i){
    if(root == NULL ||(root->left == NULL and root->right == NULL)){
        i--;
        return;
    }
    arr[2*i+1] = root->left;
    arr[2*i+2] = root->right;
    i++;
    treeToARR(root->left,arr,i);
    i++;
    treeToARR(root->right,arr,i);
}

void printTreeFromArr(node* arr[],int &i){
    if(arr[i] == NULL) return;
    cout<<"Parent : "<<arr[i]->data<<endl<<"Childs : ";
    if(arr[2*i+1] == NULL){
        cout<<"NULL ";
    }else{
        cout<<arr[2*i+1]->data<<" ";
    }
    if(arr[2*i+2] == NULL){
        cout<<"NULL "<<endl;
    }else{
        cout<<arr[2*i+2]->data<<endl;
    }
    i++;
    printTreeFromArr(arr,i);
    i++;
    printTreeFromArr(arr,i);


}

int main(int argc, char const *argv[])
{
    vector<int> V1[] ={{1,2,3}, {4,5,6}};
    cout<<V1[0].back()<<endl;
    
    return 0;
}