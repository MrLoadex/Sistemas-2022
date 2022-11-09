#include "Whale.h"

Whale::Whale(){Mammal::SetName("Ballena");}//Si no se le asigna un nombre, se le da el de su especie por defecto
Whale::~Whale(){}

void Whale::SetName(string pName)
{
    Mammal::SetName("Ballena " + pName);//Especia + Nombre
}