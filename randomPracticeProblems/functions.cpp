#include <iostream>
#include "functions.h"
using std::cout, std::invalid_argument, std::endl;

bool isTriProduct(int n)
{
  for(int i = 1; i <= n/2; ++i){ // we dont need to iterate all the way to n, but it would work still if we did

    if(i * (i + 1) * (i + 2) == n){
      return true;
    }
  }
  return false;
}


void findSum(int arr[], int n, int target)
{ /*
  goal: take in array and verify that 0 < n < 5000 (size of array), take in target. Loop through array
  and see if any two elements sum to the target number. If so, output the 2 numbers with standard out. If not, output
  "none" to standard out
  */

  if(n <= 0 || n >= 5000)
  {
    throw invalid_argument("Array size must be between 1 - 4999");
  }
  bool executed = false;
  for(int i = 0; i < n - 1; ++i) // outer loop goes from 0 to size_arr - 2
  {
    for(int j = i + 1; j < n; ++j) // inner loop executes from i + 1 to size_arr - 1 looking for sum
    {
      if(arr[i] + arr[j] == target)
      {
        // print out all pairs found
        cout << arr[i] << "," << arr[j] << endl;
        executed = true; // imeffcient to reassign but it will work for now
      } // end if
      else
      {
        continue; // goto next iteration
      } // end else
    } // end inner loop

  } // end outer loop

  /*
  Example run of above nested loop : arr = (2,4,6), n/size = 3, and target = 8.
  In first run i = 0, so the outer loop accesses arr[0] = 2, the inner loop then begins.
  The inner loop goes from arr[i + 1] = 0 + 1 = arr[1] to arr[2] checking if arr[i = 0] + arr[j] == target
  If it does, then we print that pair and set execute to true. i is then incremented to 1. In our case, this will
  be the last outer loop iteration as i stops at size/n - 2, or 3 - 2 here. We then repeat the above process.
  So the loops checks 2 + 4 = target, then 2 + 6 = target then 4 + 6 = target and then it stops
  */

  if(!executed) // executes when no pairs of numbers were found
  {
    cout << "none" << endl;
  }
} // end function findSum

bool isPalindrome(int n)
{
  /*
  take in an integer n and determine if it is a palinedrome
  return true if so and false if not. A Palindrome is a number
  that is identical from front to back. String class is forbidden.
  */

  /*
  we could slice digits and place in array, but this would require a variable
  length array. Instead, I will reverse the number and check for equality with n
  */
  int reverse = 0;
  int temp = n; // set temporary to n
  while(temp != 0)
  {
    // below doesnt handle potential overflow, works for 1 to ~9 digits
    int digit = temp % 10;
    reverse = reverse * 10 + digit; // places back digit at front
    temp /= 10;

  } // end while loop to reverse number
  if(reverse == n)
  {
    return true;

  }
  return false; // executes if above does not

} // end palindrome function

bool isHappyNum(int n)
{
  /*
  return true if a number is "happy", a happy number is one in which
  when summing its squared digits, the result is 1. All unhappy numbers
  eventually converge to 4 eg 28 = 2^2 + 8^2 = 68, 6^2 + 8^2 = 100, 1^2 + 0 + 0 = 1, so
  28 is a happy number.
  */
  int digit = 0; // holds digit
  int sum = 0;
  while(true)
  {
    while(n != 0) // inner while loop to peel and sum digit squared
    {
      digit = n % 10; // peel off 1 digit of number
      sum = sum + (digit*digit); // sum square of digit
      n /= 10; // reduce to get next digit
      if(sum == 1){ // happy number
        return true;
      }
      if(sum == 4){ // every unhappy number converfes to 4 eventually
        return false;
      }
      // repeat above process until all digits of nuimber are squared and summed
    } // end inner digit processing while loop
    n = sum; // reset n to whatever value is in sum (its not 1 or 4, the sentenial value)
    sum = 0; // reset sum to store sum of new digits

  } // end outer infinite loop

} // end isHappyNum()

bool hasFailingGrade(double grades[], unsigned int size)
{
  // goal: find and fix logic error
  if (size == 0) {
    throw invalid_argument("There are no grades.");
  }

  bool hasFailing = false;
  for (unsigned int i = 0; i < size; ++i) {
    if (grades[i] < 60) {
      hasFailing = true;
      /*
       bug is right here, we should break from loop once a failing grade is found, further iteration
      results in hasFailing being reset to false if a later value is > 60
      */
      break;
    }
    else {
      hasFailing = false;
    }
  }
  return hasFailing;
}







int main()
{
  // small amount of unit testing

  try
  {
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(1921923) << endl;
    cout << isHappyNum(28) << endl;
    cout << isHappyNum(102) << endl;
    cout << isTriProduct(120) << endl;
    int arr[] = {5,3,2,4,9};
    int size = 5;
    int target = 6;
    findSum(arr,size,target);
    size = -2;
    findSum(arr,size,target); // should throw an exception
  }
  catch(invalid_argument &e)  // catches obj of invalid_argument type

  {
    cout << e.what() << endl;
    return -1; // error

  }
  return 0;
}
