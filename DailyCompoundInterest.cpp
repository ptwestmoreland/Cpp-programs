/******************************************************************************

The purpose of this program is to compute the ending amount of a sum of money that grows by a constant
percentage per day. 

*******************************************************************************/
#include <iostream>
using namespace std;

/* program should start with some user input amount of money, daily percent increase/ rate of growth, and 
time period in years. 
it should pass this info to a function which computes and returns the total amount of money at the end of
the period */ 

int timeConversionYearsToDays(int years){
    int days = years * 365;
    return days;
}

double computeBalance(double principle, double rate, double timePeriod){
    /* function should repeatedly multiply value by rate of growth. i.e. if we start with 1000 dollars 
    ,that increases by 2% per day, then on day 1 we should have 1000 * 1.02 dollars, that amount should 
    be multiplied by 1.02 the next day */ 
    
    int timePDays = timeConversionYearsToDays(timePeriod);
    double amt = principle;
    double decimal = rate / 100.0;
    for(int i = 0; i < timePDays; ++i){
        amt *= (1 + decimal);
    } // end computation loop 
    return amt; 
    
} // end function


int main()
{
    double beginAmt = 0.0;
    double rateofgrowth = 0.0;
    cout << "Enter the starting amount of money in dollars: ";
    cin >> beginAmt;
    cout << "Enter the daily percentage growth: ";
    cin >> rateofgrowth;
    double timePeriod = 0;
    cout << "Enter the time period in years: ";
    cin >> timePeriod;
    
    double endAmt = computeBalance(beginAmt, rateofgrowth, timePeriod);
    
    cout << endAmt << endl;
    
    

    return 0;
}