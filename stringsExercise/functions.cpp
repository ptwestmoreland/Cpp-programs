# include "functions.h"
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {

}

void wordFilter()
{
  /* get a multiword input string and a filter word. At every occurence of
  the filter word, replace it with hashtags */
  string userIn = "";
  string filterWord = "";
  cout << "Please enter the sentence: ";
  getline(cin, userIn);
  cout << "Please enter the filter word: ";
  cin >> filterWord;
  unsigned int indxOfFirstOccurence = 0;
  string replaceMentWord = filterWord; // initialize it
  for(unsigned int i = 0; i < replaceMentWord.length(); ++i)
  {
    replaceMentWord.at(i) = '#'; // replace filter with this sequence

  }
  while(userIn.find(filterWord) != string::npos){
    indxOfFirstOccurence = userIn.find(filterWord);
    userIn.replace(indxOfFirstOccurence, filterWord.length(), replaceMentWord);
  }
  cout << "Filtered sentence: " << userIn << endl;
}

void passwordConverter() {
    /* take common characters found in a password (vowels) and replace them with less
    common characters for security then append reversed version to new password */
    string userPass = "";
    string newPass = "";
    cout << "Please enter your text input: ";
    getline(cin, userPass);
    newPass = userPass; // reset string to replace characters
    for(unsigned int i = 0; i < userPass.size(); ++i)
    {
      // only 1 sel block below executes for a given i
      if(newPass.at(i) == 'a')
      {
        newPass.at(i) = '@';
      }
      if(newPass.at(i) == 'e')
      {
        newPass.at(i) = '3';
      }
      if(newPass.at(i) == 'i')
      {
        newPass.at(i) = '!';
      }
      if(newPass.at(i) == 'o')
      {
        newPass.at(i) = '0';
      }
      if(newPass.at(i) == 'u')
      {
        newPass.at(i) = '^';
      }

    } // end for loop

    string reversedPass = newPass;
    unsigned int j = newPass.size() - 1;
    for(unsigned int i = 0; i < reversedPass.size(); ++i){
      reversedPass.at(i) = newPass.at(j);
      j -= 1;
    }
    cout << "input: " << userPass << endl; // output original password
    newPass.append(reversedPass);
    cout << "output: " << newPass << endl;


}

void wordCalculator() {
    // TODO
}

void palindromeCounter() {
    // TODO
}
