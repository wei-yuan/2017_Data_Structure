/*
    C++11 recommended
*/

# include <iostream>
# include <vector> 
# include "hw1_class.hpp"
# include "hw1_mergesort.hpp"

//using namespace std;


int main()
{
    // using vector instead of array in C++
    // 1-D vector
    int A[5] = {5, 3, 1, 9, 7};
    int B[5] = {8, 2, 10, 6, 4};        
    
    std::vector<int> vectorA(A + 0, A + 5); //vector start pos ~ end pos + 1
    std::vector<int> vectorB(B + 0, B + 5);
    // 2-D vector
    int C_term[2] = {1,0}; // term[]
    int C_coef[2] = {1,1}; // coef[]

    // 2-D vector
    int D_term[2] = {1,1}; // term[]
    int D_coef[2] = {2,5}; // coef[]

    std::vector<int> vectorC1(C_term + 0, C_term + 2);
    std::vector<int> vectorC2(C_coef + 0, C_coef + 2);    
    std::vector< std::vector<int> > vectorC;
    vectorC.push_back(vectorC1);
    vectorC.push_back(vectorC2);

    std::vector<int> vectorD1(D_term + 0, D_term + 2);
    std::vector<int> vectorD2(D_coef + 0, D_coef + 2);    
    std::vector< std::vector<int> > vectorD;
    vectorD.push_back(vectorD1);
    vectorD.push_back(vectorD2);
    
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
    list1.print_poly();
    
    std::cout << "#---Poly---#" << std::endl;
    Poly poly1(vectorD);
    poly1.print_poly();
    std::cout << "#---Add()---#" << std::endl;
    poly1.add(vectorD);
    poly1.print_poly();

    return 0;
}