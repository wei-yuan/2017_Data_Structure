# ifndef HW1_CLASS_HPP
# define HW1_CLASS_HPP

# include <iostream>
# include <vector>

using namespace std;

// You can try reference and compare to other method
class List
{
    //friend function or class    
    std::vector<int> _list_array;

public:
    List() { _list_array.resize(10); }

    //constructor & destructor
    List(int len)
    {
        //cout << "Object is being created, length = " << len << endl;
        _list_array.resize(len);
    }

    // function
    void print()
    {
        cout << "length =" << _list_array.size() << endl;
    }

    //common operation
    int merge(int num1, int num2)
    {
        cout << "num1 + num2 =" << num1 + num2 << endl;
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
    

/*    template <typename T>
    void check(T arrayA_term[], T arrayB_term[], int len_array, 
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
*/    
};

# endif