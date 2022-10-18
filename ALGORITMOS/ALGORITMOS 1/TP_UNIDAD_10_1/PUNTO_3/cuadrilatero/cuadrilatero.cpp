#include "cuadrilatero.h"

    cuadrilatero::cuadrilatero(){}
    cuadrilatero::~cuadrilatero(){}

    void cuadrilatero::SetAltura(float alt)
    {
        altura = alt;
    }

    float cuadrilatero::GetAltura()
    {
        return altura;
    }

    void cuadrilatero::SetBase(float b)
    {
        base = b;
    }

    float cuadrilatero::GetBase()
    {
        return base;
    }

    float cuadrilatero::area()
    {
        float area = base * altura;
        return area;
    }

    float cuadrilatero::perimetro()
    {
        float perimetro = (2*base + 2*altura);
        return perimetro;
    }