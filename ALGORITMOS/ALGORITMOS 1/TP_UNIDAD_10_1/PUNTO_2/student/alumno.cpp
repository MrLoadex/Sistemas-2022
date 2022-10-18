#include "alumno.h"
using namespace std;


alumno::alumno(/* args */) {}

alumno::~alumno() {}


void alumno::SetCedula(string ced)
{
    cedula = ced;
}
string alumno::GetCedula()
{
    return cedula;
}
void alumno::SetNombre(string nom)
{
    nombre = nom;
}
string alumno::GetNombre()
{
    return nombre;
}
void alumno::SetNota1(float n1)
{
    nota1 = n1;
}
float alumno::GetNota1()
{
    return nota1;
}
void alumno::SetNota2(float n2)
{
    nota2 = n2;
}
float alumno::GetNota2()
{
    return nota2;
}
void alumno::SetNota3(float n3)
{
    nota3 = n3;
}
float alumno::GetNota3()
{
    return nota3;
}
float alumno::NotaFinal()
{
    float notaFinal = nota1 + nota2 + nota3;
    return notaFinal;
}
string alumno::AproRepro()
{
    string aprobo;
    if (NotaFinal() >= 48)
    {
        aprobo = "aprobado";
        
    }
    else
    {
        aprobo = "desaprobo";
    }
    return aprobo;
}
