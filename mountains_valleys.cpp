#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	// print prompt for input
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	int a = 0;
	int b = 0;
	cin >> a >> b; // get user input for end points of intervals
	//cin >> b; // prompt user for input
	bool valid = false; //variable to determine if we move on with program
	valid = is_valid_range(a,b); // function checks is 10 <= a <= b < 10k, before moving on to task

	while(valid != true){ // continously prompt user for input until input is validated
	    cout << "Invalid Input" << endl;
	    cout << "Enter numbers 10 <= a <= b < 10000: "; // reprompt user for input
	    cin >> a >> b;

	    valid = is_valid_range(a,b);
	} //end input validation loop

// used for testing input integers a,b  with various input intervals
/*	if(valid){
	   cout << "its working" << endl;
	} */
// send a and b to count_valid_mv_numbers here the mountains and valleys are computed and displayed
	
	count_valid_mv_numbers(a,b);  // computes and displays mountains and valley with valid a, b



	return 0;
} // end main
