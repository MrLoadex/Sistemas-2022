#ifndef Whale_h
    #define Whale_h

#include "../Mammal.h"
#include <string>
using namespace std;

class Whale : public Mammal
{
private:

public:
    Whale(),
    ~Whale();
    void SetName(string pName = "Ballena");
};
#endif