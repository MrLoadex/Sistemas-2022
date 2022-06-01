#include <iostream>
#include <string>
using namespace std;
typedef enum {banana, naranja, uva, frutilla, kiwi, manzana} frutas;
string SelectFruta(int f); // selecciona las frutas y devuelve un string de la fruta seleccionada.


int main(){
    int select, codigo_proveedor, cantidad, centinela = 1;
    string razon_social, fecha_solicitud, fecha_entrega, total;
    cout << "Ingrese razon social:";
    cin >> razon_social;

    cout << "Ingrese su codigo de proveedor: "; // ingreso de datos
    cin >> codigo_proveedor;

    cout << "Fecha de solicitud:";
    cin >> fecha_solicitud;

    cout << "Fecha de entrega: ";
    cin >> fecha_entrega;
    string codigo_proveedor_str(to_string(codigo_proveedor));
    total = "Razon social: " + razon_social + "\nCodigo de proveedor " + codigo_proveedor_str +
    "\nFecha de solicitud: "+ fecha_solicitud + "\nFecha de entrega: " + fecha_entrega; 


    while (centinela == 1){
        cout << "Que desea solicitar?" << endl <<
        "1. Banana" << endl <<
        "2. Naranja" << endl <<
        "3. Uva" << endl <<
        "4. Frutilla" << endl <<
        "5. Kiwi" << endl <<
        "6. Manzana" << endl;
        cin >> select;
        select --;
        cout << "Cantidad? En kg.\n";
        cin >> cantidad;
        string cantidad_str(to_string(cantidad));
        total += "\n" + cantidad_str + "kg de " + SelectFruta(select) + "."; // carga el str que se mostrara al final.
        cout << "Desea solicitar algo mas?" << endl <<
        "1. Si\n"<<
        "2. No\n";
        cin >> centinela;
    }
    cout << total;
    return 0;
}

string SelectFruta(int f){
    string resultado;
    frutas fruta = frutas(f);
    if (fruta == banana){
        resultado = "banana";
    }
    else if (fruta == naranja){
        resultado = "naranja";
    }
    else if (fruta == uva){
        resultado = "uva";
    }
    else if (fruta == frutilla){
        resultado = "frutilla";
    }
    else if (fruta == kiwi){
        resultado = "kiwi";
    }
    else if (fruta == manzana){
        resultado = "manzana";
    }
    return resultado;
}