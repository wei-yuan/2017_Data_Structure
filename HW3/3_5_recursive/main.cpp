#include<iostream>

struct Node 
{
	int data;
	struct Node *leftChild;
	struct Node *rightChild;
};

//Preorder traversal
void Preorder( Node *root) 
{
	if(root == NULL) return;

	std::cout << root->data << std::endl; 
	Preorder(root->leftChild);     // go to left subtree
	Preorder(root->rightChild);    // got to right subtree
}

//Inorder traversal
void Inorder(Node *root) 
{
	if(root == NULL) return;

	Inorder(root->leftChild);       //got to left subtree
	std::cout << root->data << std::endl; 
	Inorder(root->rightChild);      // got to right subtree
}

void Least_Bound(Node *root, int k) 
{
	if(root == NULL) return;
		
	//if k > num in tree, keep update
	if(k < root->data)
	{	
		std::cout << "number L: " << root->data << std::endl; 				
		return;
	}

	Least_Bound(root->leftChild, k);       //got to left subtree	
	std::cout << root->data << std::endl; 
	Least_Bound(root->rightChild, k);      // got to right subtree	
}


// use a global int array to store value in BST
int arr[10] = {};
int Least_Combined(Node *root, int* arr) 
{	
	if(root == NULL) return 0;

	int index = 0;				
	// LHS, got to left subtree
	index += Least_Combined(root->leftChild, arr);       
	// storing data here
	arr[index++] = root->data;
	// RHS, got to right subtree
	index += Least_Combined(root->rightChild, arr + index);    
	
	return index;
}

//Postorder traversal
void Postorder(Node *root) 
{
	if(root == NULL) return;

	Postorder(root->leftChild);    // got to left subtree
	Postorder(root->rightChild);   // got to rightChild subtree
	std::cout << root->data << std::endl; 
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root, int data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->leftChild = root->rightChild = NULL;
		return root;
	}
	else if(data <= root->data)
		root->leftChild = Insert(root->leftChild,data);
	else 
		root->rightChild = Insert(root->rightChild,data);
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
	Least_Bound(root, k);		
	std::cout << std::endl;

	/* 3-7  find the least summation S of two numbers *m and *n in a binary search tree 
	where their summation exceeds a predefined number k */	
	std::cout<<"find the least summation S of two numbers *m and *n: \n";	
	
	int sum = 6;		
	std::cout<<"test sum: " << sum << std::endl;
	int index = 0;	

	// assign arr with -1 to check validility
	for(int i=0; i < 10; i++)
		arr[i] = -1;

	Least_Combined(root, arr); // 0 cuz root node has no parent
	bool find = false;
	for(int i=0; i < 10; i++) // 0~9
	{		
		for(int j=1+i; j <10; j++) 
		{
 			if(sum < arr[i] + arr[j])
			{
				std::cout << "m:" << arr[i] << ", n:" << arr[j]<< ", m+n:" << arr[i]+arr[j] << std::endl; 
				find = true;
				break;
			}
		}

		if(find == true) break;
	}	

	return 0;
}