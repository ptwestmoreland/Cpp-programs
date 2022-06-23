#include <iostream>
//#include <string.h>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  char k = str[0];
  int count = 0;
  int i = 0;
  while(k != '\0'){
    count++;
    i++;
    k = str[i];
  }
  return count;
}

unsigned int find(char str[], char character) {
  // returns
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  int index = 0;
  int size = length(str);
  for(int i = 0; i < size; ++i){
    if(str[i] == character){
      index = i;
      return index;
      break;
    }

  }
return size;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  int a = 0;

  bool equal = true;
  int length1 = length(str1);
  int length2 = length(str2);
  if(length1 == length2){
    while(a < length1 && a < length2){
      if(str1[a]!= str2[a]){
        equal = false;
        break;
      }
      a++;
    }
  }
  else{
    equal = false;
  }
  return equal;
}
