#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = nullptr;
	return temp;
}

bool isLeaf(Node* node){
if(node->left == NULL && node->right==NULL){
	return true;
}
return false;
}

void addLeftBound(Node * root, vector<int>& ans){
//Go left left and no left then right but again check from left
root = root->left;
while(root!=NULL){
	if(!isLeaf(root)) ans.push_back(root->data);
	if(root->left !=NULL) root = root->left;
	else root = root->right;
}
}

void addRightBound(Node * root, vector<int>& ans){
//Go right right and no right then left but again check from right
root = root->right;
//As we need the reverse of this for Anticlockwise
stack<int> stk;
while(root!=NULL){
	if(!isLeaf(root)) stk.push(root->data);
	if(root->right !=NULL) root = root->right;
	else root = root->left;
}
while(!stk.empty()){
	ans.push_back(stk.top());
	stk.pop();
}
}

//its kind of inorder
void addLeaves(Node * root, vector<int>& ans){
if(root==NULL){
	return;
}
if(isLeaf(root)){
	ans.push_back(root->data); //just store leaf nodes
	return;
}
addLeaves(root->left,ans);
addLeaves(root->right,ans);
}

vector <int> boundary(Node *root)
{
//Your code here
vector<int> ans;
if(root==NULL) return ans;
if(!isLeaf(root)) ans.push_back(root->data); // if leaf then its done by addLeaf
addLeftBound(root,ans);
addLeaves(root,ans);
addRightBound(root,ans);

return ans;

}

int main()
{
	// Let us construct the tree given in the above diagram
	Node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);

	vector<int>ans = boundary(root);
	for(int v : ans){
		cout<<v<<" ";
	}
	cout<<"\n";

	return 0;
}
