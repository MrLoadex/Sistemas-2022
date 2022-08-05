#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string ConvertDecimalTo(string num, int base);
string ConvertNumToDecimal(string num, int base);
string To_HexadecimalSymbol(int num);
int Menu();

string ConvertNumToDecimal(string num,int base)
{
    int unitList[30][2];// Guarda los numeros descompuestos unidad por unidad (de atras para delante).
    int end_int_part = 0; //Aca se almacenara el indice donde finaliza la parte entera.
    for (int i = 0; i <= num.size()-1; i ++)
    {
        char letter = num[i];
        //Si finalizo la parte entera significa que hubo un punto que no se almaceno y hay que corregir eso.
        if (end_int_part != 0){i--;}
        unitList[i][1] = 1;
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
        else if (letter == '.')//Aqui finaliza la aprte entera.
        {
            i--;
            end_int_part = i;
            end_int_part = i;
        }
        if (end_int_part != 0){i++;}
        if (i == num.size()-1 && end_int_part == 0){end_int_part = i;}
    }
    //Finalizada la descomposicion, comenzamos a operar con los numeros obtenidos.
    int power_num = end_int_part; //Este sera el numero por el que se vaya elevando nuestro numero final.
    int decimal_i;
    double result = 0;
    for (int i = 0; i < 30; i ++)
    {
        result += unitList[i][0]*pow(base,power_num);
        power_num --;
        if (unitList[i+1][1] != 1){i = 31; cout << endl;}//Finalizo el bucle si el control es 0.

    }
    string str_result = to_string(result); //Usa un string por que mover double o float es demasiado erratico.
    return str_result;
}

string ConvertDecimalTo(string num, int base)
{
    //Separa parte entera y decimal
    float num_float = stof(num);
    int num_int = num_float; //Convierte parte entera en integer
    num_float -= num_int;
    /*
    Dividide consecutivas veces por la base deseada hasta que el cociente sea 0.
    Guarda en un string los numeros obtenidos.
    Si es sistema hexadecimal cambia los numeros por los simbolos correspondientes.
    Luego invierte el orden de los elementos.
    */
    string int_result = "";
    for (int i = 0; num_int != 0; i++)
    {
        int rest = num_int % base;
        int_result += To_HexadecimalSymbol(rest);
        num_int /= base;
    }
    string aux ="";
    for (int i = int_result.size()-1; i >= 0; i--)
    {
        aux += int_result[i];
    }
    int_result = aux;// Resultado de la parte entera.

    /*Comienza a trabajar con la parte decimal*/

    if (num_float == 0) {return int_result;}//Comprueba que haya una parte decimal
    /*Multiplica por la base deseada hasta que quede en 0
    Almacena la parte entera en un string*/
    string float_result = "";
    while (num_float > 0)
    {
        num_float *= base;
        int aux = num_float;
        float_result += To_HexadecimalSymbol(aux);//Comprueba si esta en sistema hexadecimal.
        if (num_float > 0) {num_float -= aux;}
    }
    //Guarda ambos datos y los devuelve.
    string result = int_result + "." + float_result;
    return result;
}

string To_HexadecimalSymbol(int num)
{
    if (num == 10){return "A";}
    if (num == 11){return "B";}
    if (num == 12){return "C";}
    if (num == 13){return "D";}
    if (num == 14){return "E";}
    if (num == 15){return "F";}
    return to_string(num);
}

int Menu()
{
    int base;
    string num;
    cout << "Seleccione 0 para salir." << endl;
    cout << "Seleccione el sistema numerico de origen: ";
    cin >> base;
    if (base == 0) {return 0;}
    cout <<"Numero de origen: ";
    cin >> num;
    string DecimalNumber = ConvertNumToDecimal(num,base);

    cout << "Seleccione el sistema numerico al que desea convertirlo: ";
    cin >> base;
    system("cls");
    cout << endl << "Resultado: " << ConvertDecimalTo(DecimalNumber,base) << endl
    << "Precione Enter para continuar";
    cin.get();
    cin.get();

    return 1;
}

int main()
{
    int salir = 1;
    while(salir != 0)
    {
        salir = Menu();
    }
}
