#include <Pelican.h>

Pelican::Pelican(){ Oviparous::SetName("Pelicano"); }//Si no tiene nombre se le asigna el de su especie
Pelican::~Pelican(){}
void Pelican::SetName(string pName)
{
    Oviparous::SetName("Pelicano " + pName);//Especie + Nombre
}