#include <iostream>
using namespace std;

void GuessNumber(int lowVal, int highVal) 
{
   int midVal;        
   char userAnswer;       
   
   midVal = (highVal + lowVal) / 2;
   
   cout << "Is it " << midVal << "? (l/h/y): "; // lower, higher, yes 
   cin >> userAnswer;
   
   if( (userAnswer != 'l') && (userAnswer != 'h') ) 
   { 
      cout << "Thank you!" << endl;                   
   }
   else 
   {                                           
      if (userAnswer == 'l') 
      {                        
         GuessNumber(lowVal, midVal);                 
      }
      else 
      {                                    
         GuessNumber(midVal + 1, highVal);            
      }
   }
}

int main() 
{
   cout << "Choose a number from 0 to 100." << endl;
   cout << "Answer with:" << endl;
   cout << "   l (your num is lower)" << endl;
   cout << "   h (your num is higher)" << endl;
   cout << "   any other key (guess is right)." << endl;

   GuessNumber(0, 100);
   
   return 0;
}