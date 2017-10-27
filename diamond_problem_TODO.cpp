//http://www.geeksforgeeks.org/multiple-inheritance-in-c/
//TODO: Parameterized constructors

#include<stdio.h>
// class GrandParent
// {
//     int x;
//     public:
//     GrandParent()
//     {
//         printf("\n GrandParent default constructor\n");
//     }

//     ~GrandParent()
//     {
//         printf("\n GrandParent distructor\n");
//     }

//     int getX()
//     {
//         return x;
//     }

//     void setX(int a)
//     {
//         x = a;
//     }
// };

// class Parent1:public GrandParent
// {
//     public:
//     Parent1()
//     {
//         printf("\n Parent1 default constructor\n");
//         setX(10);
//     }
//     ~Parent1()
//     {
//         printf("\n Parent1 distructor\n");
//     }
// };

// class Parent2:public GrandParent
// {
//     public:
//     Parent2()
//     {
//         printf("\n Parent2 default constructor\n");
//         setX(20);
//     }
//     ~Parent2()
//     {
//         printf("\n Parent2 distructor\n");
//     }
// };

// class Child:public Parent1, public Parent2
// {
//     public:
//     Child()
//     {
//         printf("\n Child default constructor");
//     }
//     ~Child()
//     {
//         printf("\n Child distructor");
//     }
// };

// int main()
// {
//     Child c;
//     printf("\n X =  %d\n",c.getX());
//     /*
//     diamond_problem.cpp: In function ‘int main()’:
//     diamond_problem.cpp:71:29: error: request for member ‘getX’ is ambiguous
//      printf("\n X =  %d\n",c.getX());
//                              ^
//     diamond_problem.cpp:16:9: note: candidates are: int GrandParent::getX()
//     int getX()
//          ^
//     diamond_problem.cpp:16:9: note:                 int GrandParent::getX()
//     */
// }

///////////////////////////////////////////Solution to diamond problem by Virtual Classes//////////////////////////

class GrandParent
{
    int x;
    public:
    GrandParent()
    {
        printf("\n GrandParent default constructor\n");
    }

    ~GrandParent()
    {
        printf("\n GrandParent distructor\n");
    }

    int getX()
    {
        return x;
    }

    void setX(int a)
    {
        x = a;
    }
};

class Parent1:public virtual GrandParent
{
    public:
    Parent1()
    {
        printf("\n Parent1 default constructor\n");
        setX(10);
    }
    ~Parent1()
    {
        printf("\n Parent1 distructor\n");
    }
};

class Parent2:public virtual GrandParent
{
    public:
    Parent2()
    {
        printf("\n Parent2 default constructor\n");
        setX(20);
    }
    ~Parent2()
    {
        printf("\n Parent2 distructor\n");
    }
};

class Child:public Parent2, public Parent1
{
    public:
    Child()
    {
        printf("\n Child default constructor");
    }
    ~Child()
    {
        printf("\n Child distructor");
    }
};

int main()
{
    Child c;
    printf("\n X =  %d\n",c.getX());
    // X =  20 if GrandParent inheritance order is Parent1, Parent2
    // X =  10 if GrandParent inheritance order is Parent2, Parent1
    /*
    diamond_problem.cpp: In function ‘int main()’:
    diamond_problem.cpp:71:29: error: request for member ‘getX’ is ambiguous
     printf("\n X =  %d\n",c.getX());
                             ^
    diamond_problem.cpp:16:9: note: candidates are: int GrandParent::getX()
    int getX()
         ^
    diamond_problem.cpp:16:9: note:                 int GrandParent::getX()
    */
}