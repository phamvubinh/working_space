/* Test Driver for the Author class (TestAuthor.cpp) */
#include "Author.h"

int main()
{
   // Declare and construct an instance of Author
   Author peter("Peter Jones", "peter@somewhere.com", 'm');
   peter.print();
      // Peter Jones (m) at peter@somewhere.com
   peter.setEmail("peter@xyz.com");
   peter.print();
      // Peter Jones (m) at peter@xyz.com

   Author paul("Paul Jones", "@somewhere.com", 'n');
      // Invalid email! Set to empty string.
      // Invalid gender! Set to 'u' (unknown).
   paul.setEmail("paul@");
      // Invalid email! Set to empty string.
   paul.print();
      // Paul Jones (u) at
}