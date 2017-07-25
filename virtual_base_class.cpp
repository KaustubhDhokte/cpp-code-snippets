#include<stdio.h>

class GrandParent
{
    public:
    void print_method()
    {
        printf("GrandParent::print_method()\n");
    }
};

class Parent1:public virtual GrandParent
{
    // Method can be overriden if inherited by virtual
    // public:
    // void print_method()
    // {
    //     printf("Parent1::print_method()\n");
    // }
};

class Parent2:public virtual GrandParent
{

};

class Child:public Parent1, public Parent2
{

};

int main()
{
    Child c;
    c.print_method();
    //Works well 
}


//////////////////////////////Above code works well//////////////////////////

// #include<stdio.h>

// class GrandParent
// {
//     public:
//     void print_method()
//     {
//         printf("GrandParent::print_method()\n");
//     }
// };

// class Parent1:public virtual GrandParent
// {

// };

// class Parent2:public GrandParent
// {

// };

// class Child:public Parent1, public Parent2
// {

// };

// int main()
// {
//     Child c;
//     c.print_method();

//     /*

//     Fails with error: (Note that only one class in inherited as virtual)

//     virtual_base_class.cpp: In function ‘int main()’:
//     virtual_base_class.cpp:70:7: error: request for member ‘print_method’ is ambiguous
//      c.print_method();
//        ^
//      virtual_base_class.cpp:46:10: note: candidates are: void GrandParent::print_method()
//      void print_method()
//           ^
//      virtual_base_class.cpp:46:10: note: void GrandParent::print_method()
//     */
// }



//////////////////////////////////////////////////////////////////////////////////////////

// #include<stdio.h>

// class GrandParent
// {
//     public:
//     void print_method()
//     {
//         printf("GrandParent::print_method()\n");
//     }
// };

// class Parent1:public GrandParent
// {

// };

// class Parent2:public GrandParent
// {

// };

// class Child:public virtual Parent1, public virtual Parent2
// {

// };

// int main()
// {
//     Child c;
//     c.print_method();

//     /*

//     Fails with error: (Note that child classes are inherited)

//     virtual_base_class.cpp: In function ‘int main()’:
//     virtual_base_class.cpp:70:7: error: request for member ‘print_method’ is ambiguous
//      c.print_method();
//        ^
//      virtual_base_class.cpp:46:10: note: candidates are: void GrandParent::print_method()
//      void print_method()
//           ^
//      virtual_base_class.cpp:46:10: note: void GrandParent::print_method()
//     */
// }