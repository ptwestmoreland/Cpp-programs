/******************************************************************************

The purpose of this software is to compute the collector current that makes
a nonlinear equation true. This is the bias current needed for a common emitter
transistor amplifier that I am designing.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    float i = 0.0;
    float Col_Current = 0.0011; // initial collector current guess as 1.1 mA

    while(103.8 - i >= 0.1){ // compare i with constant computed equality

        i = log(Col_Current/(5e-16)) + (Col_Current*38461.5); // set i based on collector current
        Col_Current = Col_Current + 0.00001; // increase collector current for next iteration
    }

    cout << Col_Current << endl;

    return 0;
}
