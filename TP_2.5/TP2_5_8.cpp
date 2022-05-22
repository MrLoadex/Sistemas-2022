#include <iostream>
using namespace std;

int tiempo(int totalSeg);

int main()
{
    int segundos;
    cout << "Ingrese un valor en segundos: ";
    cin >> segundos;
    tiempo(segundos);
    return 0;
}

int tiempo (int totalSeg)
{
    int horas = 0, minutos = 0, segundos = 0;
    int segundosRestantes = totalSeg;
    
    while (segundosRestantes > 0)
    if (segundosRestantes >= 3600)
    {
        segundosRestantes -= 3600;
        horas += 1;
    }
    else if (segundosRestantes >= 60)
    {
        segundosRestantes -= 60;
        minutos +=1;
    }
    else
    {
        segundos =segundosRestantes;
        segundosRestantes -=segundosRestantes;
    }
cout << totalSeg << " segundos son " << horas << " horas, " << minutos << " minutos, " << segundos << "segundos" << endl;
return 0;
    

}