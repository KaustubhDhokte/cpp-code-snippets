/*
Whenever we want to control destruction of objects of a class, we make the destructor private.
For dynamically created objects, it may happen that you pass a pointer to the object to a function and the function deletes the object. If the object is referred after the function call, the reference will become dangling. See this for more details.
*/

//http://www.geeksforgeeks.org/private-destructor/
//http://www.geeksforgeeks.org/c-plus-plus-gq/destructors-gq/

#include<stdio.h>

class DestructorExample
{
    public:
    ~DestructorExample()
    {
        printf("Destructor called! \n");
    }
};

class PrivateDestructor
{
    /*
    ~PrivateDestructor()
    {
        printf("Private Destructor \n");
    }
    */
    /*
    destructors.cpp:14:5: error: ‘PrivateDestructor::~PrivateDestructor()’ is private
     ~PrivateDestructor()
     ^
    destructors.cpp:23:23: error: within this context
    PrivateDestructor p;

    */
};

class PrivateDestructor2
{
    ~PrivateDestructor2()
    {
        printf("Private Destructor \n");
    }

    //Compiles well if no object is deleted
};


int main()
{
    DestructorExample d, d2;
    PrivateDestructor p; //Fails with compilation error

    PrivateDestructor2 *pptr; // Works well

    PrivateDestructor2 *pptr2 = new PrivateDestructor2; //Works well

    PrivateDestructor2 *pptr3 = new PrivateDestructor2(); //Works well

    /*
    PrivateDestructor2 *pptr4 = new PrivateDestructor2();
    delete pptr4;

    destructors.cpp: In function ‘int main()’:
    destructors.cpp:39:5: error: ‘PrivateDestructor2::~PrivateDestructor2()’ is private
     ~PrivateDestructor2()
     ^
    destructors.cpp:60:12: error: within this context
    delete pptr4;
    */
    
    printf("\n Main \n");
}