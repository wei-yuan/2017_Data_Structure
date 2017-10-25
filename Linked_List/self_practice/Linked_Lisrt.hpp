# ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <iostream>

// struct version
struct Node
{
    int data;
    Node* next; // struct pointer
};

// class version
class c_node
{
protected:
    int data;
    c_node* next;
};

# endif