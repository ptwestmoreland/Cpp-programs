#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

/*
convert a character digit to an integer value
input: digit - a character representing a digit, e.g. '7'
output: the corresponding integer value of the digit, e.g. 7
throws: std::invalid_argument if the input is not a valid digit, e.g. '0' -- '9'
*/
unsigned int digit_to_decimal(char digit) {

 // function should only work for characters within 0 to 9
 if( (digit >= '0') && (digit <= '9') ){ // check range
     unsigned int digit_num = digit - '0'; // convert to integer
     return digit_num; // return it
 }
 else{
     throw std:: invalid_argument("Invalid argument"); // throw exception
 }
return digit; // extra return
}
/*
convert an integer value to a character digit
input: decimal - an integer value of a digit, e.g. 7
output: the corresponding character of the digit, e.g. '7'
throws: std::invalid_argument if the input is not a valid digit, e.g. 0 -- 9
*/

char decimal_to_digit(unsigned int decimal) {
    char digit_character = '0';
    if(decimal <= 9){ // check range
        digit_character = decimal + '0'; // convert int to char
        return digit_character; // return char
    }
    else{
        throw std::invalid_argument("Invalid argument"); // throw exception
    }
    return '\0'; // extra return
}
/*
remove the leading zeros from a number
input: num - a string representing a number with zero or more leading 0s
output: a copy of the input with all leading 0s removed
throws: none
*/
string trim_leading_zeros(string num) {
    string trimmed_string = "";

// for the case of positive strings:
// string represents a number

if(num.at(0) != '-') // executes for non negative strings
{

    // test to see if positive string is all zeros:
    unsigned int count = 0; // for large zero strings
    for(unsigned int i = 0; i < num.size(); ++i){
        if(num.at(i) == '0'){
            count++; // increments count for every zero in string
        }
    } // end loop to count total zeros in string
    if(count == num.size()){
        trimmed_string = "0";
        return trimmed_string;
    }
    for(unsigned int i = 0; i < num.size(); ++i){ // iterate through string
        if(num.at(i) != '0') // check each index for non equality with 0
        {
            trimmed_string = num.substr(i,num.size()); // when we reach a non zero entry create substr
            return trimmed_string; // return substring from non 0 to end of string
            // works for numbers with no leading zeros or with leading zeros
        } // end selection
    } // end for loop
} // end positive non zero string block

// for the case of negative strings:
if(num.at(0) == '-') // executes for only negative strings
{

    // test to see if negative string is all zeros:
    unsigned int count = 0; // for large zero strings
    for(unsigned int i = 1; i < num.size(); ++i) // iterate from 2nd index because first is '-'
    {
        if(num.at(i) == '0'){ // count each zero
            count++;
        }
    }
    if(count == num.size() - 1) // we care about size - 1 due to '-' being the first character
    {
        trimmed_string = "0"; // set string to "-0"
        return trimmed_string;
    }
    for(unsigned int i = 1; i < num.size(); ++i) // iterate from second index to last
    { // begin for loop
       if(num.at(i) != '0'){ // find first char not equal to 0
           trimmed_string = num.substr(i,num.size()); // create new string from this index to last
           trimmed_string = "-" + trimmed_string; // concact negative sign to string
           return trimmed_string;

       } // end nested if

    } // end for loop
} // end negative string block
return trimmed_string; // for compiler warnings, returns earlier
} // end function trim leading zeros
string add(string lhs, string rhs) {

// declare and initiliaze strings to hold numbers
string lhs1 = trim_leading_zeros(lhs);
string rhs1 = trim_leading_zeros(rhs);
// int variables
int stringnum = 0;
int place = 0;
int carry = 0;
// char variables
char res;
char t = 'a';
char negative_sign = '-';
// string variable
string summation;
string lhs2 = lhs1;
string rhs2 = rhs1;
int k = lhs1.length() - 1;
int n = rhs1.length() - 1;

if(!(lhs1.at(0) != '-')) { // execute if negative number, result will neg
   lhs2 = lhs1.substr(1, k); // get rid of negative sign for processing
   rhs2 = rhs1.substr(1,n); // repeat

} // end if

// check strings for equal length and make equal if not equal
if(lhs2.length() < rhs2.length()) {
    while(!(lhs2.length() == rhs2.length())){
        lhs2 = lhs2.insert(0,"0");
    } // end while
} // end if

// repeat for reverse situation
if(rhs2.length() < lhs2.length()){
    while(!(lhs2.length() == rhs2.length())){
    rhs2 = rhs2.insert(0,"0");
} // end while
} // end if

lhs2.insert(0, "0");
rhs2.insert(0,"0");
lhs2.insert(0, "0");
rhs2.insert(0,"0");

// begin processing
k = lhs2.length() - 1;
while(k > 0 || k == 0) {
    unsigned int a = digit_to_decimal(lhs2.at(k)); // turns char to decimal
    unsigned int b = digit_to_decimal(rhs2.at(k)); // turns char to decimal
    stringnum = a + b + carry; // sum this and any carry
    carry = 0;
    if(9 < stringnum){ // addition resulted in a two digit number
     carry = stringnum / 10; // store digit
     place = stringnum % 10; // stoer digit
     t = decimal_to_digit(place);
     summation = t + summation;
    } // end if
    else { // one digit number
        res = decimal_to_digit(stringnum);
        summation = res + summation;
    }
k-=1;
} // end while loop
string trimmed_string = "";
if(lhs1.at(0) == negative_sign){
    summation = '-' + summation;
     trimmed_string = trim_leading_zeros(summation);
}
else{
     trimmed_string = trim_leading_zeros(summation);
}
return trimmed_string;


} // end add function

/*
muplity two numbers
input: lhs,rhs - strings representing numbers, e.g. "1", "2"
output: the result of multiplying lhs by rhs: lhs * rhs, e.g. "2"
throws:  none.
*/
string multiply(string lhs, string rhs) { // begin multiply function
// redoing w/ diff method, previous only worked for some tests
lhs = trim_leading_zeros(lhs);
rhs = trim_leading_zeros(rhs);
int carry = 0;
int count = 0;
count = 1;
int indprod = 0;
string summation = "0";
string res = "";
bool appneg = 0;

if((lhs.at(0) == '-') ^ (rhs.at(0) == '-')){ // uses XOR to execute for only one neg sign case
   appneg = 1;
    if(lhs.at(0) == '-'){ // nested if
        int k = lhs.length() - 1;
        lhs = lhs.substr(1,k); // replaces lhs with numeric portion
       // return lhs; debugging fixme
    }
    else{ // executes if rhs has a negative sign and lhs does not
        int k = rhs.length() - 1;
        rhs = rhs.substr(1,k);
        //return rhs; debugging fix me
    }
} // end outer if
// case where both are negative (this implies that the result of multiplication is positive)
if(rhs.at(0) == '-'){
    if(lhs.at(0) == '-') {
        int k = lhs.length() - 1;
        int n = rhs.length() - 1;
        lhs = lhs.substr(1,k);
        rhs = rhs.substr(1,n); // gets just numeric portion for both sets
        //return lhs; used in debugging
    }
} // end both negative if block

// creating for clairty, two positive strings lhs rhs

if(lhs.at(0) != '-' && rhs.at(0) != '-'){
    lhs = lhs;
    rhs = rhs;
    //return rhs + lhs; used in debugging
}
// loop statements used to compute multiplication
int i = lhs.size()-1;


while(i > 0 || i == 0)
{ // begin outer for loop
 // multiplcation must be done thoughout the number
  for(int j = rhs.size()-1; j >=0; j--){ // begin inner loop iterate for all indx rhs for each lhs

     indprod = digit_to_decimal(rhs.at(j)) * digit_to_decimal(lhs.at(i)) + carry; // multiply digits and add carry
     carry = 0; // reset carry

     // selection sequence within innner for loop

     if((9 < indprod) && !(j!=0)){ //indprod 2 digits and last index j
         int temp2 = indprod; //storage for prod
         while(!(temp2 == 0)){
             char a = decimal_to_digit(temp2 % 10);
             res = res + a; //append char
             temp2 = temp2 / 10;
         }
     } // end 2 digit indprod and j = 0
     else if((9 < indprod) && j != 0){ // indprod is 2 digits and j !===0
         char a = decimal_to_digit(indprod%10);
         carry = indprod / 10;
         res = res + a; // append char
     } // end inner else if block
     else{ // 1 digit end prod
         char a = decimal_to_digit(indprod);
         res = res + a; // apend char
     }

  } // end inner loop
  string stur = ""; // storage for res
  int len = res.size() - 1;
  while(len >= 0){
      stur += res.at(len);
      len = len - 1;
  }
  summation = add(summation,stur); // perform addition
  res = ""; // reset result before looping back
  for(int p = 0; p < count; ++p)
  res.append("0"); //store zeros on result
  count++; //inc count

i--; // deinc i
} // end outer for loop

// differntiate between positive and negative inputs

if(appneg == true){
    summation = '-' + summation;
}
return summation;
} // end multiply function
