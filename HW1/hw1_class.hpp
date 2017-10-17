# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>
# include <vector>

//add "using namespace std; wheb there is only one namespace in this header file" 

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
    void print_array()
    {
        //size_t row, col;
        for(size_t row = 0; row < _2d_array.size(); row++)
            for(size_t col = 0; col < _2d_array[row].size(); col++)
                std::cout << "list_2d_array[" << row << "][" << col << "]: " << _2d_array[row][col] <<  std::endl;
    }    
    //common operation, compare two element
    int merge(std::vector< std::vector<int> > & input_2d_array_1,
        std::vector< std::vector<int> > & input_2d_array_2, int row, int col_1, int col_2)
    {
        return input_2d_array_1[row][col_1] += input_2d_array_2[row][col_2];
    }    
};

class Poly : public List //inheritance of class List
{   
protected:
    int row = 1;     
public:    
    // constructor & destructor
    Poly(std::vector< std::vector<int> > & input_2d_array)
    {
        _2d_array = input_2d_array;
    }    
    // use merge() in class List to merge two poly object
    void add(std::vector< std::vector<int> > & input_2d_array)
    {
        std::vector< std::vector<int> > tmp_vec; // size is zero, so it needs init before use it 
        tmp_vec = input_2d_array;

        int input_size = input_2d_array.size();
        int _2d_arr_size = _2d_array.size();
        int idx_input, idx_2d_arr, idx_tmp;
        idx_input = idx_2d_arr = idx_tmp = 0;
                
        for(int i=0; i < std::min(input_size, _2d_arr_size); i++)
        {
            if( input_2d_array[0][idx_input] == _2d_array[0][idx_2d_arr] )
            {
                //term: same, merge                            
                tmp_vec[row][idx_tmp] = merge(tmp_vec, _2d_array, row, idx_tmp, idx_2d_arr);
                // increment index value
                idx_input++; 
                idx_2d_arr++;
                idx_tmp++;
            }                
            else if (input_2d_array[0][idx_input] > _2d_array[0][idx_2d_arr]  ) 
            {
                // term: input array > self                
                for(int j=0; j < row; j++)
                {
                    tmp_vec[j][idx_tmp] = _2d_array[j][idx_2d_arr];
                }
                idx_2d_arr++;
            }
            else
            {
                // term: input array < self
                // insert
                for(int j=0; j < row; j++)
                {
                    tmp_vec[j][idx_tmp] = input_2d_array[j][idx_input];
                }
                // increment 
                idx_input++;
            }            
        }// end for

        if (input_size > _2d_arr_size) // self empty first
        {
            for(int i=idx_input; i < input_size; i++ )    
            {
                for(int j=0; j < row; j++)
                {
                    tmp_vec[j][i] = input_2d_array[j][i];
                }
            }
        }
        else // input empty first
        {
            for(int i=idx_2d_arr; i < _2d_arr_size; i++ )    
            {
                for(int j=0; j < row; j++)
                {
                    tmp_vec[j][i] = _2d_array[j][i];
                }
            }
        }           
        // copy back to vector _2d_array
        _2d_array = tmp_vec;
    }
};

class Spmatrix : public List
{    
public:
    // constructor & destructor
    Spmatrix(std::vector< std::vector<int> > & input_2d_array)
    {
        _2d_array = input_2d_array;
    }
    void mul(std::vector< std::vector<int> > & input_2d_array){
        // C = A * B, transpose B for convenience
        // It only needs to change the idx of reading input_2d_array 
        // from row to col vector
        std::vector<std::vector<int>>  tmp_vec_2d = {{0}, {0}, {0}};

        int input_size = input_2d_array.size();
        int _2d_arr_size = _2d_array.size();
        int cnt, idx;
        cnt = idx = 0;
                
        for(int i=0; i < _2d_arr_size; i++)
        {
            for(int j=0; j < input_size; j++)
            {
                // element wise multiplication
                // transpose here: change 0 -> 1
                // merge operation
                if(input_2d_array[1][j] == _2d_array[0][i]) 
                {
                    tmp_vec_2d[0][idx]  = _2d_array[0][i];
                    tmp_vec_2d[1][idx]  = input_2d_array[0][j];
                    cnt  = input_2d_array[2][i] - 1;
                    // val1 * val2 - > val1 add val2 times                    
                    for(int k=0; k < cnt; k++)
                    {                           
                        // merge(std::vector< std::vector<int> > & input_2d_array_1, 
                        //       std::vector< std::vector<int> > & input_2d_array_2, 
                        //       int row, int col_1, int col_2)                        
                        tmp_vec_2d[2][idx] =  merge(_2d_array, input_2d_array, 2, i, j);                        
                    }
                    idx++;
                }
                else //result is zero, do nothing
                {                    
                }             
            }            
        }
        _2d_array = tmp_vec_2d;
    }
};

# endif