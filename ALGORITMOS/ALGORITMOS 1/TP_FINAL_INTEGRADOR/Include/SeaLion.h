#ifndef SeaLion_h
    #define SeaLion_h

#include <Mammal.h>
#include <string>
using namespace std;

class SeaLion : public Mammal
{
private:

public:
    SeaLion(),
    ~SeaLion();
    void SetName(string pName = "Leon marino");
};

#endif