
#include<iostream>

using namespace std;

template<typename T>
struct Node {
	T data;	
	T getData()
    {
        return data;
    }
	struct Node<T> *leftChild;
	struct Node<T> *rightChild;
};

//Function to visit nodes in Preorder
template<typename T>
void Preorder(Node<T> *root) {	
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;	
	cout << "------------------" << endl;
	cout << root->data << endl; 	// Print data
	//cout << root->leftChild << endl;
	Preorder(root->leftChild);       // Visit left subtree
	cout << root->rightChild << endl;
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
Node<T>* Insert(Node<T>* root, T data) {	
	if(root == NULL) {
		cout << "root: " << root << endl;	
		root = new Node<T>();
		cout << "after new root: " << root << endl;
		root->data = data;		
		root->leftChild = root->rightChild = NULL;						
		cout << "Insert:" << root->data << endl;
		//return root;
	}
	else if(data <= root->data)
	{				
		cout << "left" << endl;
		Insert(root->leftChild, data);
	}		
	else
	{		
		cout << "right" << endl;
		Insert(root->rightChild, data);
	}		
	return root;
}
 
int main() {
	
	Node<int>* root = NULL;
	//Node<int>* original = NULL;

	// Add node manually
	root = Insert(root, 5);
	//original = root;
	cout << "main root: " << root << endl;	 
	root = Insert(root, 1);
	cout << "main root: " << root << endl;	
	root = Insert(root, 6); 
	cout << "main root: " << root << endl;	
	/*
	root = Insert(root, 8);
	cout << "main root: " << root << endl;	
	root = Insert(root, 2); 
	cout << "main root: " << root << endl;	
	root = Insert(root, 3);
	cout << "main root: " << root << endl;	
	*/

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