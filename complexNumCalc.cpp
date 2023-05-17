/******************************************************************************
This program populates a vector with random non repeating numbers from 0 to 9

*******************************************************************************/


#include <iostream>
#include <random>
#include <vector>
using namespace std;

class complxNum{
    public:
      void add(complxNum a, complxNum b){ // add 2 complex numbers
          double real = a.realPt + b.realPt;
          double imag = a.imagPt + b.imagPt;
          cout << real << " + i" << imag << endl;
      }
      void multiply(complxNum a, complxNum b){ // multiply 2 complex number
          double real = a.realPt * b.realPt - a.imagPt*b.imagPt;
          double imag = a.imagPt*b.realPt - a.realPt*b.imagPt;
          cout << real << " + i" << imag << endl; 
      }
      
        complxNum(double real, double imaginary) { // constructor
        this->realPt = real;
        this->imagPt = imaginary;
    }
    
    
    private:
      double realPt;
      double imagPt;
    
}; // end class definition

int main()
{
    // testing in main
    complxNum zOne = complxNum(3,2);
    complxNum zTwo = complxNum(-2,1);
    
    zOne.add(zOne, zTwo);
    zOne.multiply(zOne, zTwo);
 
    return 0;
}