#include <iostream>
using namespace std;

int main()
{
    float notas, aux =1, total;
    while (aux <=3)
    {
        cout <<"Ingrese la nota " << aux << endl;
        cin >> notas;
        total += notas;
        aux++;
    }
    total /=3;
    if (total < 4)
    {
        cout << "Desaprobo";
    }
    else
    {
        cout << "Aprobo";
    }
    return 0;
}