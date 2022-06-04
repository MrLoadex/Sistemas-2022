#include <iostream>
using namespace std;

string Calidad(int calidad);
string Envio(int envio);
string Mostrar(int calidad, int envio);
//Opciones de 4 productos a) Simple b)medio c)calidad d)Premiun
//luego nos deberá mostrar en menú de tipo de envio: 1) normal 2) express 3) Fast Delivery.

int main ()
{
    int calidad, envio;
    cout <<"Seleccione dentro de las siguientes opciones de producto:\n" <<
    "1- Simple\n" <<
    "2- Medio\n"<<
    "3- Calidad\n"<<
    "4- Premium\n";
    cin >> calidad;
    cout << "Seleccione el tipo de envio:\n" <<
    "1- Normal\n"<<
    "2- Express\n"<<
    "3 Fast Delivery\n";
    cin >> envio;
    Mostrar(calidad,envio);

    return 0;
}

string Mostrar(int calidad, int envio){
    cout << "\nUsted selecciono:\n" <<
    "Tipo de producto: "<< Calidad(calidad) << endl <<
    "Tipo de envio: "<< Envio(envio) << endl;
}

string Calidad(int calidad){
    string retorno;
    switch (calidad)
    {
    case 1:
        retorno = "Simple";
        break;
    case 2:
        retorno = "Medio";
        break;
    case 3:
        retorno = "Calidad";
        break;
    case 4:
        retorno = "Premium";
        break;
    default:
        cout << "Elegi bien cien pies.";
        break;
    }
    return retorno;
}
string Envio(int envio){
    string retorno;
    if (envio == 1){
        retorno = "Normal";
    }
    else if (envio == 2){
        retorno = "Express";
    }
    else if (envio == 3){
        retorno = "Fast Delivery";
    }
    else{
        cout << "Era dificil errarle, pero lo lograste.";
    }
return retorno;
}