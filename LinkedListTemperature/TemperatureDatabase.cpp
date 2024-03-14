#include "TemperatureDatabase.h"
#include <sstream>
#include <fstream>

using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

// function reads id month year temperature from in file stream

  void TemperatureDatabase::loadData(const string& filename) {
  ifstream inFS(filename);
 if(!inFS.is_open()){
   cout << "Error: Unable to open " << filename << ".dat" << endl;

 }
  while(!inFS.eof()){

    	 int month = 0;
    	int year = 0;
    	string fullline = "";
    	double temperature = 0.0;
    	string id = "";
    inFS >> id;
    inFS >> year;
    inFS >> month;
    inFS >> temperature; // split at spac
    if(inFS.fail()){
      cout << "Error: Other invalid input" << endl;
    }
    bool track = 0;
    if(year < 1800 || year > 2022){
      track = 1;
      cout << "Error: Invalid year " << year << endl;

    }
    if(month < 1 || month > 12){
      track = 1;
      cout << "Error: Invalid month " << month << endl;

    }
    if(temperature > 50.0 || temperature < -50.0){
        cout << "Error: Invalid temperature " << temperature << endl;
        track = 1;
    }
    if(temperature != -99.99){
      if(!track){
        records.insert(id,year,month,temperature);
      }
    }

  }

} // end load file/ get input function

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename); // filename;

	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

/*void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
} */
