#ifndef FUNCTIONS_H
#define FUNCTIONS_H
/* These  three function constitute the entire program. is_valid_range
verifies that the input numbers in main correspond to a valid interval.
We reprompt for input until main until an appropriate interval
From there, the count function sends the numbers in this interval 1 by 1
to the classify function. This function returns 'M/V/N' and count
keeps track of each number in the interval of each type. The classify_mv_range_type
function works by digit slicing and checking for an iterative pattern. It works
for numbers outside of the 10-9999 range and was tested with 8/9 digit
integers */


bool is_valid_range(int a, int b);

char classify_mv_range_type(int number);

void count_valid_mv_numbers(int a, int b);

#endif  // FUNCTIONS_H
