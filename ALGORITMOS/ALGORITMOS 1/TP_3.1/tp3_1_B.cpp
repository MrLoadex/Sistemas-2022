#include <iostream>
using namespace std;
typedef enum {primera, bussiness, economica} clases;
typedef enum {BHI, AEP, EPA, EZE, BRC, CTC, CRD} aeropuertos;
string SelectClase(int c );
string SelectAirport(int a);

int main(){
    int dni, selector;
    string nombre, destino, origen, dni_string, clase;
    cout << "Destino al que desea viajar:" << endl <<
    "1. Bahía Blanca" << endl <<
    "2. Buenos Aires Aeroparque" << endl <<
    "3. Buenos Aires El Palomar" << endl <<
    "4. Buenos Aires Ezeiza" << endl <<
    "5. San Carlos de Bariloche" << endl <<
    "6. San Fernando del Valle de Catamarca" << endl <<
    "7. Comodoro Rivadavia" << endl;
    cin >> selector;
    selector --;
    destino = SelectAirport(selector);

    cout << "Desde donde va a viajar:" << endl <<
    "1. Bahía Blanca" << endl <<
    "2. Buenos Aires Aeroparque" << endl <<
    "3. Buenos Aires El Palomar" << endl <<
    "4. Buenos Aires Ezeiza" << endl <<
    "5. San Carlos de Bariloche" << endl <<
    "6. San Fernando del Valle de Catamarca" << endl <<
    "7. Comodoro Rivadavia" << endl;
    cin >> selector;
    selector --;
    origen = SelectAirport(selector);

    cout << "Clase en la que desea viajar: " << endl <<
    "1. primera clase" << endl <<
    "2. bussiness" << endl <<
    "3. economica" << endl;
    cin >> selector;
    selector --;
    clase = SelectClase(selector);

    cout <<"Apellido y nombre de quien viajadra: ";
    cin >> nombre;

    cout << "DNI de quien viajara: ";
    cin >> dni;
    dni_string = dni;
    cout << "El señor " << nombre << " con D.N.I " << dni << " viajara desde " << origen << " hasta " << destino;
   
}

string SelectClase(int c ){
    string resultado;
    clases clase = clases(c);
    if (clase == primera){
        resultado = "primera";
    }
    else if (clase == bussiness){
        resultado = "bussiness";
    }
    else if (clase == economica){
        resultado = "economica";
    }
    return resultado;
}
string SelectAirport(int a){
    string resultado;
    aeropuertos aeropuerto = aeropuertos(a);
    if (aeropuerto == BHI){
        resultado = "Bahía Blanca";
    }
    else if (aeropuerto == AEP){
        resultado = "Buenos Aires Aeroparque";
    }
    else if (aeropuerto == EPA){
        resultado = "Buenos Aires El Palomar";
    }
    else if (aeropuerto == EZE){
        resultado = "Buenos Aires Ezeiza";
    }
    else if (aeropuerto == BRC){
        resultado = "San Carlos de Bariloche";
    }
    else if (aeropuerto == CTC){
        resultado = "San Fernando del Valle de Catamarca";
    }
    else if (aeropuerto == CRD){
        resultado = "Comodoro Rivadavia";
    }
    return resultado;
}