# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>
# include <vector>

//add "using namespace std; wheb there is only one namespace in this header file" 

//template <typename T>
// Reference object and inheritance a class, avoid friend
class List
{
    //protected data member, allow 2-Dimensional data of vector 
protected:
    std::vector<int> _1d_array;
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
    void merge(std::vector< std::vector<int> > & input_2d_array_1, int row, int idx)
    {
        _2d_array[row][idx] += input_2d_array_1[row][idx];
    }
    //TODO compare(), enum?
};

class Poly : public List //inheritance of class List
{   
protected:
    int row = 1;     
public:    
    //constructor & destructor
    Poly(std::vector< std::vector<int> > & input_2d_array)
    {
        _2d_array = input_2d_array;
    }    
    //use merge() in class List to merge two poly object
    // input list class vector ?
    void add(std::vector< std::vector<int> > & input_2d_array)
    {
        std::vector< std::vector<int> > tmp_array;
        int input_size = input_2d_array.size();
        int self_size = _2d_array.size();
        int idx_input, idx_self;
        idx_input = idx_self = 0;

        std::vector< std::vector<int> >::iterator row_Iter; //between rows
        std::vector<int> ::iterator col_Iter; //between col in same row
        
        for(int i=0; i < std::max(input_size, self_size); i++)
        {
            if( input_2d_array[0][idx_input] == _2d_array[0][idx_self] )
            {
                //term: same, merge
                merge(input_2d_array, row, idx_input);
                for(int j=0; j < row; j++)
                {
                    tmp[j][idx_input] = input_2d_array[j][idx_input];
                }
                // increment index value
                idx_input++; idx_self++;
            }                
            else if ( input_2d_array[0][idx_input] > _2d_array[0][idx_self] ) 
            {
                // term: input array > self
                // only increment self
                idx_self++;
            }
            else
            {
                // term: input array < self
                // insert into self vector
                /* TODO: use insert() of vector
                for(row_Iter = _2d_array.begin(); row_Iter != _2d_array.end(); row++)
                {
                    //_2d_array.insert(row, );
                }*/
                for(int j=0; j < row; j++)
                {
                    tmp[j][idx_input] = input_2d_array[j][idx_input];
                }
                // increment 
                idx_input++;
            }
        }            
    }
};

class spmatrix : public List
{

};

# endif