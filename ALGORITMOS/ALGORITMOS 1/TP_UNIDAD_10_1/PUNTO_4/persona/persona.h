#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class persona
{
private:
    string nombre;
    int dia;
    int mes;
    int anno;
    int diaact;
    int mesact;
    int annoact;
public:
    persona();
    ~persona();
    void SetName(string nom);
    string GetName();
    void SetDia(int d);
    int GetDia();
    void SetMes(int m);
    int GetMes();
    void SetAnno(int a);
    int GetAnno();
    int obtenerEdad();
    void SetDiaact(int da);
    int GetDiaact();
    void SetMesact(int ma);
    int Getmesact();
    void SetAnnoact(int ao);
    int GetAnnoact();

};
#endif