#include <iostream>
using namespace std;

int main()
{
    int horasTrabajadas,total,horasNormales = 200, horasExtra = 250;

    cout << "Cuantas horas trabajo este mes?"<< endl;
    cin >> horasTrabajadas;
    
    if (horasTrabajadas <40)
    {
        total = horasTrabajadas * horasNormales;
    }
    else
    {
        total = horasTrabajadas * horasExtra;
    }
    cout <<"Este mes cobrara " << total << endl;
    return 0;
}