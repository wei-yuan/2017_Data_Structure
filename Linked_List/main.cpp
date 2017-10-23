#include <iostream>
#include "Linked_Lisrt.hpp"

using namespace std;

// only for the 1st Node
void initSNode(struct s_node *head, int n)
{
    head->data  = n;
    head->s_next = NULL;
}

/*void initCNode(class c_node *head, int n){
    head->data = n;
    head->c_ptr = NULL;
}

// apending
void addNode(struct s_node *head, int n)
{

}

void insertFront()
{
}

struct Node searchNode(struct Node *head, int n)
{

}

bool deleteNode()
{
}*/

void display(struct s_node *head)
{
    while(head != NULL)
    {
        int i = 0;
        cout << "Struct node" << i << "= " << head->data << endl;
        head = head->s_next;
        i++;        
    }
}

int main()
{
    // create 3 node
    s_node snode1;
    s_node snode2;
    s_node snode3;

    struct s_node *head;
    struct s_node *tail;

    snode1.data = 1;
    snode1.data = 2;
    snode1.data = 3;
    
    // linked
    head = &snode1;
    tail = &snode3;
    snode1.s_next = &snode2;
    snode2.s_next = &snode3;
    snode2.s_next = NULL;

    display(head);

    return 0;
}