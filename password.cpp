#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    /* Take in a user password string, replace certain characters with others, then reverse the string
    and append the updated password with the reversed password */
  string password = "";

  cout << "Please enter your text input: ";
  getline(cin, password);
  cout << "input: " << password << endl;

  for(int i = 0; i < password.size(); ++i){
      if(password.at(i) == 'a'){
          password.at(i) = '@';
      }
      if(password.at(i) == 'e'){
          password.at(i) = '3';
      }
      if(password.at(i) == 'i'){
          password.at(i) = '!';
      }
      if(password.at(i) == 'o'){
          password.at(i) = '0';
      }
      if(password.at(i) == 'u'){
          password.at(i) = '^';
      }
  }
  //create a new string that will be the reversed string
  string reversed_pass = password; // initialize it to have the correct amount of indices

  int k = password.length() - 1; // gives last index of password string

  //revered_pass.at(0) = password.at(password.size()-1) this needs to be the last index in the new string

  for(int j = 0; j < reversed_pass.size(); ++j){
    reversed_pass.at(j) = password.at(k);  // reverses the string password
    k = k - 1; // deincrement k to go backwords through the password string down to 0
  } // end loop

  /* for testing
  cout << password << endl;
  cout << reversed_pass << endl; */

  // append new string to old string
  string final_result = password + reversed_pass;
  cout << "output: " << final_result << endl;
    return 0;
}
