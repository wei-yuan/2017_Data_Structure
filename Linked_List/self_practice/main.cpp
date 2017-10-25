#include <iostream>
#include "Linked_Lisrt.hpp"

using namespace std;

// TODO: template version?

// only for the 1st Node
struct Node *initNode(struct Node *head, int intput_data) {    
    // New a head of list
    Node init_Node;
    head = &init_Node;
    // Assignment
    head->data = intput_data;
    head->next = NULL;
    //cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;
    return head;
}

void display(struct Node *head) {        
    if(head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    } 

    int i = 0;
    struct Node it;
    struct Node* it_ptr = &it;
    
    it_ptr->data = head->data;
    it_ptr->next = head->next;

    while (it_ptr != NULL) {              
        cout << "Struct node[" << i << "]= " << it_ptr->data << endl;                      
        it_ptr = it_ptr->next;
        i++;        
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

deleteList(struct Node **head)
{

}
*/

int main() {
    // pointer to struct
    struct Node *head;
    struct Node *tail;
    // create 3 node    
    head = initNode(head, 1);
    display(head);
    head = insertFront(head, 0);
    cout << "Struct node data= " << head->data << ", Next struct node= " << head->next << endl;

    // show list
    //display(head);

    return 0;
}