#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <queue> // for priority queue
#include <algorithm> // for sort

using namespace std;


// using namespace std; // don't pollute :)

class STUDENT {
public:

    STUDENT() : Fname("null"), Lname("null"), score(0) {} // initializer lists
    STUDENT(std::string fname, std::string lname, int pts) : Fname(fname), Lname(lname), score(pts) { }
    std::string Fname;
    std::string Lname;
    size_t score;

    // mutators
    void setFname(std::string x) { Fname = x; } // use inline when possible, no source!
    void setLname(std::string x) { Lname = x; }
    void setScore(size_t x) { score = x; }

    // accessors
    std::string getFname() const { return Fname; }
    std::string getLname() const { return Lname; }
    size_t getScore() const { return score; }

    // CUSTOM overloaded operators
    const STUDENT &operator = (const STUDENT &source);
    bool operator != (const STUDENT &source) { return !(score == source.score); }
    bool operator == (const STUDENT &source)
    { return (score == source.score) && (Fname == source.Fname) && (Lname == source.Lname); }
    bool operator < (const STUDENT &source) const { return score < source.score; }

    // friends are not a declaration, just a notice that it will be accessing private data members
    friend bool compare(const STUDENT &e1, const STUDENT &e2);
    // CUSTOM friend overloaded streams
    friend std::ostream &operator << (std::ostream &out, const STUDENT &x);
    friend std::istream &operator >> (std::istream &in, STUDENT &x);
};

// all "friend" functions declared
bool compare(const STUDENT &e1, const STUDENT &e2);
// declaration that the compiler sees when called
std::ostream &operator << (std::ostream &out, const STUDENT &x);
std::istream &operator >> (std::istream &in, STUDENT &x);

#endif

ostream &operator << (ostream &out, const STUDENT &x)
{
    // out << x.getFname() << endl; --> will not work
    out << x.Fname << endl;
    out << x.Lname << endl;
    out << x.score << endl;
    return out;
}

const STUDENT & STUDENT::operator = (const STUDENT &source)
{
    if (this == &source) // this is a self assignment checker
    { return *this; }   // returns the pointer to the current object
    // otherwise copy

    //new-instance now = source instance
    Fname = source.Fname;
    Lname = source.Lname;
    score = source.score;

    return *this; // returns previously empty instance
}

istream &operator >> (istream &in, STUDENT &x)
{
    // temp variables
    string TempF, TempL;
    int TempScore;

    cout << "Enter First Name:" << endl;
    in >> TempF;
    cout << "Enter Last Name:" << endl;
    in >> TempL;
    cout << "Enter a score for this student:" << endl;
    in >> TempScore;

    x.setFname(TempF);
    x.setLname(TempL);
    x.setScore(TempScore);
    return in;
}

bool compare(const STUDENT &e1, const STUDENT &e2) {
  return e1.score < e2.score;
}

bool compare2(const STUDENT &e1, const STUDENT &e2) {
  return e1.Fname < e2.Fname; 
}

int main()
{
    // Step 2a
    priority_queue <STUDENT> teachers_pets;

    // Step 2b
    // created new constructor and used for below
    STUDENT temp1a("Jonathan", "Laney", 75);

    STUDENT temp2a("Walter", "Henry", 100);
    STUDENT temp3a("Justin", "Hill", 95);
    STUDENT temp4a("Tim", "Burke", 10);
    STUDENT temp5a("Justin", "Taylor", 90);

    // Step 2c
    teachers_pets.push(temp1a);
    teachers_pets.push(temp2a);
    teachers_pets.push(temp3a);
    teachers_pets.push(temp4a);
    teachers_pets.push(temp5a);

    // Step 2d
    cout << teachers_pets.top() << endl; // overloaded the cout

    // Step 2a
    vector <STUDENT> * CMSC341 = new vector<STUDENT>;

    // Step 2b
    // created new constructor and used for below

    // Step 2c
    CMSC341->push_back(temp1a);
    CMSC341->push_back(temp2a);
    CMSC341->push_back(temp3a);
    CMSC341->push_back(temp4a);
    CMSC341->push_back(temp5a);

    // Step 2d
    cout << CMSC341->front() << endl; // overloaded the cout

    // WHY???????????????? :(
    //sort(CMSC341->begin(), CMSC341->end(), compare);
    sort(CMSC341->begin(), CMSC341->end());

    cout << "Printing in sorted order" << endl;
    // print to see if ok
    for (vector<STUDENT>::const_iterator i = CMSC341->begin(); i != CMSC341->end(); ++i)
    { cout << (*i) << endl; }


    //  sort(CMSC341->begin(), CMSC341->end(), compare);
    sort(CMSC341->begin(), CMSC341->end(), compare);
    // sort(CMSC341->begin(), CMSC341->end(), compare);

    cout << "Printing in sorted order AGAIN" << endl;
    // print to see if ok
    for (vector<STUDENT>::const_iterator i = CMSC341->begin(); i != CMSC341->end(); ++i)
    { cout << (*i) << endl; }


    return 0;
}
