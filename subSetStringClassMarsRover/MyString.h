#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <iostream>
using namespace std;

class MyString
{
  private:
    char* dataM; // pointer to char data
    size_t sizeM; // track size and capacity of object
    size_t capacityM;
  public:
    MyString(const char *str = nullptr); // defines default and c string constructor w default param
    MyString(const MyString& str); // copy constructor
    ~MyString(); // destructor
    void resize(size_t n);
    size_t capacity() const noexcept;
    size_t size() const noexcept;
    size_t length() const noexcept;
    char* data() const noexcept; // getter
    bool empty() const noexcept;
    const char& front() const;
    char& at(size_t pos) const;
    void clear() noexcept;
    friend ostream &operator << (ostream& os, const MyString& str);
    MyString& operator=(const MyString& str);  // change data type to string and test
    MyString& operator+= (const MyString& str);
    size_t find(const MyString& str, size_t pos = 0) const noexcept; // sets default position
    friend bool operator==(const MyString& rhs, const MyString& lhs);
    friend MyString operator+(  MyString& rhs, MyString& lhs);
}; // end class definition

#endif // end of header file
