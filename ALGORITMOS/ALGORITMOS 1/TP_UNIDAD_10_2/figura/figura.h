#ifndef figura_h
    #define figura_h
#include <string>
using namespace std;

class figura
{
public:
    figura();
    virtual string dibujar();
    virtual string borrar();
    string rotar();
    string mover();
    ~figura();
};

#endif