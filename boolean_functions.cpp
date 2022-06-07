#include "boolean_functions.h"

#include <iostream>

using std::cin, std::cout, std::endl;

void booleanLogic1()
{
  //displays truth table for not operator
    cout << "--- Boolean Logic 1 ---" << endl;


    cout << " x | NOT x" << endl;
    cout << "---+-------" << endl;
    cout << " 0 |   1" << endl;
    cout << " 1 |   0" << endl;

    cout << endl;
}

void booleanLogic2()
{ // displays truth table for OR operation
    cout << "--- Boolean Logic 2 ---" << endl;

    cout << " x | y | x OR y" << endl;
    cout << "---+---+--------" << endl;
    cout << " 0 | 0 |   0" << endl;
    cout << " 0 | 1 |   1" << endl;
    cout << " 1 | 0 |   1" << endl;
    cout << " 1 | 1 |   1" << endl;

    cout << endl;
}

void booleanLogic3()
{  //displays truth table for AND operation
    cout << "--- Boolean Logic 3 ---" << endl;

    cout << " x | y | x AND y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    0" << endl;
    cout << " 1 | 0 |    0" << endl;
    cout << " 1 | 1 |    1" << endl;

    cout << endl;
}

void booleanLogic4()
{  // displays truth table for XOR operation
    cout << "--- Boolean Logic 4 ---" << endl;

    cout << " x | y | x XOR y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    1" << endl;
    cout << " 1 | 0 |    1" << endl;
    cout << " 1 | 1 |    0" << endl;

    cout << endl;
}

void booleanLogic5()
{
    cout << "--- Boolean Logic 5 ---" << endl;

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = false; //output x OR y OR z, given boolean variables x,y,z
    value = x | y | z; //just 1 bit so bitwise will give correct output
    cout << x << " OR " << y << " OR " << z << " = " << value << endl;

    cout << endl;
}

void booleanLogic6()
{
    cout << "--- Boolean Logic 6 ---" << endl;

    // computes logical x AND y AND Z given through boolean variables x,y,z

    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = false; // holds value of boolean operation
    value = x & y & z;
    cout << x << " AND " << y << " AND " << z << " = " << value << endl;

    cout << endl;
}

void booleanLogic7()
{
    cout << "--- Boolean Logic 7 ---" << endl;
    // computes and displays result of boolean operation x XOR y XOR z
    bool x, y, z;
    cout << "Enter 0 or 1 values for x, y, and z: ";
    cin >> x >> y >> z;
    bool value = false; // holds result of boolean operation
    value = x ^ y ^ z;
    cout << x << " XOR " << y << " XOR " << z << " = " << value << endl;

    cout << endl;
}
