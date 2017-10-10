# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>
# include <vector> 

using namespace std;

// You should try template in your code
/**/
class list
{
public:
    list();
    ~list();
    int split(int,int);    
    int compare(int,int);
    int merge(int,int);
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

// Sorting array with random number inside
// Odd & Even number of array size should be considered
// try iterator instead of recursive way
// In bottom up fashion

template <typename T>
// combime array[low, mid-1], array[mid, high]
void _merge(T rand_arr[], int low, int mid, int high)  //vector<T> & rand_vecl: reference vector
{
    //array dynamic allocation 
    T *vec_ptr = new T[high - low + 1];
    
    //copy to dynamic allocated  array 
    for(int i=low; i<= high; i++)
        vec_ptr[i-low] = rand_arr[i]; // i-low: make sure T[] start from zero        
    
    for(int i=low; i<= high; i++)
        cout << "vec_ptr[" << i << "]: " << vec_ptr[i] << endl;

    int i = low, j = mid + 1; // two pointer point two left & right array with number inside

    for(int k = low; k<= high; k++)
    {
        if(i > mid) //end of left array
        {
            rand_arr[k] = vec_ptr[j-low]; j++;
        }            
        else if(j > high) //end of right array    
        {
            rand_arr[k] = vec_ptr[i-low]; i++;
        }            
        else if(vec_ptr[i] < vec_ptr[j])
        {
            rand_arr[k] = vec_ptr[i-low]; i++;
        }
        else
        {
            rand_arr[k] = vec_ptr[j-low]; j++;
        }            
    }

    for(int k = low; k<= high; k++)
    {
        cout << "rand_arr[" << k << "]: " << rand_arr[k] << endl;
    }

    //garbage collection
    delete [] vec_ptr;
}

template <typename T>
void _mergesort(T rand_arr[], int low, int high)
{
    int mid = (low + high) / 2;
    _mergesort(rand_arr, low, mid);
    _mergesort(rand_arr, mid+1 , high);
}

template <typename T>
void mergesort(T rand_arr[], int num_element)
{
    _mergesort(rand_arr, 0, num_element-1);
}

template <typename T>
void mergesort_bottom_up(T rand_arr[], int num_element)
{   
    // interval size control
    for(int size = 1; size < num_element; size *= 2)
    {       
        cout << "size: " << size << endl;             
        // over vector iteration
        for(int i = 0; i < num_element - size; i += size*2)
        {
            cout << "i: " << i << endl;            
            if( rand_arr[ i + size - 1 ] > rand_arr[ i + size ] )
                _merge(rand_arr, i, i+size-1, min( i+size*2-1, num_element-1) ); //arr, low, mid, high
        }
    }
}

# endif