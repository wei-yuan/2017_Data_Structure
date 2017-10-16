# ifndef HW1_MERGESORT_HPP
# define HW1_MERGESORT_HPP

# include <iostream>
# include <vector> 

// Sorting vector with random number inside
// Odd & Even number of vector size should be considered

// ## In bottom up fashion ##
template <typename T>
// combime vector[low, mid-1], vector[mid, high]
void _merge(std::vector<T> & rand_arr, int low, int mid, int high)  //vector<T> & rand_vecl: reference vector
{
    // vector initilazation
    std::vector<T> _alloc_arr;
    
    //copy to vector
    for(int i=low; i<= high; i++){       
        _alloc_arr.push_back(i);         // Before assignmengt, it needs to create new element to void vector
        _alloc_arr[i-low] = rand_arr[i]; // i-low: make sure vector index start from zero
    }
    
    int i = low, j = mid + 1; // two pointer point two left & right vector with number inside

    for(int k = low; k<= high; k++)
    {
        if(i > mid) //end of left array
        {
            rand_arr[k] = _alloc_arr[j-low]; j++;
        }
        else if(j > high) //end of right array    
        {
            rand_arr[k] = _alloc_arr[i-low]; i++;
        }            
        else if(_alloc_arr[i] < _alloc_arr[j])
        {
            rand_arr[k] = _alloc_arr[i-low]; i++;
        }
        else
        {
            rand_arr[k] = _alloc_arr[j-low]; j++;
        }            
    }
}

template <typename T>
void mergesort_bottom_up(std::vector<T> & rand_arr, int num_element)
{   
    // interval size control
    for(int size = 1; size < num_element; size *= 2)
    {      
        /*GDB*/ 
        //cout << "size: " << size << endl;             
        // over vector iteration
        for(int i = 0; i <= num_element - size; i += size*2)
        {
            /*GDB*/ 
            //cout << "i: " << i << endl;            
            if( rand_arr[ i + size - 1 ] > rand_arr[ i + size ] )
                _merge(rand_arr, i, i+size-1, std::min( i+size*2-1, num_element-1) ); //arr, low, mid, high
        }
        
        /*GDB*/
        /*for(int k = 0; k < 5; k++)
        {
            std::cout << "rand_arr[" << k << "]: " << rand_arr[k] << std::endl;
        }*/    
    }
}

// ## In Top down fashion ##
template <typename T>
void _mergesort_divide(std::vector<T> & rand_arr, int low, int high)
{
    //recursion end condition: only one element left, left this stack
    if (low == high) return;

    int mid = (low + high) / 2;    

    _mergesort_divide(rand_arr, low, mid);
    _mergesort_divide(rand_arr, mid+1 , high);

    //Do not use "if(rand_arr[low] > rand_arr[high])"
    // -> it will be wrong when dealing with array with odd number positions
    if(rand_arr[mid] > rand_arr[mid+1]) 
        _merge(rand_arr, low, mid, high);
}

template <typename T>
void mergesort_top_down(std::vector<T> & rand_arr, int num_element)
{
    _mergesort_divide(rand_arr, 0, num_element-1);
}

# endif