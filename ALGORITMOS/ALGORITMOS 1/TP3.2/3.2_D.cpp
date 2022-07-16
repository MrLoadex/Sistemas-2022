#include <iostream>
using namespace std;

int DiferenciaXeY(int x, int y);
int Mostrar(int x, int y,int diferencia_x_y);

int main ()
{
    int x,y, diferenciax_y;
    cout << "Ingrese x :";
    cin >> x;
    cout << "Ingrese y: ";
    cin >> y;
    diferenciax_y = DiferenciaXeY(x, y);
    Mostrar(x,y, diferenciax_y);
    return 0;
}

int DiferenciaXeY(int x, int y){
    int diferencia;
    diferencia = x - y;
    if (diferencia <0){diferencia *= -1;}
    return diferencia;
}



int Mostrar(int x, int y, int diferencia_x_y){

    cout << "La diferencia entre " << x << " y " << y << " es: " << diferencia_x_y << endl;   

    if (diferencia_x_y > 10){
        cout << "Entre " << x << " y " << y << " estan: " ;
        while (diferencia_x_y > 1){
            diferencia_x_y --;
            if (x<y){
                cout << y - diferencia_x_y << ", ";
            }
            else{
                cout << x - diferencia_x_y << ", ";
            }
        }
    }
    return 0;
}