#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string Convert_decimal_binary(int decimal); // Convierte decimal a binario (devolviendo un string)
string Convert_binary_decimal(int binary);
bool Detect_bugs(int num, string numerycal_sistem); // Detecta excepciones.
void Menu();

int main()
{
	int option = 1;
	system("cls");
	do
	{
		Menu();
		system("pause");
		system("cls");
		cout << "Desea hacer otra conversion?" << endl;
		cout << "1) Si" << endl;
		cout << "0) No" << endl;
		cin >> option;
	} while (option != 0);

	return 0;
}

string Convert_decimal_binary(int decimal) // Convierte decimal a binario
{
	string reverse_binary; // Almacena los digitos binarios deseados al reves.
	string binary = "";
	system("cls");
	/*Va dividiendo el decimal trabajando con enteros hasta que el resultado es 0
	y almacena los restos obtenidos.
	*/
	while (decimal != 0)
	{
		reverse_binary += to_string(decimal % 2);
		decimal /= 2;
	}
	// Da vuelta el numero asi queda el binario deseado.
	for (int i = reverse_binary.size() - 1; i >= 0; i--)
	{
		binary += reverse_binary[i];
	}
	return binary;
}

void Convert_binary_decimal(string binary)
{
	int numeros = 0;
	string resultados = "";
	int aux = 0;
	for (int i = binary.size() - 1; i >= 0; i--)
	{
		string iteracion_numero = "";
		iteracion_numero.append(1, binary[i]);

		numeros += stoi(iteracion_numero) * pow(2, aux);
		aux++;
	}
	cout << numeros << endl;
}

bool Detect_bugs(string num, string numerycal_sistem) // Detecta errores.
{
	bool bug = false; // Almacena true si hay error
	system("cls");
	// Comprueba que se haya ingresado un numero entero y si es binario que no sea otra cosa mas que 1 o 0.
	for (int i = num.size() - 1; i >= 0; i--)
	{
		for (int a = 9; a >= 0; a--) // Recorre el el "numero" caracter por caracter.
		{
			if (numerycal_sistem == "binary")
			{
				if (num[i] != '0' && num[i] != '1') /// pensar
				{
					bug = true;
					cout << "Solo se admiten los valores '0' y '1'" << endl;
					return bug;
				}
			}
			if (num[i] == a + '0') // Comprueba que cada caracter sea un numero
			{
				a = -1;
			}
			else if (a == 0)
			{
				cout << "Asegurese de ingresar un numero decimal sin puntos, comas u otro simbolo." << endl;
				bug = true;
				return bug;
			}
		}
	}
	if (num.size() > 8) // Comprueba que no sean mas de 8 caracteres.
	{
		bug = true;
		cout << "El numero no puede ser mayor a 8 numeros" << endl;
	}
	return bug;
}

void Menu()
{
	int option;
	string number;
	system("cls");

	cout << "Selecciones sistema numerico de origen:" << endl;
	cout << "1) Decimal" << endl;
	cout << "2) Binario" << endl;
	cin >> option;

	cout << "Ingrese el numero: ";
	cin >> number;

	switch (option)
	{
	case 1:
		if (Detect_bugs(number, "decimal") == false)
		{
			cout << number << " en binario es: ";
			cout << Convert_decimal_binary(stoi(number)) << endl;
		}
		break;
	case 2:
		if (Detect_bugs(number, "binary") == false)
		{
			Convert_binary_decimal(number);
		}
		break;
	default:
		cout << "Opcion incorrecta." << endl;
		break;
	}
}