#ifndef Oviparous_h
    #define Oviparous_h

#include "../Animal.h"
#include <string>
using namespace std;
//hereda de Animal, clase abstracta
class Oviparous : public Animal
{
private:

public:
    Oviparous();
    ~Oviparous();
    virtual string LayEgg();
};

#endif

