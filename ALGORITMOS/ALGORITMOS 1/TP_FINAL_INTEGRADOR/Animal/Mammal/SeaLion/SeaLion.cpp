#include "SeaLion.h"

SeaLion::SeaLion(){ Mammal::SetName("Leon Marino"); }//Si no se le asigna un nombre, se le da el de su especie por defecto
SeaLion::~SeaLion(){}

void SeaLion::SetName(string pName)
{
    Mammal::SetName("Leon Marino " + pName);//Especia + Nombre
}