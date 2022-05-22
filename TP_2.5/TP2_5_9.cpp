#include <iostream>
using namespace std;
int Duplicar(int a, int b);

int main()
{
    int a,b;
    cout << "Ingrese un valor: ";
    cin >> a;
    cout << "Ingrese un valor: ";
    cin >> b;
    Duplicar(a,b);
    return 0;
}

int Duplicar(int a, int b)
{
    cout << "a: "<< a << " b: " << b << endl;
    int a1,b1;
    a1 = a * 2;
    b1 = b * 2;
    cout << "a: "<< a1 << " b: " << b1 << endl;
    return 0;
}