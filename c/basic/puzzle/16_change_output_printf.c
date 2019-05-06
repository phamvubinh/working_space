#include <stdio.h>

void fun() 
{ 
    // Add something here so that the printf in main prints 10 
    #define printf(x, y) printf(x, 9)
} 
  
int main() 
{ 
    int i = 10; 
    fun(); 
    i = 20; 
    printf("%d", i); 
    return 0; 
}