/*
    C++11 recommended
*/
# include <iostream>
# include <vector> 
# include "hw1_class.hpp"
# include "hw1_mergesort.hpp"

int main()
{
    // using vector instead of array in C++
    // 1-D vector
    std::vector<int> vectorA = {5, 3, 1, 9, 7}; //vector start pos ~ end pos + 1
    std::vector<int> vectorB = {8, 2, 10, 6, 4};
    // 2-D vector    
    std::vector< std::vector<int>> vectorC = {{1,0}, {2,5}};
    std::vector< std::vector<int>> vectorD = {{1,1}, {2,5}};
    std::vector< std::vector<int>> vectorE = {{1,3}, {1,3}, {2,2}};
    std::vector< std::vector<int>> vectorF = {{1,2}, {2,1}, {2,2}};
        
    std::cout << "Before sorted" << std::endl;

    int size_of_array = vectorA.size();

    for(int i=0; i< size_of_array; i++)
    {        
        std::cout << "vectorA[" << i << "]: " << vectorA[i] << ", vectorB[" << i << "]: " << vectorB[i] << std::endl;        
    }

    for(size_t row=0; row < vectorC.size(); row++)
        for(size_t col=0; col < vectorC[row].size(); col++)
            std::cout << "vectorC[" << row << "][" << col << "]: " << vectorC[row][col] <<  std::endl;    
    
    //mergesort, how about execution time
    mergesort_bottom_up(vectorA, size_of_array);
    mergesort_top_down(vectorB, size_of_array);
    
    std::cout << "After sorted" << std::endl;
    std::cout << "A in Bottom up fashion" << std::endl;
    std::cout << "B in Top up fashion" << std::endl;

    for(int i=0; i< size_of_array; i++)
    {                
        std::cout << "vectorA[" << i << "]: " << vectorA[i] << ", vectorB[" << i << "]: " << vectorB[i] << std::endl;        
    }

    // place an array into list class
    std::cout << "#---Class---#" << std::endl;
    // change to OOP style of code    
    std::cout << "#---List---#" << std::endl;
    List list1(vectorC);
    std::cout << list1 << std::endl; //class: std::out version print

    std::cout << "#---Poly---#" << std::endl;
    Polygon<List> poly1(vectorD);
    std::cout << poly << std::endl; //class: std::out version print

    std::cout << "#---add()---#" << std::endl;
    poly1 = poly1 + vectorD;
    poly1 += vectorD;

    poly1.insert(vectorD);
    poly1.push_back(vectorD);

    std::cout << poly << std::endl; //class: std::out version print

    std::cout << "#---spmatrix---#" << std::endl;

    SparseMatrix<List> spmatrix1(vectorE);
    std::cout << "#---mul()---#" << std::endl;
    spmatrix1.mul(vectorF);
    std::cout << sparmatrix1 << std::endl; //class: std::out version print

    return 0;
}