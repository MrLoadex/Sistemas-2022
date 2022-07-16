#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;

void lectura();

int main(){
 lectura();
 return 0;
}


void lectura(){ //Lee el archivo y busca la palabra mas larga.
 ifstream archivo;
 string palabra, max_palabra;
 int max_longitud = 0;
 
 archivo.open("frasesDeBjarme.txt");
 
 if(archivo.fail()){//comprueba que exista el archivo
  cout<<"\nNo se pudo abrir el archivo.";
  exit(1);
 }
 cout<<"\n";
 while(!archivo.eof()){ //Lo recorre hasta finalizarlo.
     archivo >> palabra; //la variable palabra toma el valor de cada palabra del archivo
     int longitud = palabra.length(); //Devuelve la cantidad de caracteres de la variable tipo string.
     if (longitud > max_longitud){//Comprueba si la longoitud de la actual palabra es mayor a la analisada
         max_longitud = longitud;//De ser asi se reemplazan los valores por los de la nueva palabra maxima
         max_palabra = palabra;
     }

    }
    cout << "La palabra mas larga es " << max_palabra << endl;//Imprime por pantalla.
 archivo.close();
}