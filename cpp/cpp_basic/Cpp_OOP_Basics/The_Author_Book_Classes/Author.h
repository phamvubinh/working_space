/* Header for the Author class (Author.h) */
#ifndef __AUTHOR_H__
#define __AUTHOR_H__

#include <string>
using namespace std;

class Author
{
private:
   string name;
   string email;
   char gender;   // 'm', 'f', or 'u' for unknown

public:
   Author(string name, string email, char gender);
   string getName() const;
   string getEmail() const;
   void setEmail(string email);
   char getGender() const;
   void print() const;
};

#endif