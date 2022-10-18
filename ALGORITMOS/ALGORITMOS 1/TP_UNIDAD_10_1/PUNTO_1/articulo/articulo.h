#ifndef ARTICULO_H
    #define ARTICULO_H
using namespace std;

class articulo
{
private:
    float costoBase;
public:
    articulo();
    void SetCostoBase(float CB);
    float GetCostoBase();
    float PVPMayor();
    float PVPDetal();
    ~articulo();
};

#endif