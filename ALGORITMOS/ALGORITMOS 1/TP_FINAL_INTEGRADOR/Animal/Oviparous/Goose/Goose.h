#ifndef Goose_h
    #define Goose_h
#include <string>
#include "../Oviparous.h"
using namespace std;

class Goose : public Oviparous
{
private:

public:
    Goose();
    ~Goose();
    void SetName(string pName = "Goose");
};
#endif