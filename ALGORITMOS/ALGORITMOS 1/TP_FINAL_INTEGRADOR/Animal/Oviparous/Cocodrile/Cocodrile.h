#ifndef Cocodrile_h
    #define Cocodrile_h

#include "../Oviparous.h"
#include <string>
using namespace std;

class Cocodrile : public Oviparous
{
private:

public:
    Cocodrile(),
    ~Cocodrile();
    void SetName(string pName = "Cocodrilo");
};

#endif