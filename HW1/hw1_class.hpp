# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>

using namespace std;

// You can try reference and compare to other method
class list
{
public:
    //constructor & destructor
    list();
    ~list();    
    //friend function
    friend class poly;
    friend class spmatrix;

    //common operation
    int sum;
    int merge(int num1, int num2)
    {
        return num1 + num2;
    }
};

class poly
{
public:
    poly();
    ~poly();
    // Either array A or B will expand to same size dynamically
    //void expand();
    int add(int num1, int num2); //friend function

    template <typename T>
    int check(T arrayA_term[], T arrayB_term[], int len_array, 
                T arrayA_coef[], T arrayB_coef[]) 
    {
        //array dynamic allocation 
        T *coef_arr = new T[len_array];
        T *term_arr = new T[len_array];

        //inde pointer initialization
        int idxA, idxB;
        idxA = idxB = 0; //when should I initialization of this?

        for(int i=0; i < len_array; i++)
        {
            if(arrayA_term[idxA] == arrayB_term[idxB]){
                term_arr[i] = arrayA_coef[idxA];    //change to friend add()
                coef_arr[i] = arrayA_coef[idxA] + arrayB_coef[idxB];  //change to friend add()
                idxA++; idxB++;
            }                
            else if( arrayA_term[idxA] > arrayB_term[idxB])
            {
                term_arr[i] = arrayB_term[idxB];  //change to friend add()
                coef_arr[i] = arrayB_coef[idxB];  //change to friend add()                
                idxB++;
            }
            else
            {
                term_arr[i] = arrayA_term[idxA];  //change to friend add()
                coef_arr[i] = arrayA_coef[idxA];  //change to friend add()                
                idxA++;
            }
        }
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