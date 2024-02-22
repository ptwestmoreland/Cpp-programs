
#include <iostream>
#include <stdexcept>
#include "functions.h"
using namespace std;

int Largest(int a, int b, int c) {
  if(a >= b && a >= c){
      return a;
  }
  else if(b >= a && b >= c){
      return b;
  }
  else if(c >= a && c >= b){
      return c;
  }
  return a;
}

bool SumIsEven(int a, int b) {
  if( (a+b) % 2 == 0) {
      return true;
  }
  else{
    return false;
  }
}
int BoxesNeeded(int apples) {
    // takes in a number of apples and returns how many boxes are needed to pack them
    // should only work for apples being greater than or equal to 0
    // make selection statements for the various cases:
    int boxes = 0;
    if(apples <= 0){ // blocks negative input and returns 0 for the no apples case
       boxes = 0;
    } // end if
    if(apples > 0){ // else
        /* if the number of apples is divisible by 20, we just return the int division result */
       if(apples % 20 == 0) { // begin nested if for apples divisible by 20 case
           boxes = apples / 20; // integer division
       }
       else {
           /* the number of extra apples for an input that is not divisible by 20 will always
           be less than 20, b/c we have split apples into groups of 20 */

           boxes = (apples / 20) + 1; // add one extra box for the remainder
       } // end nested selection
    } // end outer selection for apples > 0
  return boxes; // send to calling point needed amount of boxes
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {

    /* function takes in the number of students in section A that get a question right
    and the number of students in section A. The same occurs for section B. We then compute
    the percentage of students in each section who got it right. If section A did better
    on the question return true, otherwise return false. We throw an exception
    if the arguments are invalid. */

    // throw invalid for any negative inputs:
    if(A_correct < 0 || A_total < 0 || B_correct < 0 || B_total < 0 )
    {
        throw std::invalid_argument("");
    }
    /* throw invalid if the number of kids in each section who got
    the question right exceeds the
    amount of students in the section */

    if(A_correct > A_total || B_correct > B_total){
      throw std::invalid_argument("");
    }
   // convert to doubles to get the proper ratio and clear up int division issues
    double A = static_cast<double>(A_total); // turn total people in A to double
    double B = static_cast<double>(B_total);
    double correctA = static_cast<double>(A_correct);
    double correctB = static_cast<double>(B_correct);
    // division would work with just two of the 4 values changed to doubles
    // I converted all of the values as a precaution
    double percent_A = correctA / A; // computes percentages as floating points
    double percent_B = correctB / B;
   //cout << percent_B; used for testing
   if(percent_A > percent_B){
       return true;
   }
   else { // if section B does better on the question
       return false;
   }

}
bool GoodDinner(int pizzas, bool is_weekend) {

    /* Function takes in 2 inputs, the number of pizzas eaten and a true/false value
    indicating whether it is a weekend or not. The function returns a 0/1 value.
    function returns true if we had a good dinner and false if the user didnt. A good
    dinner is defines as eating between ten and twenty pizzas (Chrikey!), unless it is a weekend
    then there is no upper limit on pizzas. */

  if (pizzas >= 10 && pizzas <= 20 && !is_weekend) {
    return true;  // on a normal day eating between 10 - 20 pizzas is a good dinner
  }
  if (is_weekend && pizzas >= 10) {
    return true; // no upper limit on the number of pizzas interval for a weekend period
  }
  else{
      return false;
  }
}


int SumBetween(int low,int high) {

    /*
    This value takes in two endpoints of an interval, it then sums all the numbers along that
    interval, (endpoints included), and returns the sum. The function should compute the sum in some
    situations in whcih overflow would occur during computation.
    Further, the function will throw an
    invalid argument error if the endpoints are not in ascending order, (low < high). The function
    will throw an overflow error if the sum grows larger than the maximum or minimum possible value
    stored in a 32 bit integer when its not possible to get around this
    */
    int sum = 0;
    if(high < low) // must have low < high
    {
      throw invalid_argument("");

    }

    /*
       Below I target edge cases near and at the limits where the sum is known
       but it can not be computed in later blocks due to overflow occuring In
       those blocks.  Further, these
       cases are limited to points where a value that will not overflow is returned
       as in INT32_MAX + 1, which results in overflow, will not be worked with.
    */
     if(low == INT32_MIN && high == INT32_MAX)
     {
       return INT32_MIN; // int32MIN = -(INT32_MAX + 1), sum between them is INT32_MIN

     }
     if(low == INT32_MIN + 1 && high == INT32_MAX)
     {
       return 0; // max = |MIN| - 1, sigma(min + 1, max) = 0

     }
     if(low == INT32_MIN + 1 && high == INT32_MAX - 1)
     {
       return (INT32_MIN + 1);

     }
     if(low == INT32_MIN && high == INT32_MIN){
       return INT32_MIN;
     }
     if(low == INT32_MAX && high == INT32_MAX){
       return INT32_MAX;
     }
     if(low == INT32_MIN + 2 && high == INT32_MAX){
       return INT32_MAX;
     }




  /*
  adjust situations in which overflow will occur during computing the
  sum but its possible to return the sum. As in, having a large negative value and a
  positive value. Works by canceling out unneccesary computations
  */
   if(high > 0 && low < 0) // executes for above mentioned cases, works even if its not required
    {
      if(abs(low) == abs(high))
      {
        return 0; // sigma(-10,10) = 0 or sigma(INTMIN, INTMAX), sum should be 0 but overflow would occur if we tried it
      }
      if(abs(low) < high)
      {   // executes for case low = -2, high = 5, cancels out unneccesary additions by adjusting low
        low = abs(low) + 1; // makes low = 3 for above case as, sigma(3,5) = sigma(-2,5)

        }
        if(abs(low) > high) // executes for -12, 3
        {
          high = high * -1; // negate
          high = high - 1; // adjust upper limit, for -12, 3: high -> -4
        }
    }
    for(int i = low; i <= high; ++i)
    { // sum between low and high, check for overflow
     if(abs(sum) > INT32_MAX - abs(i)){
        throw overflow_error("Overflow");
      }
    /*  if(i > 0)
      {
        if(sum > INT32_MAX - i)
        {
          throw overflow_error("overflow");

        }
      }
      if(i < 0)
      {
        if(sum < INT32_MIN - i){
          throw overflow_error("overflow");
        }

      } */
      sum = sum + i;

    }
    return sum;

} // end function

int Product(int a, int b) {

  /* This function calculates the product of two numbers, it throws
  an overflow error if the product exceeds the max/min value stored
  in an integer */

// a * b > INT32_MAX
// - a * b < INT32_MIN
long long int r = a * b; // store intermediate product in a variable that can withstand regular int over flow

if(b == 0){
  return 0; // added to avoid divide by zero when checking for overflow
}
// int a * int b = r ----> r/b = a or b = r/a
if(a == r/b){
  return r; // no overflow occurs if a is r/b
}
else{
  throw std:: overflow_error(""); // overflow does occur if we get a value for r/b that is not a
}



   return a*b;
 }
