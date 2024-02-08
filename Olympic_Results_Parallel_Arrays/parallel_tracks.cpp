#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include<fstream>
#include <cctype>

#include "parallel_tracks.h"
using namespace std;


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the text file given
//---------------------------------------------------------
void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[],
unsigned int numberArray[], std::string lastnameArray[])
{
    /* function goes line by line through a file that is spaced as time country number lastName
    these entries are processed as strings, tested for conditions, their types are then converted if
    needed and they are placed in parallel arrays */
  string lastName = ""; // stores runner last name and palces in array
  string country = ""; // stores 3 letter country and places in array
  double timeentry = 0.0; // stores time entry to be put into time array
  int fileNum = 0; // stores integer # assosciated with competitor, places in array
  string linestring = ""; // holds entire line being read in from file
  std::ifstream inFS; // declare file data type
  inFS.open(file); // attempt to open file that is passed to function
  string strnum = ""; // stores number as string
  string timestring = ""; // stores time as string, convert later
  unsigned int j = 0; // holds index to store in array of loop


  unsigned int digits = 0;
  int number1 = 0;
  unsigned int number2 = 0;
  if(!inFS.is_open()){ // executes when is open returns false (file isnt open)
      throw std:: invalid_argument("Cannot open file");
  }
  // go here if file.is_open = TRUE


      while(!inFS.eof()){ // go line by line and store all data in linestring throughout whole file
         getline(inFS,linestring); // store line up to '\n' in linestring variable
          if(linestring.empty() && j <= 8){ // check for empty string and not last line
              throw std:: domain_error("File missing data");
          }
          else if(linestring.empty()){ // executes if !(j <= 8)
              break; // exit loop if on last line and its empty
          }
          stringstream inSS(linestring); // store line in istringstream for processing



/*string lastName = "";
  string country = "";
  double timeentry = 0.0;
  unsigned int fileNum = 0;
  string strnum = "";
  string timestring = "";  */ // for my usage so that I dont have to scroll to top while processing line
        // process time as string
        inSS >> timestring; // stops at space to next entry in file
        if(inSS.fail()){ // executes if failbit is set and there is a processing error
            throw std:: domain_error("File contains invalid data (time)");
        }
        if(timestring.empty()){
            throw std:: domain_error("File contains invalid data (time)"); // might need invalid data (time)
        }
        trim(timestring); // trim whitespace
     int decimalcount = 0;
     for(unsigned int i = 0; i < timestring.size(); ++i){
       if(timestring.at(i) == '.'){
         decimalcount++;
       }
     }
     if(decimalcount > 1){
       throw std:: domain_error("File contains invalid data (time)");

     }



        // convert timestring to double
        timeentry = std::stod(timestring);
        // check other points for valid time requirements

        // entry must be non zero positive number
        if(!((timeentry > 0.0) || (timeentry == 0.0))) {  // c math not allowed so I will directly compare a floating point value
            throw std:: domain_error("File contains invalid data (time)");
        }
       else if(timeentry < 0.00000000000001){
            if(timeentry > 0){ // nested if
                throw std:: domain_error("File contains invalid data (time)"); // might be file missing
            }
        }
       // process country string from linestring
       inSS >> country;
       if(inSS.fail()){ // executes if failbit is set and there is a processing error
         throw std:: domain_error("File contains invalid data (country)");
        }
    //   trim(country); // trim leading and ending whitespace

       // country conditions, must be 3 CAPITAL letters
      if(country.empty()){
          throw std:: domain_error("File contains invalid data (country)");
      }
      for(unsigned int i = 0; i < country.size(); ++i){
          if(isalpha(country.at(i))){
              if(isupper(country.at(i))){
                  continue; // executes if we have an alphabetic uppercase character
              }
              else{ // lower case alphabetic character
                  throw std:: domain_error("File contains invalid data (country)");
                  break;
              }
          }
          else{ // non alphabetic character
              throw std:: domain_error("File contains invalid data (country)");
              break;
          }
      } // end for loop
      if(country.size() != 3){ // must be 3 characters, empty string test above is now redundant
          throw std:: domain_error("File contains invalid data (country)");
      }
      // process number part of file
      // num is read in as string
      inSS >> strnum; //inSS = input string stream

        if(inSS.fail()){ // executes if failbit is set and there is a processing error
          throw std:: domain_error("File contains invalid data (number)");
        }

      //  trim(strnum);
        // convert to int and check conditions

        fileNum = std::stoi(strnum); // convert
       if(fileNum < 0){ // must be positive
            throw std:: domain_error("File contains invalid data (number)");
        }
        // must be 1 - 2 digits 1 - 99, could use direct comparison but im number slicing
        digits = 0;
        number1 = fileNum;
        while(number1 != 0){
            number1 %= 10;
            number1 /= 10;
            digits++;
        }

       if(digits < 1 || digits > 2){
            throw std:: domain_error("File contains invalid data (number)");
        }

       number2 = fileNum; // will use this for array, if we get to here then the num is positive
     // process last name
     inSS >> lastName;
     if(inSS.fail()){
         throw std:: domain_error("File contains invalid data (name)");
     }
     trim(lastName);
     if(lastName.empty()){
         throw std:: domain_error("File contains invalid data (name)");
     }
     // check for upper and lowercase alphabetic letters and space

     for(unsigned int i = 0; i < lastName.size(); ++i){
         if(isalpha(lastName.at(i)) || isspace(lastName.at(i))){
             continue;
         }
         else{
             throw std:: domain_error("File contains invalid data (name)");
             break;
         }
     } // end for loop
     // must be more than one character in length
     if(!(lastName.size() > 1)){
         throw std:: domain_error("File contains invalid data (name)");
     }

     // store valid values in arrays
     timeArray[j] = timeentry;
     countryArray[j] = country;
     numberArray[j] = number2;
     lastnameArray[j] = lastName;

     j++; // goto next line

 } // end while loop to process file
inFS.close();
} // end function get runner data
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{

  for(unsigned int i = 0; i < SIZE; ++i){
      ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an unsigned int arrays is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	for(unsigned int i = 0; i < SIZE; ++i){
	    ary[i] = 0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	for(unsigned int i = 0; i < SIZE; ++i){
	    ary[i] = "N/A";
	}
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
// input time array, lowest time rank is one, highest is 9
double tarry[9];
unsigned int i = 0;
unsigned int rank = SIZE;
while(i < SIZE){
  tarry[i] = timeArray[i]; // store copy of time array
  ++i;
}
while(rank > 0){
  double high = 0;
  unsigned int high_indx = 0;
  for(unsigned int k = 0; k < SIZE; ++k){
    if(tarry[k] > high){
      high_indx = k;
      high = tarry[k];

    }

  } // end for loop
  rankArray[high_indx] = rank;
  tarry[high_indx] = 0.0;
  rank--;
} // end outer loop


}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;

	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{

		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}


			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl;
			}

		}
	}
}

std::string trim(std::string ret) {
	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}

	return ret;
}
