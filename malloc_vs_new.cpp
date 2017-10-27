/*

http://www.geeksforgeeks.org/malloc-vs-new/

Following are the differences between malloc() and operator new.:

Calling Constructors: new calls constructors, while malloc() does not. In fact primitive data types (char, int, float.. etc) can also be initialized with new. For example, below program prints 10.
#include<iostream>
 
using namespace std;
 
int main()
{
   int *n = new int(10); // initialization with new()
   cout << *n;
   getchar();
   return 0;
}

operator vs function: new is an operator, while malloc() is a function.
return type: new returns exact data type, while malloc() returns void *.
Failure Condition: On failure, malloc() returns NULL where as new Throws.
Memory: In case of new, memory is allocated from free store where as in malloc() memory allocation is done from heap.
Overriding: We are allowed to override new operator where as we can not override the malloc() function legally.
Size: Required size of memory is calculated by compiler for new, where as we have to manually calculate size for malloc().

*/