#include <stdexcept>
#include "MyString.h"
using namespace std;


void memcopy(char* out, const char* in, size_t length);
int cont(const char *string1, const char *string2, std::size_t length);

// constructor definitions
MyString::MyString(const char *str)
{
     this->dataM = nullptr;
     this->sizeM = 0;
     this->capacityM = 1;
     if(str != nullptr)
     {
     const char* temp = str;
      size_t length = 0;
      while (*str != '\0')
      {
        length++;
        str++;
      }
      str = temp;
       this->sizeM = length;
       capacityM = 1 + length;
     }
     this->dataM = new char[this->capacityM]; // declare char arr
     memcopy(this->dataM,str,this->sizeM);
     this->dataM[this->sizeM] = '\0'; // null terminal at size - 1 + 1
} // end char/default constructor

MyString::MyString(const MyString& str)
{
  this->dataM = new char[str.capacityM];
  this->sizeM = str.sizeM;
  this->capacityM = str.capacityM;
   memcopy(dataM, str.dataM, sizeM);
}

// destructor
MyString::~MyString()
{
  this->capacityM = this->capacityM - this->capacityM;
  this->sizeM = this->sizeM - this->sizeM;
  delete [] this->dataM; // deallocate
}

// public member function definitions
void MyString::resize(std::size_t n)
{
  if(n >= capacityM) // size increase
  {
    char* data2 = new char[n]; // declare size n dynamic char array
    memcopy(data2, this->dataM, n); // copy over
    delete[] this->dataM; // deallocate
    this->dataM = data2; // change what private data member points to, now points to resized array
    return; // break from function
  }
  // executes if new size is smaller than previous
  this->sizeM = 0;
  this->sizeM = n;  // update size
  this->dataM[this->sizeM] = '\0'; // deletes extra spaces
} // end resize

size_t MyString::capacity() const noexcept
{
  return this->capacityM;
}
size_t MyString::size() const noexcept
{
  return this->sizeM;
}
size_t MyString::length() const noexcept
{
  return this->sizeM;
}
char* MyString::data() const noexcept {
  return this->dataM;
}
bool MyString::empty() const noexcept
{
  if(this->sizeM != 0)
  {
    return false;
  }
  return true;

} // end empty()

 const char& MyString::front() const {

  return *dataM;
}

  char& MyString::at(size_t pos) const
{

  if(this->sizeM <= pos)
  {
    throw std::out_of_range("position is out of rnage");
  }
  return this->dataM[pos];
}

void MyString::clear() noexcept
{
  this->dataM[0] = '\0'; // erases char array
  this->sizeM = 0; // update data member

}

ostream& operator << (ostream& os, const MyString &str)
{
    os << str.dataM;
    return os;
}

MyString& MyString::operator=(const MyString& str)
{
  if(this != &str)
  {
    this->sizeM = str.sizeM;
    if (sizeM > capacityM) {
      capacityM = sizeM + 1;

      size_t newCap = this->capacityM;
      char* data2 = new char[newCap];
      delete[] this->dataM;
      this->dataM = data2;
      newCap = 0;
    }
    memcopy(this->dataM, str.dataM , this->sizeM);
    this->dataM[this->sizeM] = '\0';
    return *this;
  }

  return *this;
} // end op overload =

MyString& MyString::operator+= (const MyString& str)
{
   size_t length = str.sizeM;
   if(this->sizeM + length > this->capacityM) // resize call or manual
   {
     this->capacityM = this->sizeM + length + 1;
     size_t newCap = this->capacityM;
     char* data2 = new char[newCap];
     newCap = 0;
     memcopy(data2, this->dataM, this->sizeM);
     delete[] this->dataM;
     this->dataM = data2;
   }

   memcopy(dataM + sizeM, str.dataM, length);
   this->sizeM = this->sizeM + length;
   dataM[sizeM] = '\0';

   return *this;

}

size_t MyString::find(const MyString& str, size_t pos) const noexcept
{
    size_t length = str.sizeM;
    if(length != 0)
    {

      size_t j = pos;
      //bool allEqual = true;
      while(j <= this->sizeM - length){
        if(cont(this->dataM + j, str.dataM, length) == 0)
        {
          return j;
        }

        j = j + 1;
      }

  }
  return -1; // not found
}
bool operator==(const MyString& rhs, const MyString& lhs)
{
    if(rhs.size() == lhs.size())
    {
      for(size_t i = 0; i < rhs.size(); ++i)
      {
        if(rhs.at(i) != lhs.at(i)){
          return false;
        }
      }
    }
    else
    {
      return false;
    }
  return true;
}
 /*MyString operator+(  MyString& rhs, MyString& lhs)
 {

 } */
// helper function declarations that are used in member functions

int cont(const char *string1, const char *string2, std::size_t length)
{
  std::size_t i = 0;
  while(i < length)
  {
    if(string2[i] != string1[i])
    {
      if(string1[i] > string2[i])
      {
        return 5;
      }
      else if(string1[i] < string2[i])
      {
        return -5;
      }
    } // end if

    i += 1;
  } // end while
  return 0;
}
void memcopy(char* out, const char* in, std::size_t length)  // copy over
{
   std::size_t i = 0;
   while(i < length)
   {
     out[i] = in[i]; // copy over
     i += 1;
   }
} // end mem copy
