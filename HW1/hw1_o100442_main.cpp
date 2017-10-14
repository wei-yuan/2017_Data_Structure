/*
    C++11 recommended
*/

# include <iostream>
# include <vector> 
# include "hw1_class.hpp"
# include "hw1_mergesort.hpp"

using namespace std;


int main()
{
    // using vector instead of array in C
    int A[5] = {5, 3, 1, 9, 7};
    int B[5] = {8, 2, 10, 6, 4};
    vector<int> vectorA(A + 0, A + 5); //vector start pos ~ end pos + 1
    vector<int> vectorB(B + 0, B + 5);

    int size_of_array = vectorA.size();
    
    cout << "Vector size: " <<  size_of_array << endl;
    cout << "Before sorted" << endl;

    for(int i=0; i< size_of_array; i++)
    {        
        cout << "vectorA[" << i << "]: " << vectorA[i] << ", vectorB[" << i << "]: " << vectorB[i] << endl;        
    }
    
    //mergesort, how about execution time
    mergesort_bottom_up(vectorA, size_of_array);
    mergesort_top_down(vectorB, size_of_array);
    
    cout << "After sorted" << endl;
    cout << "A in Bottom up fashion" << endl;
    cout << "B in Top up fashion" << endl;

    for(int i=0; i< size_of_array; i++)
    {                
        cout << "vectorA[" << i << "]: " << vectorA[i] << ", vectorB[" << i << "]: " << vectorB[i] << endl;        
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