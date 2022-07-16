#include<iostream>
#include<fstream>
using namespace std;

void lectura();

int main(){
 lectura();
 return 0;
}


void lectura(){ //Lee un archivo .txt y lo imprime en pantalla.
 ifstream archivo;
 string texto;
 archivo.open("frasesDeBjarme.txt");
 if(archivo.fail()){//Comprueba la existencia del archivo.
  cout<<"\nNo se pudo abrir el archivo.";
  exit(1);
 }
 cout<<"\n";
 
 while(!archivo.eof()){ // Este while va recorriendo linea por linea del archivo e imprimiendo por pantalla.
  getline(archivo,texto);
  cout<<texto<<endl;
 }
 archivo.close();
}