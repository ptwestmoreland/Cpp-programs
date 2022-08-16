#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    //int x = digit - '0';
    
    if((digit >= '0') && (digit <= '9')){
    int x = digit - '0';
    return x;
    }
    else{
        throw std:: invalid_argument("Invalid argument");
   }
}

char decimal_to_digit(unsigned int decimal) {
    

if(decimal == 0 || decimal <= 9){
decimal = decimal + '0';
return decimal;
}
else {
throw std :: invalid_argument("Invalid argument");
    }
}

string trim_leading_zeros(string num) {
    bool run = 0;
    int length = num.size();
    string replaced_zeros = num;
    if (replaced_zeros.at(0) == '-') {
    replaced_zeros = replaced_zeros.substr(1,replaced_zeros.size());
    run = true;
    }
    int j = 0;
    while(j < length){

    if (replaced_zeros.at(j) == '0'){
    replaced_zeros.replace(j,1,"1");
      
    }
    else {
    replaced_zeros = replaced_zeros.substr(j,replaced_zeros.size());
    if (run) {
    }
    return replaced_zeros;
    }
     j += 1;
    }
    if(num.at(0) == '-'){
    replaced_zeros = "-" + replaced_zeros;
    }

    return replaced_zeros;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    return "";
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
    return "";
}
