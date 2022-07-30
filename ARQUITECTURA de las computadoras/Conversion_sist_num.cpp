#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string ConvertDecimalTo(float decimal, int base);
int ConvertIntPartToDecimal(int num, int base);
string ConvertFractionalPartToDecimal(string intOrDecimalPart, string num, int base);
void DecomposeNum(string num);
void Menu();

string ConvertIntToDecimal(string intOrDecimalPart, string num,int base)
{
    int unitList[30][2];// Guarda los numeros descompuestos unidad por unidad (de atras para delante).
    int end_int_part = 0; //Aca se almacenara el indice donde finaliza la parte entera.
    for (int i = 0; i <= num.size()-1; i ++)
    {
        char letter = num[i];
        unitList[i][1] = 1;
        if (end_int_part != 0){i--;}//Si finalizo la parte entera significa que hubo un punto que no se almaceno y hay que corregir eso.
        if (letter == '0'){unitList[i][0] = 0;}
        else if (letter == '1'){unitList[i][0] = 1;}
        else if (letter == '2'){unitList[i][0] = 2;}
        else if (letter == '3'){unitList[i][0] = 3;}
        else if (letter == '4'){unitList[i][0] = 4;}
        else if (letter == '5'){unitList[i][0] = 5;}
        else if (letter == '6'){unitList[i][0] = 6;}
        else if (letter == '7'){unitList[i][0] = 7;}
        else if (letter == '8'){unitList[i][0] = 8;}
        else if (letter == '9'){unitList[i][0] = 9;}
        else if (letter == 'A' || letter == 'a'){unitList[i][0] = 10;}
        else if (letter == 'B' || letter == 'b'){unitList[i][0]= 11;}
        else if (letter == 'C' || letter == 'c'){unitList[i][0] = 12;}
        else if (letter == 'D' || letter == 'd'){unitList[i][0] = 13;}
        else if (letter == 'E' || letter == 'e'){unitList[i][0] = 14;}
        else if (letter == 'F' || letter == 'f'){unitList[i][0] = 15;}
        else if (letter == '.'){i--; end_int_part = i;}//Aqui finaliza la aprte entera.
        if (end_int_part != 0){i++;}
        //Si no posee parte fracionaria...
        if (i == num.size()-1 && end_int_part == 0){end_int_part = i;}
    }
    //Finalizada la descomposicion, comenzamos a operar con los numeros obtenidos.
    int power_num = end_int_part; //Este sera el numero por el que se vaya elevando nuestro numero final.
    int decimal_i;
    double result = 0;
    for (int i = 0; i <= 30; i ++)
    {
        result += unitList[i][0]*pow(base,power_num);
        power_num --;
        if (unitList[i+1][1] != 1){i = 31; cout << endl;}//Finalizo el bucle si el control es 0.

    }
    string str_result = to_string(result); //Usa un string por que mover double o float es demasiado erratico.
    return str_result;
}

void DecomposeNum(string num)
{

}

int main()
{
    cout << ConvertIntToDecimal("decimal_part","111.11", 2);
}