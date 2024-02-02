
#include <iostream>

using std::cout, std::endl;

int main()
{
    /* goal, swap variables without using temp storage, might be faster and more efficvient 
    to use temp but this is more interesting */
     
    int a = 3; // declare and intialize 
    int b = 5;
    a = a + b; // a = a + b
    b = a - b; // b = a - b = (a + b) - b = original a 
    a = a - b; // a = (a + b) - b = (a + b) - original a = original b
    
    cout << a << " " << b << endl; // display output 

    return 0;
}