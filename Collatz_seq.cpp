/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int collatz(int n){ // define collatz, 1 integer parameter and an integer return value
    
    if(n % 2 == 0){ // check if argument is even
        int k = n / 2; // perform int division to get next value
        cout << k << " "; // print
        return k; // return to main
    }
    else{
        int k = 3*n + 1; // if integer is odd, multiply it by 3 and add 1
        cout << k << " "; // print
        return k; // return to main
        
    }
    
}

int main()
{
    
    cout << "Enter a number: ";
    int n = 0;
    cin >> n;
    cout << "The collatz sequence for " << n << " is:" << endl;
    cout << n << " "; // printing of starting point is done once as opposed to each time the function is called
    int k = collatz(n); // initialize k with first term in sequence
    
    while(k != 1){
        k = collatz(k); // perform the algorithm on each value of k and then compare loop condition
    }
   

    return 0;
}
