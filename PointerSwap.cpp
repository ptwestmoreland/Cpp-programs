/* The purpose of this program is to use a function to swap out the values of two variables
defined in main. It is primarily intended for me to practice working with pointers */

#include <iostream>

//using namespace std;
// swap has pointer paramters so that copies are not made and data items in main can be altered outside of main
void swap1(int *ptr1, int *ptr2){
    int hold = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = hold;
    
}

void swap2(int &a,int &b){
    int hold = a; // hold a value
    a = b; // switch a and b 
    b = hold;
    
    
}

int main()
{
    // define two variables
    
    int a = 5;
    int b = 8;
    
   std:: cout << "The value of a is " << a << " and the value of b is " << b << std::endl;
   
   // create pointers to the variables a and b 
   int *ptra = &a;
   int *ptrb = &b;
   
   swap1(ptra, ptrb);
   
   std::cout << "The value of a is " << a << " and the value of b is " << b << std::endl;
   
   swap2(a, b);
   
   std::cout << "The value of a is " << a << " and the value of b is " << b << std::endl;
   

    return 0;
}
