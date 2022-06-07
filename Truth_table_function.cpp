#include "problem8.h"
#include <iostream>




bool f(bool x, bool y, bool z) {
  // write your code to compute f(x,y,z) here
  // given a random truth table implement its boolean function
  /* i did not reduce it in its largest sum of products form to get
     more practice working with boolean operators */

  bool value = false;

  value = (!x && !y && z) || (!x && y && !z) || (!x && y && z) || (x && !y && !z) || (x && y && z);


  return value;
}
