#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {

    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl; // display message
    string string1;
    string string2;
    string operation;
    string readstring;
    std::istringstream inSS;

    int counter = 0;

    getline(cin,readstring);
    inSS.str(readstring);
    inSS >> string1;
    inSS >> operation;
    inSS >> string2;
    bool enterloop = false;
    if(string1 != "q" && string1 != "quit" && !cin.eof()){
        enterloop = 1;
    }
    while(enterloop == 1){
        counter++; // keeps track of iterations, will output one farvel if loop isnt entered later
        if(operation == "*"){
            cout << ">> " << endl;

            cout << "ans =" << endl;
            cout << endl;
            cout << "    " << multiply(string1,string2) << endl;
            cout << endl;

        }
        if(operation == "+") {

            cout << ">> " << endl;

            cout << "ans =" << endl;
            cout << endl;
            cout << "    " << add(string1,string2) << endl;
            cout << endl;
        }
        cin >> string1 >> operation >> string2;
        if(string1 == "q" || string1 == "quit" || cin.eof()){
            cout << ">> " << endl;

            cout << "farvel!" << endl;
            cout << endl;

            enterloop = 0;
        }

    } // end while loop

  /* if(counter == 0){
       cout << endl;
       cout << "farvel!" << endl;

   }*/
  // cout << endl;
return 0;
}
