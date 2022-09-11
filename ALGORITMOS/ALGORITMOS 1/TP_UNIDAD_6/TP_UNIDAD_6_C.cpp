#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef int tList[3][3];//Usamos matrices de 3x3 para agilizar las cosas.
tList list1 = {1,2,3,4,5,6,7,8,9};
tList list2 = {9,8,7,6,5,4,3,2,1};

void Operate_matrices(char operation);
void Transpose_matriz();
void Show_matriz(tList list);
void Read_matriz(tList list);

int main()
{
    int option;
    cout << "Matrices Default: " << endl;
    cout << "Matriz 1:" << endl;
    Show_matriz(list1);
    cout << "Matriz 2:" << endl;
    Show_matriz(list2);
    
    while (option != 0)
    {
        cout << "selecione la opcion deseada:" << endl;
        cout << "1) Escribir una matriz" << endl;
        cout << "2) Transponer una matriz" << endl;
        cout << "3) Ver una matriz" << endl;
        cout << "0) SALIR" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "1) Modificar lista 1." << endl;
            cout << "2) Modificar lista 2." << endl;
            cin >> option;
            switch (option)
            {
            case 1:
               Read_matriz(list1);
                break;
            case 2:
               Read_matriz(list2);
                break;
            default:
                break;
            }
            break;
        case 2:
            Transpose_matriz();
            break;
        case 3:
            cout << "1) Ver lista 1." << endl;
            cout << "2) Ver lista 2." << endl;
            cin >> option;
            switch (option)
            {
            case 1:
               Show_matriz(list1);
                break;
            case 2:
               Show_matriz(list2);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        system("pause");
    }
    
    return 0;
}

void Operate_matrices(char operation)
{
    int x = 0;
    int y = 0;
    for (int x = 0; x < 3; x++) //X
    {
        for (int y = 0; y < 3; y++)//Y
        {
            if (operation == '*')
            {
                cout << list1[x][y]<< " x " <<list2[x][y] << ": "; 
                cout << list1[x][y] * list2[x][y] << endl;
            }
            else if (operation == '+')
            {
                cout << list1[x][y]<< " + " <<list2[x][y] << ": "; 
                cout << list1[x][y] + list2[x][y] << endl;
            }
            else if (operation == '-')
            {
                cout << list1[x][y]<< " - " <<list2[x][y] << ": "; 
                cout << list1[x][y] - list2[x][y] << endl;
            }
            
            
        }
        
    }   
}

void Transpose_matriz()
{
    tList listAux;//Lista que  
    for (int x = 0; x < 3; x++) //X
    { 
        for (int y = 0; y < 3; y++)//Y
        {
            cout << list1[x][y];
            listAux[y][x] = list1[x][y];
        }
        cout << endl;
    }
    cout << "lista 1: \n";
    Show_matriz(list1);
    cout << "lista Transpuesta: \n";
    Show_matriz(listAux);
}

void Show_matriz(tList list)
{ 
    for (int x = 0; x < 3; x++) //X
    { 
        for (int y = 0; y < 3; y++)//Y
        {
            cout << list[x][y];
        }
        cout << endl;
    }
}

void Read_matriz(tList list)
{
    cout << "Se utilizan matrices de 3x3, por favor completar los 9 datos."<< endl; 
    for (int x = 0; x < 3; x++) //X
    { 
        for (int y = 0; y < 3; y++)//Y
        {
            cout << "X: " << x << " Y: " << y << endl;
            cin >> list[x][y];
        }
        cout << endl;
    }
}
