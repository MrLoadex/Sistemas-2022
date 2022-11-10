#include <Goose.h>

Goose::Goose(){Oviparous::SetName("Ganso");}//Si no tiene nombre se le asigna el de su especie
Goose::~Goose(){}
void Goose::SetName(string pName)
{
    Oviparous::SetName("Ganso " + pName);//Especie + Nombre
}
