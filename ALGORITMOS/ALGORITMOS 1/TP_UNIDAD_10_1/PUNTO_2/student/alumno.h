#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>

class alumno
{
private:
    std::string cedula;
    std::string nombre;
    float nota1;
    float nota2;
    float nota3;
public:
    alumno(/* args */);
    ~alumno();
    void SetCedula(std::string ced);
    std::string GetCedula();
    void SetNombre(std::string nom);
    std::string GetNombre();
    void SetNota1(float n1);
    float GetNota1();
    void SetNota2(float n2);
    float GetNota2();
    void SetNota3(float n3);
    float GetNota3();
    float NotaFinal();
    std::string AproRepro();

};

#endif