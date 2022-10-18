#ifndef CUADRILATERO_H
#define CUADRILATERO_H

class cuadrilatero
{
private:
    float altura;
    float base;
public:
    cuadrilatero();
    ~cuadrilatero();
    void SetAltura(float alt);
    float GetAltura();
    void SetBase(float b);
    float GetBase();
    float area();
    float perimetro();
};

#endif