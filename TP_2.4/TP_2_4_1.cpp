#include <iostream>
using namespace std;

int main()
{
    float productosCantidad, producto =80,total;

    cout << "Cuantos productos desea comprar?"<< endl;
    cin >> productosCantidad;
    total = producto*productosCantidad;
    
    if (productosCantidad >30)
    {
        total = total-(40 * total / 100);
    }
    else if (productosCantidad >20)
    {
        total = total-(25 * total / 100);
    }
    else if (productosCantidad >10)
    {
        total = total-(12 * total / 100);
    }
    cout <<"Total: $" << total;
    return 0;
}