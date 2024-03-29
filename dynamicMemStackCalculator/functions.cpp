#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  INFO_STRUCT(stack);
  INFO(number);

  if(stack.capacity == stack.count) // resize stack array
  {
    stack.capacity = stack.capacity * 2;
    int* tempPte = new int[stack.capacity]; // double stack array capacity
    for(int i = 0; i < stack.count; ++i){
      tempPte[i] = stack.numbers[i];
    }
    delete[] stack.numbers;
    stack.numbers = tempPte;
    tempPte = nullptr;
    delete[] tempPte;
    //tempPte = nullptr;
  }
  stack.numbers[stack.count] = number;
  stack.count += 1;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);

  if(stack.count == 0){ // empty stack
    return INT32_MAX;
  }
  stack.count -= 1; // return last element and reduce count size
  return stack.numbers[stack.count]; // {0,1,2,3} count = 4, after exe count = 3 return 3
}

/**
 * ----- REQUIRED -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO: implement peek function for stack
  INFO_STRUCT(stack);
  if(stack.count == 0){ // empty stack
    return INT32_MAX;
  }
  //stack.count -= 1; // return last element and reduce count size
  return stack.numbers[stack.count - 1];


  return 0;
}
