#include <Cocodrile.h>

Cocodrile::Cocodrile(){ Oviparous::SetName("Cocodrilo"); }//Si no tiene nombre se le asigna el de su especie
Cocodrile::~Cocodrile(){}

void Cocodrile::SetName(string pName)
{
    Oviparous::SetName("Cocodrilo " + pName);//Especie + Nombre
}