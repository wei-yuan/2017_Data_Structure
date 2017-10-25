#include <iostream>
#include "Linked_Lisrt.hpp"

using namespace std;

// TODO: template version?

// only for the 1st Node
Node *initNode(Node *head, int intput_data) {    
    // New a head of list
    // dynamic allocation in C
    struct Node *init_Node_ptr = (struct Node*) malloc(sizeof(struct Node));
    init_Node_ptr = head;
    // Assignment
    head->data = intput_data;
    head->next = NULL;
    //cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;
    return head;
}

void display(Node *head) {        
    cout << "--- Print List Start---" << endl;
    
    int i = 0;    
    Node* it_ptr = head;

    if(head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    } 
    
    while (it_ptr != NULL) {              
        cout << "Struct node[" << i << "]= " << it_ptr->data << endl;                      
        it_ptr = it_ptr->next;
        i++;        
    }
    cout << "--- Print List End---" << endl;
}

// appending
void appendNode(struct Node *head, int n) 
{
    // iterate to last node
    while(head->next != NULL);
    
}

Node *insertFront(struct Node *head, int insert_num) 
{    
    // create new front Node    
    struct Node new_front_Node;
    struct Node *new_front_Node_ptr = &new_front_Node;
    new_front_Node_ptr->data = insert_num;
    new_front_Node_ptr->next = head;
    // head pointer point to new front Node
    head = new_front_Node_ptr;
    //display(head);
    return head;
}

/*
// Similar to what it does in display
struct Node* searchNode(struct Node *head, int n)
{
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

bool deleteNode()
{
}
*/
void deleteList(struct Node *head)
{    
    while (head != NULL) {                      
        cout << "Delete Struct node= " << head->data << endl;
        // record memory position of next node
        struct Node *current_ptr = (struct Node*) malloc(sizeof(struct Node));
        current_ptr = head;
        head = head->next;
        // delete dynamically allocated Node
        free(current_ptr);        
    }
}


int main() {
    // pointer to struct
    Node *head = NULL;
    Node *tail = NULL;
    // create 3 node
    display(head); 
    head = initNode(head, 1);
    cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;
    display(head);
        
    //head = insertFront(head, 0);    

    // show list
    //display(head);
    // Don't forget free()
    deleteList(head);

    return 0;
}