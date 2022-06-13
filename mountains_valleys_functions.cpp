#include <iostream>
//#include "functions.h"

using namespace std;

bool is_valid_range(int a, int b) {
    /* this function takes in two standard input arguments from main and verifies that
    they are within the range 10 - 9999 and that they meet the condition a <= b */
	// in main this function is continously called until we have a valid range
	// validating input range:
	// nested selection could be used for expression simplification
    if( (10 <= a) && (a <= b) && (b < 10000) )
    {
        return true;
    }
    else
    {
        return false;
    } //end if-else block
} // end is_valid_range function

char classify_mv_range_type(int number) {

    /* This function takes in a number as input, this number will be between two digits
    and 4 digits wide, if digit 2 > digit 1 and digit 2 > digit 3 and digit 4 is greater
    than digit 3, we have a mountain number. The same principle applies to numbers that are
    less than 4 digits.
    Conversely if digit 1 > digit 2 and digit 3 > digit 2 and digit 3 is > digit 4
    we have a valley, if none of these patterns are met, then we have neither. This will be
    accomplished by number slicing, a series of selection statements will execute
    depending on the number of digits in the input number, this function executes once
    for each number in the interval a - b */
	// return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

	// begin function execution:
	// begin number slicing based on number of digits
	if((number >= 10) && (number <= 99)) // i.e number is two digits wide
	{
	   // slice digits based on integer division and modulus operator
	   int dig1 = number / 10; // holds digit1, most signifigcant digit
	   int dig2 = number % 10; // holds the least signifigcant digit, digit 2 (10, dig2 = 0)
	   if(dig2 > dig1){ // begin nested selection to classify number as mountain or valley
	       return 'M'; // return mountain
	   }
	   else if(dig1 > dig2){
	       return 'V'; // return valley
	   }
	   else{
	       return 'N'; //return neither
	   } // end nested selection block to classify number as mountain or valley

	}
	else if(number <= 999) // if number is in range 100 - 999 (3 digits)
    {
        //slice into 3 digits
        int temporary = number / 10; // holds 2 most sig digits
        int dig3 = number % 10; // stores digit3, least signigcant digit
        int dig1 = temporary / 10; // stores most signfigicant digit
        int dig2 = temporary % 10; // stores digit2, the 2nd most signfigicant digit
        if( (dig2 > dig1) && (dig2 > dig3) )
        { // begin nested selection to classify number
           return 'M'; //return mountain
        }
        else if((dig1 > dig2) && (dig3 > dig2))
        {
            return 'V'; //return valley
        }
        else{
            return 'N'; //return neither
        } //end nested selection to classify 3 digit mountain / valley number
    }
    else if(number < 10000) // jump here if number is 4 digits 1000 to 9999
    {
        //slice into component digits and compare them
        int temporary1 = number / 10; //stores digits 1 - 3 (3 most sig, 999 in 9990)
        int temporary2 = temporary1 / 10; // stores two most sig digits
        int dig1 = temporary2 / 10; // splits 2 digits, most sig goes here
        int dig2 = temporary2 % 10; // stores 2nd most digit here
        int dig3 = temporary1 % 10; // stores 3rd digit, 2nd least sig digit
        int dig4 = number % 10; // stores digit4 (least signfigicant)
        if((dig2 > dig1 ) && (dig2 > dig3) && (dig4 > dig3)) // begin nested if to classify 4 digit number
        {
            return 'M'; // return mountain to count_valid_mv function, then send in next num
        }
        else if( (dig1 > dig2) && (dig3 > dig2) && (dig3 > dig4)) {
            return 'V';
        }
        else{
            return 'N';
        } //end nested selection block to classify numbers
     } // end 4 digit number comparison and classification block



    else{ // created for any unforseen cases, if any invalid input comes in this executes
        return 'N';
    }
   return 'N';
} //end function classify_mv_type

void count_valid_mv_numbers(int a, int b) {
	//  count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format

	/* loop through the interval a to b and keep track of mountains and valley patterns
	   present in the interval. Each number will be a mountain or a valley or neither
	   and this will be determined in the classify_mv_type function */

	   int total_mountains = 0;  // keeps track of mountains
	   int total_valleys = 0;  //keeps track of valleys
       int i = a; // using i to preserve a for later display in function

	   while(i <= b) { // iterates through whole interval a - b
	     char function_output = classify_mv_range_type(i);

	     if(function_output == 'M'){
	         total_mountains += 1;
	     }
	     else if(function_output == 'V'){
	         total_valleys += 1;
	     }
	     else{
	         i++; //increments i to next num in interval if we have a neither, then jumps to loop
	         continue; //go back to loop if we dont have a mountain or valley number
	     }
	     i += 1;
	 } // end while loop

	 // display correct function_output "There are x mountain ranges....."

cout << "There are " << total_mountains << " mountain ranges and " << total_valleys;
cout << " valley ranges between " << a << " and " << b  << "." << endl;


} // end function: count_valid_mv_numbers
