/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section:
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.text
content: The text file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli

*******************************************************************************/
#include <iostream>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;

int main()
{
    // TODO: create arrays needed
    double* timearr[SIZE] = new double[9];
    string countrarr[SIZE];
    unsigned int numarr[SIZE];
    string namearr[SIZE];
    unsigned int rankarr[SIZE]; // no pointer required

    // TOTO: prep all arrays

prep_double_array(timearr);
prep_string_array(countrarr);
prep_unsigned_int_array(numarr); // jersey numbers
prep_string_array(namearr);
prep_unsigned_int_array(rankarr);

    // TODO: prompt until both the file and the contained data are valid

    string file_name = "";
    bool continue2 = 1;
    while(continue2){
        cout << "Enter file name: ";
        cin >> file_name;
        if(file_name.at(file_name.size() - 1) != 't'){ //.txt files only
            continue2 = true;
            //continue;
        }
        // test for valid file and data
        try{
            get_runner_data(file_name,timearr,countrarr,numarr,namearr);
            continue2 = 0;
        } // end try
        // catch errors
        catch(const std:: invalid_argument& ia){
            cout << "Invalid File: " << ia.what() << endl;// file didnt open
          continue2 = true;
        }
				catch(const std:: domain_error& other){
					cout << "Invalid File: " << other.what() << endl; // other exceptions
         continue2 = true;
				}


    } // end while loop

         get_ranking(timearr,rankarr);
        print_results(timearr,countrarr,namearr,rankarr);

    return 0;
}
