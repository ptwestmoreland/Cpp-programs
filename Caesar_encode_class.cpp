
#include <iostream>
#include <string>

/* this class allows a user to send in an input word and have it encoded via the Caesar cipher

This exercise need not be done with a class, I am just trying to get some practice with object oriented programming

 Im using a hand set shift key of 4, but in practice the key should be user set and that is easily done  */
class encoded_word{
    
    private:
    string userInput;
    string encodedOutput;
    
    public:
    encoded_word();
    string encode_word(string input);
    
    
};
// public member function definitions 

encoded_word::encoded_word(){
    userInput = ""; // constructor initialization of object 
    encodedOutput = "";
}
string encoded_word::encode_word(string input){
    // this public function recieves an input from main and alters it with the Caesar cipher method 
    encodedOutput = input; // set encoded output to what ever is sent in from main 
    // shift each alphabetic character down by 4 units
    
    // convert string to all lower case and make sure the input string is alphabetic  
    
    for(unsigned int i = 0; i < input.size(); ++i){
        if(isalpha(encodedOutput.at(i))){
            
            
              encodedOutput.at(i) = tolower(encodedOutput.at(i)); 
                
         }
        else{
            throw std::invalid_argument("String must have only alphabetic characters.");
        }
    }
    for( unsigned int i = 0; i < input.size(); ++i){
        // string has been checked for alphabetics characters at this point 
        if(encodedOutput.at(i) <= 'v') { // if the character is "greater" than z, then we get a non alphabetic letter when shifting
           encodedOutput.at(i) = encodedOutput.at(i) + 4; // shift 4 letters down 
    } // end if for letters that can be shifted by 4 without a wraparound 
        else{     // some letter is greater than v 
            // say a letter is z, it should be shifted from z -> d by wrapping back around 
            encodedOutput.at(i) = encodedOutput.at(i) - 'w' + 'a'; // takes care of shift to non alphabetic characters with key of 4
        }
    
 } // end for loop 
 
 return encodedOutput; 

} // end encode_word function 


int main()
{
    // testing 
    string userIn = "";  
    std::cin >> userIn;
    encoded_word practice_word;
     
     string x = practice_word.encode_word(userIn);
     std::cout << x << std::endl;
     
     

    return 0;
}
