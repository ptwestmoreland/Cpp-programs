# include "Passport.h"

using std::string, std::vector;

// constructor/ initiailzation list

StatePark::StatePark(std::string parkName, double entranceFee, double trailMiles) : parkName(parkName), entranceFee(entranceFee),trailMiles(trailMiles),camperLog({}){} // camperLog is a vector

string StatePark::getParkName()
{


	return parkName;
}

double StatePark::getEntranceFee() {


	return entranceFee;
}

double StatePark::getTrailMiles() {
	// TODO: implement getter

	return trailMiles;
}

void StatePark::addCamper(Passport* camper) {
	INFO(camper)

	camperLog.push_back(camper);

	return;
}

double StatePark::getRevenue() {
	// TODO: implement function

	return 0.0;
}
