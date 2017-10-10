# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>

using namespace std;

// You can try reference and compare to other method
class list
{
public:
    list();
    ~list();    
    //friend function
    void merge(int arrayA[], int arrayB[])
    {
        
    }
};

class poly
{
public:
    poly();
    ~poly();
    int add(int,int);
};

class spmatrix
{
public:
    spmatrix();
    ~spmatrix();
    int mul(int,int);
};
# endif