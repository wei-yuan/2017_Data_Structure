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
    std::vector<int> _list_1d_array;
    std::vector< std::vector<int> > _list_2d_array;

public:    
    //constructor & destructor
    List() { _list_1d_array.resize(1); }
    List(std::vector<int> & input_1d_array)
    {
        _list_1d_array = input_1d_array;
    }
    List(std::vector< std::vector<int> > & input_2d_array)
    {
        _list_2d_array = input_2d_array;
    }

    // function
    void print_poly(std::vector< std::vector<int> > & input_2d_array)
    {
        //size_t row, col;
        for(size_t row = 0; row < input_2d_array.size(); row++)
            for(size_t col = 0; col < input_2d_array[row].size(); col++)
                std::cout << "list_2d_array[" << row << "][" << col << "]: " << input_2d_array[row][col] <<  std::endl;
    }

    //common operation, merge two list
    int merge(int num1, int num2)
    {
        std::cout << "num1 + num2 =" << num1 + num2 << std::endl;
        return num1 + num2;
    }
};

class Poly : public List
{
    //private data member, allow 2-Dimensional data of vector 
    std::vector<int> _poly_1d_array;
    std::vector< std::vector<int> > _poly_2d_array;

public:
    Poly(std::vector< std::vector<int> > & input_2d_array)
    {
        _poly_2d_array = input_2d_array;
    }

};

# endif