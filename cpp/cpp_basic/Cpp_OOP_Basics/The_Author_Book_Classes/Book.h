/* Header for the class Book (Book.h) */
#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>
#include "Author.h"   // Use the Author class
using namespace std;

class Book
{
private:
   string name;
   Author author; // data member author is an instance of class Author
   double price;
   int qtyInStock;

public:
   Book(string name, Author author, double price, int qtyInStock = 0);
      // To recieve an instance of class Author as argument
   string getName() const;
   Author getAuthor() const;  // Returns an instance of the class Author
   double getPrice() const;
   void setPrice(double price);
   int getQtyInStock() const;
   void setQtyInStock(int qtyInStock);
   void print() const;
   string getAuthorName() const;
};

#endif