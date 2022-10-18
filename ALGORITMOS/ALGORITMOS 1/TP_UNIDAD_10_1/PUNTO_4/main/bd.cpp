#include <iostream>
#include <time.h>
#include "../persona/persona.h"
using namespace std;

int diaActual(string d_m_a);

int main()
{   
    int diaact =diaActual("dia");
    int mesact = diaActual("mes");
    int annoact = diaActual("anno");
    persona persona1;
    persona1.SetName("Juan Carlos");
    persona1.SetDia(31);
    persona1.SetMes(3);
    persona1.SetAnno(1996);
    persona1.obtenerEdad();
    persona1.SetDiaact(diaact);
    persona1.SetMesact(mesact);
    persona1.SetAnnoact(annoact);
    cout <<"Usted es el sennor " << persona1.GetName() <<  
    " y nacio el "<< persona1.GetDia() << "-" << persona1.GetMes() << "-" << persona1.GetAnno() <<  
    " hoy es " << persona1.GetDiaact() << "-" << persona1.Getmesact() << "-" << persona1.GetAnnoact() << 
    " por lo tanto tiene " << persona1.obtenerEdad() << endl;
    system("pause");
    system("cls");
    return 0;
}



int diaActual(string d_m_a)
{
   time_t instante_actual = time(NULL);  // instante actual


   struct tm* pt1 = localtime(&instante_actual);

    if (d_m_a == "dia") return pt1->tm_mday;
    else if (d_m_a =="mes") return pt1->tm_mon+1;
    else if (d_m_a == "anno") return pt1->tm_year+1900;

   return 0;
}