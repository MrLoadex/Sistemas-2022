#include "articulo.h"
articulo::articulo(/* args */)
{

}

articulo::~articulo(){}


void articulo::SetCostoBase(float CB)
{
    costoBase = CB;
}

float articulo::GetCostoBase()
{
    return costoBase;
}

float articulo::PVPMayor()
{
    float PMayor;
    PMayor = costoBase * 0.3 + costoBase;
    return PMayor;
}

float articulo::PVPDetal()
{
    float PDetal;
    PDetal = costoBase *0.15 + costoBase;
    return PDetal;
}
