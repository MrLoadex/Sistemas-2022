#include <iostream>
using namespace std;

int main()
{
    double x,y,x1,y1,b,m,yRespuesta;
    int aux = 3;
    cout << "Ingrese el valor de 'x': ";
    cin >> x;
    cout << "Ingrese el valor de 'y': ";
    cin >> y;
    cout << "Ingrese valor de 'x1': ";
    cin >> x1;
    cout << "Ingrese el valor de 'Y1': ";
    cin >> y1;

    m = (y - y1) / (x - x1) ;
    b = m*(x-x1)+y1;
    cout <<"m: : " << m << endl;
    cout <<"b: " << b;
    //Le asigna algunos valores a x e imprime su respectiva y.
    while (aux >0){
        yRespuesta = (m*(aux-x1))+y1;
        cout << "X: " << aux << " Y: " << yRespuesta << endl;
        aux-=1;
    }

    return 0;
}