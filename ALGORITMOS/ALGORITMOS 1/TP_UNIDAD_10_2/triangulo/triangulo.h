#ifndef triangulo_h
    #define triangulo_h

#include "../figura/figura.h"
#include <string>
using namespace std;

class triangulo: public figura
{
public:
    triangulo();
    string dibujar();
    string borrar();
    ~triangulo();
};

#endif