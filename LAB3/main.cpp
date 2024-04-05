#include "stdafx.h"
using namespace System;

// Declaration of the Animal class
ref class Animal
{
public:
    int legs; // Public variable for the number of legs
private:
    String^ name; // Private variable for the name of the animal

public:
    // Public member function to set the name of the animal
    void SetName(String^ n) { name = n; }

    // Public member function to get the name of the animal
    String^ GetName() { return name; }
};

int main(array<System::String ^> ^args)
{
    // Creating two Animal objects
    Animal^ cat = gcnew Animal();
    Animal^ dog = gcnew Animal();

    // Setting the names of the cat and dog objects
    cat->SetName("Cat");
    dog->SetName("Dog");

    // Setting the number of legs for both animals
    cat->legs = 4;
    dog->legs = 4;

    // Displaying the names and the number of legs for both animals
    Console::WriteLine("The {0} has {1} legs.", cat->GetName(), cat->legs);
    Console::WriteLine("The {0} has {1} legs.", dog->GetName(), dog->legs);

    return 0;
}
