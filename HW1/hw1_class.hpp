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
    friend class poly;
    friend class spmatrix;

    //common operation
    int sum;
    void merge(int num1, int num2)
    {
        sum = num1 + num2;
    }
};

class poly
{
public:
    poly();
    ~poly();
    int add(int,int)
    {
        merge(int, int);
    }
};

class spmatrix
{
public:
    spmatrix();
    ~spmatrix();
    int mul(int,int);
};
# endif