#include <iostream>
#include <fstream>
using namespace std;

int GuardarFrases(string frases);
string IntroducirFrases();

int main(){
    string frases = IntroducirFrases();
    GuardarFrases(frases);
    return 0;
}

string IntroducirFrases(){ //Permite introducir varias lineas de texto y devolver una variable con estas mismas como valor.
    string frase, frases;
    while (frase != "fin"){
        cout << "Intoduzca una frase: ";
        getline(cin, frase);
        if (frase != "fin"){
            frases += frase + "\n";
        }
        else{
            frases += "X";
        }
        cout << "CARGADA CON EXITO" << endl;
    }

    return frases;
}

int GuardarFrases(string frases){//solicita un string que lo almacena en frasesDeBjarme.txt
    ofstream archivo;
    if (!archivo.is_open())
  {
    cout << "Error al abrir frasesDeBjarme.txt\n";
    exit(EXIT_FAILURE);
  }
    archivo.open("frasesDeBjarme.txt");
    archivo << frases;
    return 0;
}