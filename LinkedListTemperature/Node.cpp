#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node(): next(NULL) {} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature): next(NULL) {
 TemperatureData in(id, year, month, temperature);  //initisl data and next
 data = in;

}


bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
