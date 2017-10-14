# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>
# include <vector>

//add "using namespace std; wheb there is only one namespace in this header file" 

// Reference object and inheritance a class, avoid friend
class List
{
    // allow 2D vector 
    std::vector<int> _list_array;

public:
    List() { _list_array.resize(10); }

    //constructor & destructor
    List(int len)
    {
        _list_array.resize(len);
    }

    // function
    void print()
    {
        std::cout << "length =" << _list_array.size() << std::endl;
    }

    //common operation, merge two list
    int merge(int num1, int num2)
    {
        std::cout << "num1 + num2 =" << num1 + num2 << std::endl;
        return num1 + num2;
    }
};

class Poly
{
    List list;

public:
    Poly();
    ~Poly();
    // Either array A or B will expand to same size dynamically
    //void expand();
    int add(int num1, int num2) //friend function
    {
        return list.merge(num1, num2);
    }

/*  template <typename T>
    void check() 
    {

    }    
*/    
};

# endif