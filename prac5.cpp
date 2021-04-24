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
    if(d<=root->data){
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

bool isBST(node* root,int minimun,int maximum){
    if(root == NULL){
        return true;
    }

    bool leftBST = isBST(root->left,minimun,root->data);
    bool rightBST = isBST(root->right,root->data,maximum);
    bool selfBST = false;
    if( root->data >= minimun && root->data < maximum) selfBST = true;

    return (leftBST && rightBST && selfBST);
}

class nodeHelper
{
public:
    bool isBST;
    int maximum;
    int minimun;
    int size;
    nodeHelper(){
        isBST = true;
        maximum = INT_MIN;
        minimun = INT_MAX;
        size = 0;
    }
    
};

nodeHelper largestBST(node* root){
    if(root == NULL) return nodeHelper();

    nodeHelper leftT = largestBST(root->left);
    nodeHelper rightT = largestBST(root->right);

    nodeHelper curr;

    if(leftT.maximum<= root->data && rightT.minimun > root->data 
        && leftT.isBST && rightT.isBST){
        curr.isBST = true;
        curr.maximum = max(root->data,rightT.maximum);
        curr.minimun = min(root->data,leftT.minimun);
        curr.size = leftT.size + rightT.size + 1;
    }else{
        curr.isBST = false;
        curr.size = max(leftT.size,rightT.size);
    }
    return curr;
}

void printBST(node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    printBST(root->left);
    printBST(root->right);

}

node* inorderSuccessor(node* root,int key){
    node* target = search(root,key);
    if(target == NULL) return NULL;

    if(target->right != NULL){
        node* temp = target->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }else{

        node* ancestor = NULL;
        node* successor = root;
        while(successor != target){
            if(successor->data > target->data){
                ancestor = successor;
                successor = successor->left;
            }else{
                successor = successor->right;
            }
        }
        return ancestor;
    }


}

int main(int argc, char const *argv[])
{
    node* root = buildBST();
    // node* root = buildtree();
    printBST(root);
    cout<<endl;
    // if(isBST(root,INT_MIN,INT_MAX)){
    //     cout<<"Yes it is a BST"<<endl;
    // }else{
    //     cout<<"No it is not a BST"<<endl;
    // }

    // nodeHelper ans = largestBST(root);
    // cout<<ans.size<<endl;
    cout<<inorderSuccessor(root,9)->data<<endl;


    
    return 0;
}