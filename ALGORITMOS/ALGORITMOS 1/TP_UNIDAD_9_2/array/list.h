#ifndef iostream
    #include <iostream>
#endif

//Llena el vector de 10 numeros
void FillVector();

//Identifica numeros pares e impares de un arreglo y lo imprime por pantalla
void IdentifyEven_Odd();

//Encuentra el menor numero del vector y lo imprime por pantalla
void FindTheSmallestNumber();

/*Pedir una cadena de caracteres (string) al usuario, e indicar cuantas veces
aparece la vocal a,e,i,o,u; en la cadena de caracteres.*/

//Permite al usuario ingresar una frase
std::string EnterPhrase();

//Encuentra las vocales de una frase y las imprime
void FindVowels(std::string *phrasePtr);