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
    
    for(size_t row=0; row < vectorD.size(); row++)
        for(size_t col=0; col < vectorD[row].size(); col++)
                std::cout << "vectorD[" << row << "][" << col << "]: " << vectorD[row][col] <<  std::endl;
    
    
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
   
    std::cout << "#---List---#" << std::endl;
    List list1(vectorC);
    list1.print_array();
    
    std::cout << "#---Poly---#" << std::endl;
    Poly poly1(vectorD);
    poly1.print_array();
    std::cout << "#---Add()---#" << std::endl;
    poly1.add(vectorD);
    poly1.print_array();
    std::cout << "#---spmatrix---#" << std::endl;
    Spmatrix spmatrix1(vectorE);
    spmatrix1.mul(vectorF);
    spmatrix1.print_array();

    return 0;
}