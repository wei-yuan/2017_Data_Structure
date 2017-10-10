# include <iostream>
# include <vector> 
# include "hw1_class.hpp"

using namespace std;


int main()
{
    // using vector instead of array in C
    //int A[5] = {-1, 5, 3, 1, 7};
    //vector<int> vectorA(A + 1, A + 5); //vector start pos ~ end pos + 1
    int tmpA[5] = {5, 3, 1, 7, 9};
    int tmpB[5] = {8, 2, 6, 4, 10};

    int length = sizeof(tmpA)/sizeof(*tmpA);
    cout << "length: " <<  length << endl;
    //mergesort            
    mergesort_bottom_up(tmpA, length);
    mergesort(tmpB, length);
    
    cout << "After sorted" << endl;
    for(int i=0; i< length; i++)
    {
        cout << "tmpA[" << i << "]: " << tmpA[i] << ", tmpB[" << i << "]: " << tmpB[i] << endl;        
    }
        
    
    return 0;
}