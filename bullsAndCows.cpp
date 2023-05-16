/******************************************************************************



This is my implementation of the bulls and cows game. This implementation will be done using
vectors as opposed to strings, even though strings would be easier to work with, to make it more
difficult on myself. The goal is for users to guess a random n digit numeric code. This code
will be randomly generated or code created by the player. For each user guess that is correct in value and placement, the player recieves a bull
if the user guesses the right value but its in the wrong digit/place, the user gets a cow. For instance,
if the code is 2894 and the guess is 4698, then the player has 1 bull and 2 cows. The game is repeated
until the guess is correct. Leading 0s will be added to vectors to compensate for missing digits in the entered values.
In this program, the computer will randomly generate an n digit code with no repeating
digits (or accept a user defined code). The user will choose the amount of digits in the code. The options will be 3,4,5. The prompt should
be repeated until a valid choice is selected. The user can choose 0, 3, 4, or 5 digits for the code.
Choosing 0 allows the user to pick their own 3,4,5 digit game code. The user can enter floating point values
for the game code and guess (this was added in to stop a game breaking bug) but they will be converted to data type
unsigned int by truncating the decimal. The user can not enter a negative value in for either of these items.
The user guess and game code will be stored as an integer and then digit
sliced and placed in a vector.

*******************************************************************************/
// the overall goal of this game is to correctly guess a 3, 4, or 5 digit code
#include <iostream>
#include <vector>
#include<cstdlib> // random number generation
#include <chrono>
using namespace std;

int main()
{

srand(std::chrono::duration_cast<std::chrono::milliseconds>
(std::chrono::system_clock::now().time_since_epoch()).count()%2000000000); // seed rand() function

cout << "Welcome to the bulls and cows game." << endl;
cout << "Please enter the desired number of digits for the code. Your options are 0, 3, 4, or 5 (0 allows you to play with your own code): ";
double numDigits = 0.0; // stores desired number of digits, using data type double because a non integer value breaks code
cin >> numDigits;
unsigned int numDigitsInt = static_cast<int>(numDigits); // convert to int
    // validate user input and reprompt

while(numDigitsInt != 0 && numDigitsInt != 3 && numDigitsInt != 4 && numDigitsInt != 5){
    cout << "Please enter the desired number of digits for the code. Your options are 0, 3, 4, or 5 (0 allows you to choose your own code): ";
    cin >> numDigits;
    numDigitsInt = static_cast<int>(numDigits); // convert to int
        // exits loop when valid number of digits are chosen
    }
    // cout << numDigitsInt << endl; //used for debugging

    vector <int> genCode(numDigitsInt, 0); // declare vector to hold random/user defined game code

    // if numDigitsInt is 0, we should take in a user code as an integer



if(!numDigitsInt){ // executes if and only if the number of chosen digits is 0

       cout << "Enter your desired game code, do not use repeating digits: ";
        // store user code, accepts double to protect against malicious users
       double userCodeTemp = 0.0;
       cin >> userCodeTemp;
       while(userCodeTemp < 0.0){ // protect against game breaking negative inputs
          cout << "Enter your desired game code, it must be a non negative integer value ";
          cin >> userCodeTemp;
       } // end while loop
      unsigned int userCode = static_cast<int>(userCodeTemp); // convert to double to int

    // now we should take in the number of digits in the user generated code since 0 was selected to get to this point
       cout << "Enter the number of digits in your user defined game code, choose 3, 4, or 5. Leading 0's will be added if your chosen code does not have enough digits: ";
       double numDigits = 0.0;
       cin >> numDigits;
       numDigitsInt = static_cast<int>(numDigits); // convert to int

        while( numDigitsInt != 3 && numDigitsInt != 4 && numDigitsInt != 5){
        cout << "Please enter the number of digits for the code. Your options are 3, 4, or 5: ";
        cin >> numDigits;
        numDigitsInt = static_cast<int>(numDigits); // convert to int

        // exit loop when valid number of digits are chosen
      } // end while

       genCode.resize(numDigitsInt, 0); // recreate the code vector with the correct number of digits and set all values to 0

    /* now we need to take the user entered code and digit slice it. The digits will then be put in the vector genCode
    We need to add leading zeros where necessary. For instance, if a player enters 29 as their code and the number of digits as 3,
    then the code needs to be 029. This will be done by initially filling the vector with 0's and then adding
    the digits from the last index forward */
       unsigned int j = numDigitsInt - 1;
       while(userCode != 0 && j >= 0){ // we need to add leading 0s so vector is filled from the last index to the front
         genCode.at(j) = userCode % 10; // vector is populated with 0 and filled from back to front so that code 29 and numdigits of 3 is 029
         userCode /= 10;
         --j;


     } // end digit slicing and vector loading while loop
} // end if block that allows user to create their own starting code by initaiily setting numDigits to 0


// If the number of digits is not initially set to 0, we should generate a random code with non repeating digits from 0 to 9

else if(numDigitsInt == 3 || numDigitsInt == 4 || numDigitsInt == 5){ // need el if because numDigitsInt is 3,4, or 5 by default from above block
    // generate a random code of size numDigitsInt with no repeating digits
    // the game code vector is already created with the correct size and initialzed with all zeros at this point
  for(unsigned int i = 0; i < numDigitsInt; ++i){ // game code is not user defined here so we don't need to worry about leading 0s
    unsigned int ran = rand() % 10; // create a random number from 0 to 9
    genCode.at(i) = ran; // put random number in game code vector

      for (unsigned int j = 0; j < i; j++) { // ensure no repeats occur
        if (ran == genCode.at(j)) {
          i--; // repeats previous step when a repeat is found
          } // end if
      }
  } // end vector loading for loop

}   // end if block for random code generation

// output game code, this is strictly for testing purposes
cout << "Number to guess: ";
for(unsigned int i = 0; i < numDigitsInt; ++i){
    cout << genCode.at(i);
}
cout << endl;
// game play begins below
unsigned int bulls = 0;
unsigned int cows = 0;
vector <int> guess(numDigitsInt, 0); // declare guess vector of same size as generated code vector
bool quit = false; // used to signify player exit without winning game
// begin game below
bool repeat = false; // checks for repeat digits in user entered guess
while(true){ // executes until all digits are bulls
  bulls = 0;
  cows = 0; // reset bulls and cows to 0 after each iteration
//failure to do so keeps storing bulls and cows, resetting to 0 in lower portion causes infinite loop
  do { // do while loop is used to take user guess, it is error checked and repeated until the input is appropriately sized and contains no repeats
    cout << "Enter your guess as an integer number (no repeat digits), if you do not have the appropriate amount of digits, leading zeros will be added: ";
    double userGuessTemp = 0.0; // using double because a user will break code if entering floating point value for guess when datatype is an integer
    cin >> userGuessTemp;
    while(userGuessTemp < 0.0){
        cout << "Enter a positive number as the guess: "; // dont accept negative guess
        cin >> userGuessTemp;
    }
    unsigned int userGuess = static_cast<int>(userGuessTemp); // convert to int for game
    /* digit slice the guess and place it in the guess vector. The vector will be loaded from
    back to front so that the there are leading zeros if the user guess is not of the correct size
    in terms of digits */
    unsigned int j = numDigitsInt - 1;
    unsigned int numberOfDigits = 0;
    // make sure that the the guess doesn't have too many digits for the vector:
    unsigned int numDigitsGuess = 0;
    unsigned int temp = userGuess;
   // bool repeat = false; // used to control do while loop until valid user guess is chosen
    while(temp != 0){
        numDigitsGuess++; // count digits  in user's guess
        temp /= 10;
    } // end digit counting while loop
    if(numDigitsGuess > guess.size()){ // guess vector has size of gen code vector, compare it with number of digits in guess
        cout << "Enter a guess that has the same, or less, number of digits as the chosen game code: ";
        cin >> userGuessTemp; // executes if too many digits in guess numbered
        userGuess = static_cast<int>(userGuessTemp);
    }
    // load guess vector
    // repopulate guess vector with 0 so that leading 0s will be added if the number of digits in the guess is less than the chosen size
    for(unsigned int i = 0; i < numDigitsInt; ++i){ // numDigitsInt is the chosen number of digits for game code
        guess.at(i) = 0;
    }
    while(userGuess != 0 && j >= 0){
        guess.at(j) = userGuess % 10; // peel off back digit and place in vector from back to front
        userGuess /= 10; // update loop variable
        --j; // update loop/vector index variable

    } // end guess vector loading while loop

   // display user guess
    cout << "The current user guess is: ";
    for(int i = 0; i < guess.size(); ++i){
        cout << guess[i];
    }
    cout << endl;

    // check for repeat digits in user guess vector and get new guess if there is one
     repeat = false; // signifies repeat value in guess
    for(unsigned int i = 0; i < guess.size() - 1; ++i ){
        for(unsigned int j = i + 1; j < guess.size(); ++j){
            if(guess.at(i) == guess.at(j)){
                repeat = true;
                break; // exit loop if repeating digit is found
            } // end if
        } // end inner loop, that checks for repeat digits in user guess
    } // end outer loop, checks for repeats
  } while(repeat); // end user guess input, loading, and validation loop

  // game, check for bulls and cows

  for(unsigned int i = 0; i < guess.size(); ++i){
      if(guess.at(i) == genCode.at(i)){
          bulls += 1; // if the correct value is at the correct digit you have a bull
      }
  }
  // use a nested loop to check for cows
  for(unsigned int j = 0; j < guess.size(); ++j){
      for(unsigned int k = 0; k < guess.size(); ++k){
          if(guess.at(j) == genCode.at(k)){
              cows++; // bulls are inadvertently calculated here too
          }
      }
  }
    cows = cows - bulls; // remove the double counted bulls and you have cows

    // create option to leave game without completing it
    cout << "With this guess you have " << bulls << " bulls" << " and " << cows << " cows" << endl;
    if(bulls == guess.size()){ // executes when game is over
        cout << "Congratulations you have won! Rerun to play again! " << endl;
        break; // leave games infinite while loop
    }

    char leave = 'a';
    cout << "If you wish to exit the game, press q or Q, to continue press any other character (you can't win if you quit): ";
    cin >> leave;
    if(leave == 'q' || leave == 'Q'){
        quit = true; // used for end game output statements
        break; // leave games infinite while loop
    }


} // end bulls and cows game while loop

if(quit){ // executes if player quits before winning
    cout << "You quit the game, rerun to play again." << endl;
}
  return 0;
}
