#ifndef Bat_h
    #define Bat_h

#include "../Mammal.h"
#include <string>
using namespace std;

class Bat : public Mammal
{
private:

public:
    Bat(),
    ~Bat();
    void SetName(string pName = "Murcielago");
};

#endif