
#include <string>
using std:: string;
#ifndef TEMPERATUREDATA
#define TEMPERATUREDATA

struct TemperatureData {
	// private data members
	string id;
	int year;

	int month;
	double temperature;
	TemperatureData();
	TemperatureData(std::string id, int year, int month, double temperature);
	virtual ~TemperatureData();
	bool operator<(const TemperatureData& b);
};

#endif /* TEMPERATUREDATA */
