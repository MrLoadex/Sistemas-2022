#include <iostream>
#include <string>
using namespace std;
typedef enum {empanadas, sandwich, picada} primerosPlatos;
typedef enum {tarta, sorrentinos, pescado} platosPrincipales;
typedef enum {helado, torta, brownie} postres;
string SelectPlatoInicial(int pi);
string SelectPlatoPrincipal(int pp);
string SelectPostre(int postre);

//ingresa: primer_plato, plato_principal y postre; nro_mes, nombre_mozo, fecha, hora

int main()
{   
    int pedido, nro_mesa, plato_inicial, plato_principal, postre;
    string str_plato_inicial, str_plato_principal, str_postre, str_total_pedido, mozo = "Facundo";

    cout << "Mesa Nro: ";
    cin >> nro_mesa;

    cout <<"Cuantos pedidos completos desea hacer?" << endl;
    cin >> pedido;
    string str_pedido(to_string(pedido));
    str_total_pedido = str_pedido + " pedidos en total:\n";

    while (pedido >0){
        string str_pedido(to_string(pedido));
        cout << "Pedido " << pedido << endl;

        cout << "Plato inicial: \n1) Empanadas \n2) Sandwich \n3) Picada"<< endl;
        cin >> plato_inicial;
        str_plato_inicial = "Plato inicial: " + SelectPlatoInicial(plato_inicial);

        cout << "Plato principal: \n1) Tarta \n2) Sorrentinos \n3) Pescado"<< endl;
        cin >> plato_principal;
        str_plato_principal = "Plato principal: " + SelectPlatoPrincipal(plato_principal);

        cout << "Postre: \n1) Helado \n2) Torta \n3) Brownie"<< endl;
        cin >> postre;
        str_postre = "Postre: " + SelectPostre(postre);
        str_total_pedido += "Pedido: "+ str_pedido + ": " + str_plato_inicial + ", "+ str_plato_principal +", "+ str_postre + "\n" ;

        pedido --;
    }
    string mesa(to_string(nro_mesa));
    cout << "Mesa: " << mesa << endl << "mozo: "<< mozo << endl << str_total_pedido  << endl;
  
    return 0;
}

string SelectPlatoInicial(int pi){
    string plato;
    if (pi == empanadas){
        plato = "Empanadas";
    }
    else if (pi == sandwich){
        plato = "Sandwich";
    }
    else{
        plato = "Picada";
    }
    return plato;
}

string SelectPlatoPrincipal(int pp){
        string plato;
    if (pp == tarta){
        plato = "Tarta";
    }
    else if (pp == sorrentinos){
        plato = "Sorrentinos";
    }
    else{
        plato = "Pescado";
    }
    return plato;
}

string SelectPostre(int postre){
        string plato;
    if (postre == helado){
        plato = "helado";
    }
    else if (postre == torta){
        plato = "Torta";
    }
    else{
        plato = "Brownie";
    }
    return plato;
}