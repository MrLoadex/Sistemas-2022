#include "list.h"
#ifndef iostream
    #include <iostream>
    #include <fstream>
    #include <string>
#endif
using namespace std;

int nums[10];
int *identifier_ptr;

void FillVector()
{
    
    cout << "Ingrese 10 numeros enteros." << endl;
    for(int i = 0; i < 10; i ++)
    {
        cout << "Numero " << i+1 << " de " << 10 << endl;
        cout << "Numero: ";
        cin >> *identifier_ptr;
        *identifier_ptr++;
    }
}

void IdentifyEven_Odd()
{
    identifier_ptr = nums;
    for(int i = 0; i < 10; i ++)
    {
        if (*identifier_ptr%2 == 0)
        {
            cout << "El numero " << *identifier_ptr << " es par" << endl;
            cout << "Y esta ubicado en la direccion de memoria" << identifier_ptr << endl;
        }
        else
        {
            cout << "El numero " << *identifier_ptr << " es inpar" << endl;
            cout << "Y esta ubicado en la direccion de memoria" << identifier_ptr << endl;
        }
        *identifier_ptr++;
        cout << endl;
    }
}

void FindTheSmallestNumber()
{
    identifier_ptr = nums;
    int max_num = *identifier_ptr;
    for(int i = 0; i < 10; i ++)
    {
        if (max_num > *identifier_ptr)
        {
            max_num = *identifier_ptr;
        }
        identifier_ptr ++;
    }
    cout << "El numero mas chico es: " << max_num << endl;
}

string EnterPhrase()
{
    string phrase;
    cout << "Ingrese una frase: " << endl;
    getline(cin,phrase);
    return phrase;
}

void FindVowels(string *phrasePtr)
{
    string phrase;
    phrase = *phrasePtr;
    int a = 0, e = 0, i = 0, o = 0, u = 0;//CONTADORES
    for (int i = 0; i< phrase.size(); i++)
    {
        cout << phrase[i];
        if(phrase[i] == 'a' || phrase[i] == 'A')
        {
            a++;
        }
        else if(phrase[i] == 'e' || phrase[i] == 'E')
        {
            e++;
        }
        else if(phrase[i] == 'i' || phrase[i] == 'I')
        {
            i++;
        }
        else if(phrase[i] == 'o' || phrase[i] == 'O')
        {
            o++;
        }
        else if(phrase[i] == 'u' || phrase[i] == 'U')
        {
            u++;
        }
    }
    cout << "Su frase tiene: " << endl;
    cout << a << " letras A" << endl;
    cout << e << " letras E" << endl;
    cout << i << " letras I" << endl;
    cout << o << " letras O" << endl;
    cout << u << " letras U" << endl;
}