#include "Linked_Lisrt.hpp"
#include <iostream>

using namespace std;

// TODO: template version?

// only for the 1st Node
void initNode(struct Node *head, int intput_data) {
    // New a head of list
    Node init_Node;
    head = &init_Node;
    // Assignment
    head->data = intput_data;
    head->next = NULL;
    cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;
}

// appending
void appendNode(struct Node *head, int n) 
{
    // iterate to last node
    while(head->next != NULL);
    
}

void insertFront(struct Node *head, int inset_num) 
{
    // create new front Node
    struct Node* new_front_Node_ptr; 
    new_front_Node_ptr->data = inset_num;
    new_front_Node_ptr->next = head;
    // head pointer point to new front Node
    head = new_front_Node_ptr; 
}
/*
struct Node* searchNode(struct Node *head, int n)
{

}

bool deleteNode()
{
}
*/
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

int main() {
    // pointer to struct
    struct Node* head;
    struct Node* tail;
    // create 3 node
    initNode(head, 1);
    cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;    

    // show list
    display(head);

    return 0;
}