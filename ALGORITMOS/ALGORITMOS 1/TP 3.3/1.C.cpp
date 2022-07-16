#include<iostream>
#include<fstream>
#include <string>
using namespace std;

void lectura();

int main(){
 lectura();
 return 0;
}


void lectura(){
 ifstream archivo;
 string linea;
 
 archivo.open("frasesDeBjarme.txt");
 
 if(archivo.fail()){
  cout<<"\nNo se pudo abrir el archivo.";
  exit(1);
 }
 cout<<"\n";
 int linea_nro = 0,totalpalabras = 0;
 while(!archivo.eof()){
     linea_nro ++;
     getline(archivo, linea);
     int palabras_linea = 0, primer_letra = 1;
     for(int i=0;i<linea.length();i++){ 
        if(primer_letra == 1 && linea[i] == ' '){ //Comprueba que exista la primer palabra.
            primer_letra = 0; //Cierra el if.
            palabras_linea = 1;
        }

        if(linea[i-1] == ' '){/*Cuando hay una espacio detras de un caracter significa 
        que es otra palabra, asi que suma una palabra.*/
            palabras_linea += 1;
        }
     }
     cout << "La linea " << linea_nro << " tiene " << palabras_linea << " palabras.\n";
     totalpalabras += palabras_linea;

    }
 double promedio_palabras = totalpalabras / linea_nro; // calcula el promedio de palabras por linea.
 cout << "Lo que da un promedio de " << promedio_palabras << " por linea.\n";
 
 archivo.close();
}