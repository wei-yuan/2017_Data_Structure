#include <iostream>
#include "Linked_Lisrt.hpp"

using namespace std;

// TODO: template version?

// only for the 1st Node
void initNode(struct Node *head, int intput_data) {    
    // Assignment
    head->data = intput_data;
    head->next = NULL;
    cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;
}

void display(struct Node *head) {    
    int i = 0;
    
    if(head != NULL){
        while (1) {        
            cout << "Struct node[" << i << "]= " << head->data << endl;
            if (head->next != NULL)
                head = head->next;
            else
                break;
            i++;        
        }
    }
    else
    {
        cout << "Struct node[" << i << "]= " << head->data << endl;     
    }    
}

// appending
void appendNode(struct Node *head, int n) 
{
    // iterate to last node
    while(head->next != NULL);
    
}

struct Node *insertFront(struct Node *head, int insert_num) 
{
    // create new front Node
    struct Node* new_front_Node_ptr;
    Node new_front_Node;
    new_front_Node_ptr = &new_front_Node;
    new_front_Node_ptr->data = insert_num;
    new_front_Node_ptr->next = head;
    // head pointer point to new front Node
    head = new_front_Node_ptr;
    display(head);
    return head;
}
/*
struct Node* searchNode(struct Node *head, int n)
{

}

bool deleteNode()
{
}
*/


int main() {
    // pointer to struct
    struct Node *head;
    struct Node *tail;
    // create 3 node
    // New a head of list
    Node init_Node;
    head = &init_Node;
    initNode(head, 1);
    cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;
    head = insertFront(head, 0);


    // show list
    display(head);

    return 0;
}