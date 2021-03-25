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

void inorder(node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}

void postorder(node* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int countNodes(node* root){
	if(root == NULL) return 0;
	int count  = 1 + countNodes(root->left) + countNodes(root->right);
	return count;
}

int sumAllNodes(node* root){
	if(root == NULL) return 0;
	int sum = root->data + sumAllNodes(root->left) + sumAllNodes(root->right);

	return sum;
}

void printKthLevel(node* root,int k){
	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	if(root->left)printKthLevel(root->left,k-1);
	if(root->right)printKthLevel(root->right,k-1);
}

int height(node* root){
	if(root == NULL) return -1;

	int h = 1 + max(height(root->left),height(root->right));
	return h;
}


void printAllLevels(node* root){
	int h  = height(root);

	for (int i = 0; i <= h; ++i)
	{
		printKthLevel(root,i);
		cout<<endl;
	}

}


int main(int argc, char const *argv[])
{
	node* root = buildTree();
	printTree(root);
	cout<<endl;
	// cout<<countNodes(root)<<endl;
	// cout<<sumAllNodes(root)<<endl;
	// inorder(root);
	// cout<<endl;
	// postorder(root);
	// cout<<endl;
	// printKthLevel(root,3);
	// cout<<endl;
	cout<<height(root)<<endl;
	printAllLevels(root);
	return 0;
}