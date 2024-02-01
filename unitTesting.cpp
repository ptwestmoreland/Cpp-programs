/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cassert>
using namespace std;

int add(int a, int b){
    return a + b;
}

int main()
{
    // unit testing add 
    
    // nested for loops to check varying inputs 
    for(int i = 0; i <= 4; ++i){
        for(int j = 0; j < 3; ++j){
            int actual = i + j;
            int expected = add(i,j);
            cout << "Expected: " << expected << " Actual: " << actual << endl;
            if(actual != expected){
                cout << "Error at (a,b) = " << "(" << i << "," << j << ")" << endl;
            }
        }
    }
     assert(add(0,0) == 0);
     assert(add(10,0) == 10);
     assert(add(0,8) == 8); 
     
    return 0;
}