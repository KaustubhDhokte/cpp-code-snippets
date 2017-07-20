#include<stdio.h>

class Base
{
    void private_method_base()
    {
        printf("Private Method of base\n");
    }

    public:
    void public_method_base()
    {
        printf("Public Method of base\n");
    }

    protected:
    void protected_method_base()
    {
        printf("Protected Method of base\n");
    }
};

class Derived_publically : public Base
{
    void private_method_derived_publically()
    {
        printf("Private Method of derived publically\n");
    }

    public:
    void public_method_derived_publically()
    {
        printf("Public Method of derived publically\n");
    }

    protected:
    void protected_method_derived_publically()
    {
        printf("Protected Method derived publically\n");
    }
};

class Derived_privately : private Base
{
    void private_method_derived_privately()
    {
        printf("Private Method of derived privately\n");
    }

    public:
    void public_method_derived_privately()
    {
        printf("Public Method of derived privately\n");
    }

    protected:
    void protected_method_derived_privately()
    {
        printf("Protected Method derived privately\n");
    }
};

class Derived_protectedly : protected Base
{
    void private_method_derived_protectedly()
    {
        printf("Private Method of derived protectedly\n");
    }

    public:
    void public_method_derived_protectedly()
    {
        printf("Public Method of derived protectedly\n");
    }

    protected:
    void protected_method_derived_protectedly()
    {
        printf("Protected Method derived protectedly\n");
    }
};

int main()
{
    Derived_publically dpub;
    //dpub.private_method_derived_publically();
    // Compilation Error: error: ‘void Derived_publically::private_method_derived_publically()’ is private

    //dpub.protected_method_derived_publically();
    // Complation Error: error: ‘void Derived_publically::protected_method_derived_publically()’ is protected

    //dpub.private_method_base();
    //Compilation Error: error: ‘void Base::private_method_base()’ is private

    //dpub.protected_method_base();
    //Compilation Error: error: ‘void Base::protected_method_base()’ is protected
    
    dpub.public_method_base();
    //Works well

    Derived_privately dprv;

    //dprv.private_method_base();
    //Compilation Error: error: ‘void Base::private_method_base()’ is private

    //dprv.protected_method_base();
    //Compilation Error: error: ‘void Base::protected_method_base()’ is protected

    //dprv.public_method_base();
    // Compilation Error: error: ‘void Base::public_method_base()’ is inaccessible
    // error: ‘Base’ is not an accessible base of ‘Derived_privately’

    Derived_protectedly dpro;
    
    //dpro.private_method_base();
    //Compilation Error: error: ‘void Base::private_method_base()’ is private

    //dpro.protected_method_base();
    //Compilation Error: error: ‘void Base::protected_method_base()’ is protected

    //dpro.public_method_base();
    // Compilation Error: error: ‘void Base::public_method_base()’ is inaccessible
    // error: ‘Base’ is not an accessible base of ‘Derived_protectedly’
}


