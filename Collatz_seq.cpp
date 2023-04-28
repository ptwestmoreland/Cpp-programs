#include <iostream>

using std::cout;
using std::cin;
using std::endl;

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
   // make sure that n is greater than 0, not using try - throw
    while(n <= 0){
        cout << "Please enter a positive integer value: ";
        cin >> n;
    }
    // n should be checked to be an integer/ non floating point value because floats break the program
    cout << "The collatz sequence for " << n << " is:" << endl;
    cout << n << " "; // printing of starting point is done once as opposed to each time the function is called
    int k = collatz(n); // initialize k with first term in sequence
    
    while(k != 1){
        k = collatz(k); // perform the algorithm on each value of k and then compare loop condition
    } // end while
   

    return 0;
}
