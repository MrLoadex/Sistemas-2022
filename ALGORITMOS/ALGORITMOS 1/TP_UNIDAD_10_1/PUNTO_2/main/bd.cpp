#include <iostream>
#include "../student/alumno.h"
using namespace std;

void OptionSelector();

int main()
{
    alumno alumno1;
    alumno1.SetNombre("alumno1");
    alumno1.SetCedula("matematica");
    alumno1.SetNota1(4);
    alumno1.SetNota2(3.5);
    alumno1.SetNota3(10);
    cout << alumno1.GetNombre() << " en " << alumno1.GetCedula() << " tiene una nota final de " << alumno1.NotaFinal() << endl;
    cout << alumno1.GetNombre() << " " << alumno1.AproRepro()<< endl; 
    alumno1.~alumno();

    system("pause");
    system("cls");
    return 0;
}
