#include <Bat.h>

Bat::Bat(){ Mammal::SetName("Murcielago"); }//Si no se le asigna un nombre, se le da el de su especie por defecto
Bat::~Bat(){}

void Bat::SetName(string pName)
{
    Mammal::SetName("Murcielago " + pName);//Especia + Nombre
}