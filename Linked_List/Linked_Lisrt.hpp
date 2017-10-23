# ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <iostream>

// struct version
struct struct_node
{
    int data;
    struct_node * s_ptr; // struct pointer
};

// class version
class class_node
{
protected:
    int data;
    class_node * c_ptstructer;
};

# endif