/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
    int numHeads = 0;
    int numTails = 0;
    char userIn = 'a';
    srand((unsigned) time(NULL)); // seed random
    bool FlipsOccured = false;
    
    while(true){
        cout << "To flip the coin, press y or Y. Any other single character will exit the simulation." << endl;
        
        cin >> userIn;
        if(userIn != 'y' && userIn != 'Y'){
            break; // leave simulation at user input
            
        }
        else{
            FlipsOccured = true;
            unsigned int ran = rand() % 2; // generates 0 or 1
            if(ran == 1){
                numHeads++; // ran == 1 represents heads
            }
            else{
                numTails++; // ran == 0 ----> tails
            }
            
        } // end outer else
    } // end infinite simulation loop
    
    if(FlipsOccured){
    cout << "The number of heads is " << numHeads << " and the number of tails is " << numTails << endl; 
        
    }
    else{
        cout << "No coin flips were simulated, run again" << endl;
    }

    return 0;
}