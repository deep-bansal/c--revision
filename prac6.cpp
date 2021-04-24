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
class LinkedList
{
public:
    node* head;
    node* tail;   
};

LinkedList bstToLL(node* root){
    LinkedList ans;
    if(root == NULL){
        ans.head = ans.tail = NULL;
    }
    else if(root->left == NULL and root->right == NULL){
        ans.head = root;
        ans.tail = root;
    }

    else if(root->left == NULL and root->right != NULL){
        LinkedList rightLL = bstToLL(root->right);
        root->right = rightLL.head;
        rightLL.head->left = NULL;
        rightLL.tail->left = NULL;
        ans.head = root;
        ans.tail = rightLL.tail;
    }
    else if(root->left != NULL and root->right == NULL){
        LinkedList leftLL = bstToLL(root->left);
        leftLL.tail->right = root;
        leftLL.head->left = NULL;
        leftLL.tail->left = NULL;
        ans.head = leftLL.head;
        ans.tail = root;
    }else{
        LinkedList leftLL = bstToLL(root->left);
        LinkedList rightLL = bstToLL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;
        rightLL.head->left = NULL;
        rightLL.tail->left = NULL;
        leftLL.head->left = NULL;
        leftLL.tail->left = NULL;
        ans.head = leftLL.head;
        ans.tail = rightLL.tail;
    }
     return ans;

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
    // cout<<inorderSuccessor(root,9)->data<<endl;

   LinkedList ll = bstToLL(root);
     node* l = ll.head;
     while (l) {
        cout << l->data << ", ";
        l = l->right;
     }
     cout << endl;
    
    return 0;
}