#include<iostream>

using namespace std;

template<typename T>
struct Node {
	T data;
	struct Node<T> *leftChild;
	struct Node<T> *rightChild;
};

//Function to visit nodes in Preorder
template<typename T>
void Preorder(Node<T> *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	cout << root->data << endl; 	// Print data
	Preorder(root->leftChild);       // Visit left subtree
	Preorder(root->rightChild);      // Visit right subtree
}

//Function to visit nodes in Inorder
template<typename T>
void Inorder(Node<T> *root) {	
	if(root == NULL) return;

	Inorder(root->leftChild);        //Visit left subtree
	cout << root->data << endl; //Print data
	Inorder(root->rightChild);       // Visit right subtree
}

//Function to visit nodes in Postorder
template<typename T>
void Postorder(Node<T> *root) {
	if(root == NULL) return;

	Postorder(root->leftChild);      // Visit left subtree
	Postorder(root->rightChild);     // Visit right subtree
	cout << root->data << endl; // Print data
}

// Function to Insert Node in a Binary Search Tree
template<typename T>
Insert(Node<T>* root, T data) {	
	if(root == NULL) {
	//if(!root->valid) {	
		//cout << "root: " << root << endl;	
		root = new Node<T>();
		cout << "root: " << root << endl;
		root->data = data;		
		root->leftChild = root->rightChild = NULL;				
		//cout << "root == NULL" << endl;
		cout << "Insert:" << root->data << endl;
		return root;
	}
	else if(data <= root->data)
	{				
		cout << "data <= root->data" << endl;
		Insert(root->leftChild, data);
	}		
	else
	{		
		cout << "data > root->data" << endl;
		Insert(root->rightChild, data);
	}		
	return root;
}
 
int main() {
	
	Node<int>* root = NULL;

	// Add node manually
	Insert(root, 5);
	cout << "root: " << root << endl;	 
	Insert(root, 1);
	cout << "root: " << root << endl;	
	Insert(root, 6); 
	cout << "root: " << root << endl;	
	Insert(root, 8);
	cout << "root: " << root << endl;	
	Insert(root, 2); 
	cout << "root: " << root << endl;	
	Insert(root, 3);
	cout << "root: " << root << endl;	

	//Print Nodes in Preorder
	cout<<"Preorder: ";
	Preorder(root);
	cout<<"\n";
	//Print Nodes in Inorder
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
	//Print Nodes in Postorder
	cout<<"Postorder: ";
	Postorder(root);
	cout<<"\n";
}