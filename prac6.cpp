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

node* insert(node* root,int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d <= root->data){
        root->left = insert(root->left,d);
    }else{
        root->right = insert(root->right,d);
    }
    return root;
}

node* buildBST(){
    node* root = NULL;
    int d;
    cin>>d;
    while(d!=-1){
        root = insert(root,d);
        cin>>d;
    }
    return root;
}
node* search(node* root,int d){
    if(root == NULL) return NULL;
    if(root->data == d) return root;
    if(d <= root->data){
        return search(root->left,d);
    }
    return search(root->right,d);

}

node* deleteInBST(node* root,int key){
    if(root == NULL) return NULL;

    if(key > root->data){
        root->right = deleteInBST(root->right,key);
    }
    else if(key < root->data){
        root->left = deleteInBST(root->left,key);
    }
    else{
        if(root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }else if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        node* temp = root->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        root->data = temp->data;
        root->left = deleteInBST(root->left,root->data);
    }
     return root;
}

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



void printBST(node* root){
    if(root == NULL) return;
    printBST(root->left);
    cout<<root->data<<" ";
    printBST(root->right);

}

void findNodes(node* root,node* &prev,node* &A,node* &B){
    if(root == NULL) return;

    findNodes(root->left,prev,A,B);
    if(prev != NULL && prev->data > root->data){
        B = root;
        if(A == NULL){
            A = prev;
        }else{
            return;
        }
    }
    prev = root;
    findNodes(root->right,prev,A,B);
}

node* constuctBST(int* pre,int* in,int &i,int start,int end){
    if(start>end)return NULL; 

    int rootVal = pre[i];

    int idx = -1;
    for (int j = start; j <= end  ; ++j)
    {
        if(in[j] == pre[i]){
            idx = j;
            break;
        }        
    }
    i = i+1;
    node* root = new node(rootVal);
    root->left = constuctBST(pre,in,i,start,idx-1);
    root->right = constuctBST(pre,in,i,idx+1,end);
    return root;
}

node* inorderPred(node* root,int key){
    if(root == NULL) return NULL;
    node* target = search(root,key);
    if(target == NULL){
        return NULL;
    }

    if(target->left){
        node* temp = target->left;
        while(temp->right != NULL) temp =temp->right;
        return temp; 
    }

    node* ancestor = NULL;
    node* predecessor = root;
    while(predecessor != target){
        if(predecessor->data < target->data){
            ancestor = predecessor;
            predecessor = predecessor->right;
        }else{
            predecessor = predecessor->left;
        }
    } 
    return ancestor;



}

int main(int argc, char const *argv[])
{
    node* root = buildBST();
    // node* root = buildtree();
    printBST(root);
    cout<<endl;
    int x;
    cin>>x;
    node* ans = inorderPred(root,x);
    if(ans){
        cout<<ans->data<<endl;
    }
    else{
        cout<<"NO found"<<endl;
    }

    
    return 0;
}