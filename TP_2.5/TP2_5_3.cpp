#include <iostream>
#include <cmath>
using namespace std;
int  funpot(int num, int pot);

int main()
{
    int num, pot,elevar;
    cout << "Ingrese un numero:\n";
    cin >> num;
    cout << "A que numero decea elevarlo?\n";
    cin >> pot;
    elevar = funpot(num,pot);
    cout << num << " elevado a la " << pot << " da como resultado " << elevar;
    return 0;
}

int  funpot(int num, int pot)
{
    int resultado = pow(num,pot);
    return resultado;
}