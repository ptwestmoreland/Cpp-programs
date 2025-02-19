#include "Student.h" // by convention
using namespace std; // using directives okay in source files

//bool compare(const STUDENT &e1, const STUDENT &e2) { return e1.score < e2.score; }


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

bool compare(const STUDENT &e1, const STUDENT &e2) { return e1.score < e2.score; }
