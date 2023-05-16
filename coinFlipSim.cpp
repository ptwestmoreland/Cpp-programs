/******************************************************************************

This program is designed to simulate a coin flip, it will use the randomly generated numbers 0 and 1 
to represent heads and tails. 

*******************************************************************************/
#include <iostream>
#include<cstdlib>


int main()
{
   srand((unsigned) time(NULL));
    unsigned int flipResult = 0;
    unsigned int numHeads = 0;
    unsigned int numTails = 0;
    unsigned int numFlips = 0;
    std:: cout << "Enter the desired number of coin flips: ";
    std:: cin >> numFlips;
    
    for(unsigned int i = 0; i < numFlips; ++i){
        int random = rand() % 2; // number is even or odd so it has a remainder of 0 or 1 
        if(random == 1){
            numHeads++; // a remainder of 1 represents heads
        }
       /* else{
        Code optimized by not incrementing the variable numTails for each even number randomly generated. Each 
        incrementation would correspond to a seperate R type instruction at the assembly/machine language level and 
         the job can be done with a single R type instruction as it is below 
            numTails++; // a remainder of 0 represents tails
        } */
    } // end for loop
    
    numTails = numFlips - numHeads; // used for optimization, explained above
    
    std:: cout<< "After " << numFlips << " trials the number of heads is " << numHeads << " and the number of tails is " << numTails << std::endl;

    return 0;
}