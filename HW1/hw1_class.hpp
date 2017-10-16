# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>
# include <vector>

//add "using namespace std; wheb there is only one namespace in this header file" 

//template <typename T>
// Reference object and inheritance a class, avoid friend
class List
{
    //private data member, allow 2-Dimensional data of vector 
    //protected ???
    std::vector<int> _1d_array;

protected:
    std::vector< std::vector<int> > _2d_array;

public:    
    //constructor & destructor
    List()
    {
        _1d_array.resize(1);
    }
    List(std::vector<int> & input_1d_array)
    {
        _1d_array = input_1d_array;
    }
    List(std::vector< std::vector<int> > & input_2d_array)
    {
        _2d_array = input_2d_array;
    }

    // function
    // Should I use protected instead of use input argument???
    void print_poly()
    {
        //size_t row, col;
        for(size_t row = 0; row < _2d_array.size(); row++)
            for(size_t col = 0; col < _2d_array[row].size(); col++)
                std::cout << "list_2d_array[" << row << "][" << col << "]: " << _2d_array[row][col] <<  std::endl;
    }

    //common operation, merge two list
    void merge()
    {
              
    }
};

class Poly : public List //inheritance of class List
{    
public:
    //constructor & destructor
    Poly(std::vector< std::vector<int> > & input_2d_array)
    {
        _2d_array = input_2d_array;
    }    
    //use merge() in class List to merge two poly object
    void add(std::vector< std::vector<int> > & input_2d_array)
    {
        int input_size = input_2d_array.size();
        int self_size = _2d_array.size();

        for(int i=0; i < std::max(input_size, self_size); i++)
        {
            if( input_2d_array[0][i] == _2d_array[0][i] )
            {
                //same, merge
            }                
            else if ( input_2d_array[0][i] > _2d_array[0][i] )
            {
                //same, merge
            }
            else
            {
               //same, merge 
            }

        }            

    }
};

class spmatrix : public List
{

};

# endif