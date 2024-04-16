# include "Passport.h"

using std::string, std::vector;

// constructor using member initializer list

Passport::Passport(std::string camperName, bool isJuniorPassport) : camperName(camperName), isJuniorPassport(isJuniorPassport), parksVisited({}){} // parksVisited is vector

string Passport::getCamperName()
{
  return camperName; // return private data member
}

bool Passport::checkJuniorPassport() {

	return isJuniorPassport;
}

void Passport::addParkVisited(StatePark* park) {
	INFO(park)
  parksVisited.push_back(park);
	park->addCamper(this); // this is pointer to current Passport object
  return;
}

double Passport::getMilesHiked() {

	return 0.0;
}

int Passport::getHikerLevel() {

	return 0;
}
