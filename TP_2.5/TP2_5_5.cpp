#include <iostream>
using namespace std;

template <class tipo>
void despliegue(tipo numero);
int main()
{
    double n = 553.30045;
    float n1 = 1.3;
    int n2 = 5;

    despliegue(n);
    despliegue(n1);
    despliegue(n2);

    return 0;
}

template <class tipo>
void despliegue(tipo numero)
{
    cout << numero << endl;
}
