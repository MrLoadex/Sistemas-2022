#ifndef iostream
    #include <iostream>
    #include <iostream>
    #include <string>
    #include <fstream>
#endif
#include "../array/list.h"
#include "../arrayDin/listdin.h"
#include "../matrizDin/matrizDin.h"
#include "../structDin/structDin.h"
using namespace std;

void OptionSelector();

int main()
{
    OptionSelector();    
    system("pause");
    system("cls");
    return 0;
}

void OptionSelector()
{
    int option;
    string phrase;
    cout << "Seleccione una opcion:" << endl;
    cout << "1) Trabajar con una lista" << endl;
    cout << "2) Trabajar con una lista dinamica" << endl;
    cout << "3) Trabajar con una frase" << endl;
    cout << "4) trabajar con una matriz dinamica" << endl;
    cout << "5) Trabajar con una lista dinamica de estructuras" << endl;
    cin >> option;
    system("cls");
    switch (option)
    {
    case 1:
        FillVector();
        IdentifyEven_Odd();
        FindTheSmallestNumber();
        break;
    case 2:
        FillDinamicVector();
        OrderDinamicVector();
        DeletedinamicArray();
        break;
    case 3:
        phrase = EnterPhrase();
        FindVowels(&phrase);
    case 4:
        SizeMatrixDefine();
        LoadDinMatrix();
        LoadDinMatrixTransposed();
        MultiplyMatrixTranspose();
        DeleteDinamicMatrix();
        DeleteDinamicTransposeMatrix();
    case 5:
        Load_disk_students();
        ShowBestAvarage();
        DeletedDinamicStudentList();
    default:
        break;
    }
}