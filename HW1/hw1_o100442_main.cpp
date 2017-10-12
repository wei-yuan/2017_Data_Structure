/*
    C++11 recommended
*/

# include <iostream>
# include <vector> 
# include <array>
# include "hw1_class.hpp"
# include "hw1_mergesort.hpp"

using namespace std;


int main()
{
    // using vector instead of array in C
    //int A[5] = {-1, 5, 3, 1, 7};
    //vector<int> vectorA(A + 1, A + 5); //vector start pos ~ end pos + 1
    int tmpA[5] = {5, 3, 1, 7, 9};
    int tmpB[5] = {8, 2, 6, 4, 10};

    int size_of_array = sizeof(tmpA)/sizeof(*tmpA);
    
    cout << "Array size: " <<  size_of_array << endl;
    cout << "Before sorted" << endl;

    for(int i=0; i< size_of_array; i++)
    {        
        cout << "tmpA[" << i << "]: " << tmpA[i] << ", tmpB[" << i << "]: " << tmpB[i] << endl;        
    }
    
    //mergesort, how about execution time
    mergesort_bottom_up(tmpA, size_of_array);
    mergesort_top_down(tmpB, size_of_array);
    
    cout << "After sorted" << endl;
    cout << "tmpA in Bottom up fashion" << endl;
    cout << "tmpB in Top up fashion" << endl;

    for(int i=0; i< size_of_array; i++)
    {                
        cout << "tmpA[" << i << "]: " << tmpA[i] << ", tmpB[" << i << "]: " << tmpB[i] << endl;        
    }

    // place an array into list class
    cout << "#---Class---#" << endl;
    
/*    list list1(5);
    list1.Print();
    int testmerge = list1.Merge(1,2);
    cout <<"testmerge= " << testmerge << endl;
*/    

    return 0;
}