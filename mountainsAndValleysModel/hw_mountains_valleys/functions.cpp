/* These  three function constitute the entire program. is_valid_range
verifies that the input numbers in main correspond to a valid interval.
We reprompt for input until main until an appropriate interval
From there, the count function sends the numbers in this interval 1 by 1
to the classify function. This function returns 'M/V/N' and count
keeps track of each number in the interval of each type. The classify_mv_range_type
function works by digit slicing and checking for an iterative pattern. It works
for numbers outside of the 10-9999 range and was tested with 8/9 digit
integers */


#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	//This function ensures that input is in range 10 <= a <= b < 10000
	if((10 <= a) && (a <= b)){
		if(b < 10000){ // nested if executes only if prior two conditions are met
			return true; // doesnt reach return false below if conditions met
		} // end inner if
	} // end outer if
	return false; // executes if above return statement does not
} // end is_valid_range function

/* classify number function works for any number regardless of digit size (as long as it can be
represented as a word). Function uses an iterative pattern rather than focusing on 2,3,4 digit numbers
in the range */
char classify_mv_range_type(int number) {
	unsigned int temp = number;
	// count digits
	unsigned int digitCounter = 0;
	while(temp != 0){
		digitCounter++; // count digits in number
		temp /= 10;
	} // end digit counting while loop
	 bool mountain = true;
	 bool valley = true; // these will be set to false if # is not of the type M or V
	 int counter = 0;

	/* process even number of digit mountain or valley, (# of form /\/ = M or \/\ = V) below */

	if(digitCounter % 2 == 0){
	  int dig1 = 0; // used to peel off and compare two digits at a time
    int dig2 = 0;

      while(number != 0){
        counter++; // counts iteration, different comparison for even and odd iterations
        dig1 = number % 10; // peel of digit
        number /= 10;
        if(number == 0){ // break when no more digits to slice
            break;
        }
        dig2 = number % 10; // peel off 2nd digit, after first two dig1 becomes old dig2
        if((counter % 2 != 0)){ // comparison on odd iterations (1,3,5..)
          if(!(dig1 > dig2)){
             mountain = false;
        }
           if(!(dig1 < dig2)){
	            valley = false;
	        }

    }
        else{ // comparison on even iterations
            if(!(dig1 < dig2)){
                mountain = false;
            }
            if(!(dig1 > dig2)){
	                valley = false;
	            }

        }
      } // end digit slicing while
	     if(mountain == true){
	         return 'M';
	     }
	     if(valley == true){
	         return 'V';
	     }
		} // end even number of digits number processing
		// process M/V numbers odd number of digits, comparison differs from above

		if(digitCounter % 2 != 0){ // executes for odd number of digits
		int dig1 = 0;
	  int dig2 = 0;

	    while(number != 0){
	        counter++;
	        dig1 = number % 10;
	        number /= 10;
	        if(number == 0){
	            break;
	        }
	        dig2 = number % 10;
	        if(counter % 2 != 0){ // counter = 1,3,5,etc

	          if(!(dig1 < dig2)){
	            mountain = false;
	         }
	         	if(!(dig1 > dig2)){
				      valley = false;;
					}

	    }
	        else{ // counter is multiple of 2
	            if(!(dig1 > dig2)){
	               mountain = false;;
	            }
	            if(!(dig1 < dig2)){
						      valley = false; // break without incrementing count when a non mountain number pattern is found
					}

	        }
	      } // end while loop
				 if(mountain == true){
					return 'M';
				}
				 if(valley == true){
				    return 'V';
				}
		} // end odd number of digits mountain processing block

   return 'N'; // reached if none of the above are reached
} // end classify function

void count_valid_mv_numbers(int a, int b) {
	// compute and display output

	int total_mountains = 0;
	int valleys = 0;
	for(int i = a; i <= b; ++i){ // loop across all numbers in range and classify
		char type = classify_mv_range_type(i); // send num in range to classify
		if(type == 'M'){
			total_mountains += 1; // count mountains
		}
		if(type == 'V'){ // cant use else as some numbers return character N for neither
			valleys += 1; // count valleys
		}

	} // end mountain-valley counting for loop
	// output results
	cout << "There are " << total_mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;
} // end count function
