#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

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
    // second compare function
    friend bool compare2(const STUDENT &e1, const STUDENT &e2);

    // CUSTOM friend overloaded streams
    friend std::ostream &operator << (std::ostream &out, const STUDENT &x);
    friend std::istream &operator >> (std::istream &in, STUDENT &x);
};

// all "friend" functions declared
bool compare(const STUDENT &e1, const STUDENT &e2);
bool compare2(const STUDENT &e1, const STUDENT &e2);
// declaration that the compiler sees when called
std::ostream &operator << (std::ostream &out, const STUDENT &x);
std::istream &operator >> (std::istream &in, STUDENT &x);

#endif
