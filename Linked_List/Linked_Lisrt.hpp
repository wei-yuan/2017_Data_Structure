# ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <iostream>

// struct version
struct s_node
{
    int data;
    s_node* s_next; // struct pointer
};

// class version
class c_node
{
protected:
    int data;
    c_node* c_next;
};

# endif