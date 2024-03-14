#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() :  head(NULL), tail(NULL)// constructor
{

}

LinkedList::~LinkedList() { // destructor
	clear(); // call to clear
}

LinkedList::LinkedList(const LinkedList& source) { // copy
  Node* x1;
	tail = nullptr;
	head = nullptr;

	x1 = source.head;
	if(x1 != nullptr){
	while(x1 != nullptr){ // go through list
		TemperatureData& data = x1 -> data;
		insert(data.id,data.year,data.month,data.temperature);
		x1 = x1 -> next;
	}
}

}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	clear();
	Node* x1;
	x1 = source.head;
	if(x1 != nullptr){
	while(x1 != nullptr){ // go through list
		TemperatureData& data = x1 -> data;
		insert(data.id,data.year,data.month,data.temperature); // call to insert defined below
		x1 = x1 -> next;
	}
}
	return  *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {

	Node* newnode = new Node(location, year, month, temperature);
  if((head != NULL)){
		Node* curr = head;
		Node* tai = NULL;
		while(curr != NULL){
			if(newnode->data.id < curr->data.id){
				break;
			}
			else if(curr->data.id==newnode->data.id && curr->data.year > newnode->data.year){
				break;
			}
			else if(curr->data.year == newnode->data.year && curr->data.month >= newnode->data.month){
				break;
			}
			else{
			tai = curr;
			curr = curr->next; // loop condition

			}
		}
		if(curr == head){
			newnode->next = head;
			head = newnode;
		}
		else{
			newnode->next = curr;
			tai->next = newnode;
		}
	}

	else if(head == NULL){
       head = newnode;
	}


} // end function insert


void LinkedList::clear() {
	// loop through and delete list
	while(head != NULL){
		Node* temporary_point = head -> next;
		delete head; // dell
		head = temporary_point;
	}
}

Node* LinkedList::getHead() const {
	// return head
	Node* x1 = head;
	return x1;
}

string LinkedList::print() const {
string out = "";
Node* curr;
curr = head;
/*while(curr!= NULL){
	stringstream ss;
	ss << curr->data.year << " " << curr->data.month << " " << curr->data.temperature;
	string t = ss.str();
	out = out + curr->data.id + " " + t + "\n";
	curr= curr ->next;
} */

stringstream oss;
while(curr != NULL){ // nullptr
	oss << curr->data.id << " " << curr->data.year << " " << curr->data.month << " " << curr->data.temperature << std::endl;
	curr = curr -> next;  // next node
}
out = oss.str(); // convert
return out;
}
ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
