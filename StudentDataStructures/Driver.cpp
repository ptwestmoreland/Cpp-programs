/*
 * compiles with
 *        g++ *.cpp
 * -stds 98, 11, 14, 17 all work.
 */

#include <string>
#include <iostream>
#include <queue> // for priority queue
#include <algorithm> // for sort

using namespace std;

#include "Student.h"

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
   // add one more student
   STUDENT temp6a("Jerrel", "Hemmen", 40);
    // Step 2c
    teachers_pets.push(temp1a);
    teachers_pets.push(temp2a);
    teachers_pets.push(temp3a);
    teachers_pets.push(temp4a);
    teachers_pets.push(temp5a);
    teachers_pets.push(temp6a);

    // Step 2d
    cout << teachers_pets.top() << endl; // overloaded the cout

    // Step 2a
    vector <STUDENT> * CMSC341 = new vector<STUDENT>;

    // Step 2b add a few students

    // created new constructor and used for below

    // Step 2c
    CMSC341->push_back(temp1a);
    CMSC341->push_back(temp2a);
    CMSC341->push_back(temp3a);
    CMSC341->push_back(temp4a);
    CMSC341->push_back(temp5a);
    CMSC341->push_back(temp6a);

    // Step 2d
    cout << CMSC341->front() << endl; // overloaded the cout

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
