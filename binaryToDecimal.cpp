/******************************************************************************

This program converts an n digit binary number into its decimal system integer equivalent, this program 
The numbers that can be represented range from: (0 - 2^n - 1)

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int binToDec(int binArr[], int size){
    unsigned int decimalVal = 0;
    
    for(unsigned int i = 0; i < size; ++i){
        decimalVal = decimalVal + (binArr[i] * pow(2, (size - 1) - i));
        
    }
    return decimalVal;
}

int main()
{
    
  cout << "Enter the number of digits your binary number contains: " << endl;
  double numDigits = 0;
  
  cin >> numDigits;
  // protect against negative and non integer inputs 
  while(numDigits < 0.0){
      cout << "The number of digits must be a whole number: ";
      cin >> numDigits;
  }
  // convert to int 
  unsigned int numDigitsInt = static_cast<int>(numDigits);
  
  int binArr[numDigitsInt]; // create array
  cout << "Enter the binary digits from MSB to LSB: " << endl;
   for(unsigned int i = 0; i < numDigitsInt; ++i){
       
       cin >> binArr[i];
   }
   
   unsigned int decEqv = 0;
   decEqv = binToDec(binArr, numDigits);
   cout << "The decimal equivalent is: " << decEqv << endl;

    return 0;
}