#ifndef Mammal_h
    #define Mammal_h

#include <Animal.h>
#include <string>
using namespace std;

class Mammal : public Animal
{
private:

public:
    Mammal();
    ~Mammal();
    virtual string Nurse();
};

#endif

