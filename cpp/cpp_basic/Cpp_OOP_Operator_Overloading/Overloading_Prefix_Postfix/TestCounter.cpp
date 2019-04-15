#include "Counter.h"
#include <iostream>
using namespace std;
 
int main() {
   Counter c1;
   cout << c1 << endl;     // 0
   cout << ++c1 << endl;   // 1
   cout << c1 << endl;     // 1
   cout << c1++ << endl;   // 1
   cout << c1 << endl;     // 2
   cout << ++++c1 << endl; // 4
// cout << c1++++ << endl; // error caused by const return value
}