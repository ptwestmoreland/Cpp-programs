/******************************************************************************
This program populates a vector with random non repeating numbers from 0 to 9

*******************************************************************************/


#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    srand(time(0));
    cout << "Enter the size of the random vector: " << endl;
    double size = 0.0;
    cin >> size;
    while(size < 0.0){
        cout << "Enter a positive integer value for the size: " << endl; // protect against - and floating point inputs
        cin >> size;
    }
    unsigned int sizeInt = static_cast<unsigned int>(size); // convert vector size to integer 
     
    
     vector<int> randomVec(sizeInt, 0); // declare and initialize vector 
    
    for(unsigned int i = 0; i < sizeInt; ++i ){
        unsigned int temp = rand() % 10; // create a random number 
        randomVec.at(i) = temp;
        for(unsigned int j = 0; j < i; ++j){
            if(randomVec.at(j) == randomVec.at(i)){
                --i;
            }
            
        }
    }
    
    // display vector 
    
    cout << "Your randomly generated vector with non repeating digits is: ";
    for(unsigned int i = 0; i < randomVec.size(); ++i){
        cout << randomVec[i];
    }

    return 0;
}