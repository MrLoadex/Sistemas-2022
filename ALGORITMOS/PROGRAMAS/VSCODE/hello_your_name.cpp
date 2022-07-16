#include <iostream>
using namespace std;
int main ()
{
    string name;
    cout << "Dia duit cad is ainm duit?"; //Si, es Irlandes
    cin >> name;
    cout  << "Dia dhuit " << name << std::endl;
    //Lineas necesarias para detener el cierre de ventana en Microsoft  Windows
    cin.ignore();
    cin.get();
    return 0;
}