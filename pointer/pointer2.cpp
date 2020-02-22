#include <iostream>
using namespace std;

//Compiler version g++ 6.3.0

int main()
{

  int value [] { 78, 79, 80,81 };
    int *ptr;
    ptr = value;
 
    std::cout << *ptr << '\n';
    std::cout << *(ptr+1) << '\n';
    std::cout << *(ptr+2) << '\n';
    std::cout << *(ptr+3) << '\n';
 
    return 0;

}