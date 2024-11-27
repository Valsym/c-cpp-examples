#include <iostream>
#include "darray.h"

int main()
{
    //DArray ar1, ar2;
 
    // for(int i = 0;i < 10; ++i)
    //     ar1.push_back(i+1);
 
    //ar1[14] = 7;
    //int v = ar1[14];
    
    // ar2 = ar1;
 
    // std::cout << v << std::endl;
    // std::cout << ar2.size() << " " << ar2.capacity_ar() << std::endl;
    
    // for(int i = 0;i < ar2.size(); ++i)
    //     std::cout << ar2.get_data()[i] << " ";
 
    // return 0;

 
    // ar1[10] = 100;
    // ar1[0] += 2;
    // ar1[2] = 7; ar1[2] *= 3;
    // ar1[3] = 11; ar1[3] %= 4;
    // double v = ar1[14];
 
    // std::cout << v << std::endl;
    
    // for(int i = 0;i < ar1.size(); ++i)
    //     std::cout << ar1.get_data()[i] << " ";
    // std::cout << std::endl;
//+++++++++++++++++++++++++++++++++++++++++++++++++++
  
    /*DArray ar1, ar2, ar3;

    for(int i = 0;i < 10; ++i)
        ar1.push_back(i+1);
    for(int i = 0;i < 5; ++i)
        ar2.push_back(i+15);
    ar1 += ar2;
    for(int i = 0;i < ar1.size(); ++i)
        std::cout << ar1.get_data()[i] << " ";

    std::cout << std::endl;

    ar3 = ar1 + ar2;
    ar1[0] = 9; ar1[0] /= 3;

    for(int i = 0;i < ar1.size(); ++i)
        std::cout << ar1.get_data()[i] << " ";
 
    return 0;*/

  //++++++++++++++++++++++++++++++++++
  // test incremen/decrement
    DArray ar1, ar2;
 
    ar1[10] = 10;
    ar1[3] = 5;
 
    int v1 = ar1[3]--;
    int v2 = ++ar1[10];
 
    std::cout << v1 << " " << ar1[3] << std::endl;
    std::cout << v2 << " " << ar1[10] << std::endl;
 
    for(int i = 0;i < ar1.size();++i)
        std::cout << ar1.get_data()[i] << " ";
 
    return 0;
}
