#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

/*
The goal of this program is to count the number of mountains and valley numbers in a range
of integers. These numbers model mountains and valleys on an ocean floor. A number is a mountain
if d1 < d2 && d2 > d3 for a 3 digit number d1d2d3. A number is a valley if d1 > d2 && d2 < d3
else it is neither. I will use a function and an iterative pattern to classify each number in the
interval 10 - 9999. My classify function should work for numbers that are outside of the 4 digit range.

*/

int main() {
	//  print prompt for input

	bool initial_input_prompt = false; // used to enter loop and validate input
	int a = 0;
	int b = 0; // input range
	while(initial_input_prompt == false){ // repeat until valid range 10 <= a <= b < 10000 is recieved
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> a >> b;
		initial_input_prompt = is_valid_range(a,b); // loop breaks when a valid range is found, else it repeats prompt
		if(!initial_input_prompt){ // executes when is_valid_range returns false 
			cout << "Invalid Input" << endl; // executes if not valid range
		}
	} // end while loop

    // count mountains and valleys in range and display output

		count_valid_mv_numbers(a,b);

	return 0;
}
