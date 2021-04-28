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

node* constructBST(vector<int>v){
	stack<node*>st;
	int i = v.size()-1;
	node* root = new node(v[i]);
	i--;
	st.push(root);
	while(i>=0){
		node* top = st.top();
		if(v[i] > top->data){
			top->right = new node(v[i]);
			st.push(top->right);
		}else{
			while(!st.empty() && st.top()->data > v[i]){
				top = st.top();
				st.pop();
			}
			top->left = new node(v[i]);
			st.push(top->left); 
		}
		i--;
	}
	return root;
}
void printBST(node* root){
	if(root == nullptr){
		return;
	}
	printBST(root->left);
	cout<<root->data<<" ";
	printBST(root->right);
}

int main(int argc, char const *argv[])
{
    vector<int>v;
    for (int i = 0; i < 6; ++i)
    {
    	int d;
    	cin>>d;
    	v.push_back(d);
    }
    node* root = constructBST(v);
    printBST(root);

    return 0;
}