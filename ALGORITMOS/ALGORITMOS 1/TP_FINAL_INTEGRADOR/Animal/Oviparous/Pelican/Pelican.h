#ifndef Pelican_h
    #define Pelican_h

#include "../Oviparous.h"
#include <string>
using namespace std;

class Pelican : public Oviparous
{
private:

public:
    Pelican();
    ~Pelican();
    void SetName(string pName = "Pelican");
};



#endif