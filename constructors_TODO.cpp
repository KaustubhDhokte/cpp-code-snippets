//In fact except inline, no other keyword is allowed in the declaration of constructor.

#include<stdio.h>

class DefaultConstructorExample
{
};

class ConstructorExample
{
    public:
    ConstructorExample()
    {
        printf("Constructor called\n");
        //Try Catch works well in constructors
        try
        {
            printf("Call in Try\n");
        }
        catch(...)
        {

        }
    }
};

class PrivateConstructorExample
{
    
    // PrivateConstructorExample()
    // {
    //     printf("Constructor called\n");
    //     //Try Catch works well in constructors
    //     try
    //     {
    //         printf("Call in Try\n");
    //     }
    //     catch(...)
    //     {

    //     }
    // }

    /*
    constructors.cpp:28:5: error: ‘PrivateConstructorExample::PrivateConstructorExample()’ is private
     PrivateConstructorExample()

    */
};

class ConstructorWithReturnType
{
    public:
    //Error:
    /*
    //constructors.cpp:28:36: error: return type specification for constructor invalid
    //void ConstructorWithReturnType()
    
    void ConstructorWithReturnType()
    {
        printf("Constructor with return type\n");
    }
    */
};

class CopyConstructorExample
{
    int x, y;
    public:
    CopyConstructorExample(int x1, int y1)
    {
        printf("Copy Constructor Example \n");
        x = x1;
        y = y1;
    }

    //CopyConstructorExample(const CopyConstructorExample cce)
    /*
    constructors.cpp:75:60: error: invalid constructor; you probably meant ‘CopyConstructorExample (const CopyConstructorExampl
    e&)’
     CopyConstructorExample(const CopyConstructorExample cce)
    */
    CopyConstructorExample(const CopyConstructorExample &cce)
    {
        x = cce.x;
        y = cce.y;
    }

    int getX() {return x;}
    int getY() {return y;}
    void setX(int x1) {x=x1;}
    void setY(int y1) {y=y1;}
};

class PrivateCopyConstructorExample
{
    int x, y;
    PrivateCopyConstructorExample(const CopyConstructorExample &cce)
    {
        //x = cce.x;
        /*
        constructors.cpp: In constructor ‘PrivateCopyConstructorExample::PrivateCopyConstructorExample(const CopyConstructorExample
        &)’:
        constructors.cpp:66:9: error: ‘int CopyConstructorExample::x’ is private
        int x, y;
         ^
        constructors.cpp:98:17: error: within this context
         x = cce.x;
        */
        //y = cce.y;


        //x = cce.getX();


        /*
        constructors.cpp: In constructor ‘PrivateCopyConstructorExample::PrivateCopyConstructorExample(const CopyConstructorExample
        &)’:
        constructors.cpp:109:22: error: passing ‘const CopyConstructorExample’ as ‘this’ argument discards qualifiers [-fpermissive
        ]
         x = cce.getX();
                      ^
        constructors.cpp:87:9: note:   in call to ‘int CopyConstructorExample::getX()’
        int getX() {return x;}
        */

        //y = cce.getY();
    }

    /*
    constructors.cpp:66:12: error: ‘int CopyConstructorExample::y’ is private
     int x, y;
            ^
    constructors.cpp:99:17: error: within this context
         y = cce.y;
    */

    public:
    PrivateCopyConstructorExample(int x1, int y1)
    {
        printf("Copy Constructor Example \n");
        x = x1;
        y = y1;
    }
    
    int getX() {return x;}
    int getY() {return y;}
    void setX(int x1) {x=x1;}
    void setY(int y1) {y=y1;}
};

int main()
{
    DefaultConstructorExample def;

    ConstructorExample c;         //Calls Constructor

    PrivateConstructorExample pric;
    //ConstructorWithReturnType c2;
    
    CopyConstructorExample cpy1(5, 10);
    //CopyConstructorExample
    CopyConstructorExample cpy2 = cpy1;

    //CopyConstructorExample cpy3;
    /*
    constructors.cpp:137:28: error: no matching function for call to ‘CopyConstructorExample::CopyConstructorExample()’
    CopyConstructorExample cpy3;
    constructors.cpp:68:5: note:   candidate expects 2 arguments, 0 provided
    */

    printf("\n\nCpy2\n x: %d y: %d\n", cpy2.getX(), cpy2.getY());

    cpy2.setX(6);
    cpy2.setY(12);

    printf("\n\nCpy1\n x: %d y: %d\n", cpy1.getX(), cpy1.getY());
    // Prints 5,10

    printf("\n\nCpy2\n x: %d y: %d\n", cpy2.getX(), cpy2.getY());
    // Prints 6,12 

    /*
    User defined Copy constructor does deep copy
    */
}
