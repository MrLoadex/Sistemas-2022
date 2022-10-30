#ifndef circulo_h
    #define circulo_h

#include "../figura/figura.h"
#include <string>
using namespace std;

class circulo: public figura
{
public:
    circulo();
    string dibujar();
    string borrar();
    ~circulo();
};

#endif