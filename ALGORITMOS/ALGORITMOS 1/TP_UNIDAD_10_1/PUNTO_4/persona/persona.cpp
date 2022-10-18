#include "persona.h"

    persona::persona(){}
    persona::~persona(){}

    void persona::SetName(string nom)
    {
        nombre = nom;
    }
    string persona::GetName()
    {
        return nombre;
    }
    void persona::SetDia(int d)
    {
        dia = d;
    }
    int persona::GetDia()
    {
        return dia;
    }
    void persona::SetMes(int m)
    {
        mes = m;
    }
    int persona::GetMes()
    {  
        return mes;
    }
    void persona::SetAnno(int a)
    {
        anno = a;
    }
    int persona::GetAnno()
    {
        return anno;
    }
    int persona::obtenerEdad()
    {
        int edad = annoact - anno;
        if (mesact < mes) edad --;
        else if (mesact == mes && diaact > dia) edad--;

        return edad;
    }
    void persona::SetDiaact(int da)
    {
        diaact = da;
    }
    int persona::GetDiaact()
    {
        return diaact;
    }
    void persona::SetMesact(int ma)
    {
            mesact = ma;
    }
    int persona::Getmesact()
    {
        return mesact;
    }
    void persona::SetAnnoact(int ao)
    {
        annoact = ao;
    }
    int persona::GetAnnoact()
    {
        return annoact;
    }