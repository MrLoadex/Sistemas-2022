#include "matrizDin.h"
#ifndef iostream
    #include <iostream>
    #include <fstream>
    #include <string>
#endif
using namespace std;

short int N;
short int M;

int **dinamic_matrix = new int*[N];
int **dinamic_transposed_matrix = new int*[M];

void SizeMatrixDefine()
{
    cout << "tamanio de la funcion" << endl;
    cout << "N: " << endl;
    cin >> N;
    cout << "M: ";
    cin >> N;
    system("cls");
}

void LoadDinMatrix()
{
    int entered_number;
    for (int i = 0; i < N; i++) {
        dinamic_matrix[i] = new int[M]; 
        for (int pos = 0; pos < M; pos ++)
        {
            cout << "Total: \n" << "Filas: " << N << ", columnas: " << M << endl;
            cout << "Ingrese el numero de la fila " << i + 1 << " columna  " << pos + 1 << endl;
            cout << "Numero: ";
            cin >> entered_number;
            dinamic_matrix[i][pos] = entered_number;
            system("cls");
        }
    }
}

void LoadDinMatrixTransposed()
{
    for (int i = 0; i < M; i++)
    {
        dinamic_transposed_matrix[i] = new int[N];
        for(int pos = 0; pos < N; pos ++)
        {
            dinamic_transposed_matrix[i][pos] = dinamic_matrix[pos][i];
        }
    }

}

void MultiplyMatrixTranspose()
{
    int total = 0, aux;

    for (int i = 0; i < N; i++)
    {
        for (int pos = 0; pos < M; pos++)
        {
            //imprime un label por consola
            cout << dinamic_matrix[i][pos] << " x " << dinamic_transposed_matrix[pos][i] << " + " ;
            //hace la ecuacion
            aux = dinamic_matrix[i][pos] * dinamic_transposed_matrix[pos][i];
            total += aux;
        }
    }
    cout << " 0 = " << total << endl; //El 0 es por estetica, y requiere menos recursos que un if dentro del for
}

void DeleteDinamicMatrix()
{
    //elimina elemento por elemento
    for (int i = 0; i < N; i++) delete dinamic_matrix[i];
    //elimina la matriz original
    delete dinamic_matrix;
    cout << "Matriz dinamica eliminada." << endl;
}

void DeleteDinamicTransposeMatrix()
{
    for (int i = 0; i < M; i++) delete dinamic_transposed_matrix[i];
    delete dinamic_transposed_matrix;
    cout << "Matriz dinamica transpuesta eliminada correctamente" << endl;
}