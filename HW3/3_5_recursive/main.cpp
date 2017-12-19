#include<iostream>
#include "memory.h"

struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

//Preorder traversal
void Preorder( Node *root) 
{
	if(root == NULL) return;

	std::cout << root->data << std::endl; 
	Preorder(root->left);     // go to left subtree
	Preorder(root->right);    // got to right subtree
}

//Inorder traversal
void Inorder(Node *root) 
{
	if(root == NULL) return;

	Inorder(root->left);       //got to left subtree
	std::cout << root->data << std::endl; 
	Inorder(root->right);      // got to right subtree
}

void find_num_Inorder(Node *root, int k) {
	if(root == NULL) return;
		
	//if k > num in tree, keep update
	if(k < root->data)
	{	
		std::cout << "number L: " << root->data << std::endl; 
		memcpy(&k, &root->data, sizeof(int));
		return;
	}

	find_num_Inorder(root->left, k);       //got to left subtree	
	std::cout << root->data << std::endl; 
	find_num_Inorder(root->right, k);      // got to right subtree
}

//Postorder traversal
void Postorder(Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // got to left subtree
	Postorder(root->right);   // got to right subtree
	std::cout << root->data << std::endl; 
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root, int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	Node* root = NULL;
	
	/* 3-5 traversal method */
	// insert data
	root = Insert(root, 5); 
	root = Insert(root, 1);
	root = Insert(root, 6); 
	root = Insert(root, 8); 
	root = Insert(root, 2); 
	root = Insert(root, 3);

	//Print Nodes in Preorder. 
	std::cout<<"Preorder: \n";
	Preorder(root);
	std::cout << std::endl;
	//Print Nodes in Inorder
	std::cout<<"Inorder: \n";
	Inorder(root);
	std::cout << std::endl;
	//Print Nodes in Postorder
	std::cout<<"Postorder: \n";
	Postorder(root);
	std::cout << std::endl;

	/* 3-6 find the least number L that exceeds a predefined number k */
	int k = 7;	
	std::cout<<"find the least number L that exceeds a predefined number k: \n";
	find_num_Inorder(root, k);	

	/* 3-7  find the least summation S of two numbers *m and *n in a binary search tree 
	where their summation exceeds a predefined number k */	
	int l = 5;

	return 0;
}