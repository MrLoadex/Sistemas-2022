#ifndef rectangulo_h
    #define rectangulo_h

#include "../figura/figura.h"
# include <string>
using namespace std;

class rectangulo : public figura
{
private:
public:
    rectangulo();
    string dibujar();
    string borrar();
    ~rectangulo();
};

#endif