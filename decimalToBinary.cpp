/******************************************************************************

This program converts decimal numbers to unsigned binary numbers through the use of a function with the 
divide by 2 method. Binary number is stored as an array of integers.

*******************************************************************************/
#include <iostream>

void converter(int input, int binArr[32]){
    
    /*  for(unsigned int i = 0; i < 32; ++i){
        binArr[i] = input % 2; // stores back digit remainder (0 or 1) in front of array 
        input = input / 2; // divide input by 2, 0s will be added for remaining bits from front to back if necessary
    } */ 
    // conversion is redone below for higher efficiency 
    // since array is initially populated with all 0s we only need to loop until input / 2 = 0 vs all 32 iterations
    unsigned int i = 0;
    while(input != 0){
        binArr[i] = input % 2; // stores back digit remainder (0 or 1) in front of array
        input /= 2;
        i++;
     } // end conversion/divide by 2 loop
} // end function

int main()
{
    
    int binArr[32] = {0}; // initialize array to 0
    int decNumber = 0;
    std:: cout << "Enter the decimal number that you would like to convert to a 32 bit binary number: ";
    std:: cin >> decNumber;
    
    converter(decNumber, binArr); 
    
    for(unsigned int i = 0; i < 32; ++i){ // display binary number
       std:: cout << binArr[i]; // array is pass by ref so it is altered in function and displayable in main
    }
    std:: cout << std:: endl;
  return 0;
}