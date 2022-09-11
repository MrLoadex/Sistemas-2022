#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct
{
    int id;
    double price;
    int units;
}tProduct;

const int max_products = 50;
typedef tProduct tProductsList[max_products];

tProductsList productList;

void Load_disk_products();//lee el archivo donde esta la informacion
void Show_products();//Muestra los productos en pantalla
void Show_max_value();//Imprime el producto acumulado que mas valor total tiene.
void Search_and_destroy();//busca y destruye un producto del array
void Save_file();

int main ()
{
    Load_disk_products();
    Show_products();
    Search_and_destroy();
    Save_file();
    return 0;
}

void Load_disk_products()
{
    ifstream products_file;
    products_file.open("products.txt");    
    short int id;
    short int list_position = 0;

    if (products_file.is_open())
    {
        while (!products_file.eof())
        {   
            products_file >> productList[list_position].id;
            products_file >> productList[list_position].price;
            products_file >> productList[list_position].units;
            list_position ++;
        }
        productList[list_position].id = -1;
    }
    else//Si no hay ningun archivo crea uno.
    {
        ofstream products_file;
        products_file.open("products.txt");
        cout << "No habia registro de ningun producto almacenado." << endl;
    }
    products_file.close();
}

void Show_products()
{
    /*
    lee el array con un bucle
        lee cada subdato
            muestra cada dato
    */
   system("cls");
   short int list_position = 0;
   while (productList[list_position].id != -1)
   {
    cout << "ID: " << productList[list_position].id << endl;
    cout << "PRECIO: " << productList[list_position].price << endl;
    cout << "CANTIDAD: " << productList[list_position].units << endl;
    cout << "==============" << endl;
    list_position ++;
   }
}

void Show_max_value()
{
    int id_max_value;
    double price_max_value = 0;
    int units_max_value = 0;
    int list_position = 0;
    while (productList[list_position].id != -1)//Busca el valor maximo
    {
        if (price_max_value * units_max_value < productList[list_position].price * productList[list_position].units)
        {
            id_max_value = productList[list_position].id;
            price_max_value =productList[list_position].price;
            units_max_value =productList[list_position].units;
        }
        list_position ++;
    }
    system("clear");
    cout << "MAYOR VALOR ACUMULADO EN EL PRODUCTI:" << endl;
    cout << "ID: " << id_max_value << endl;
    cout << "PRECIO: " << price_max_value << endl;
    cout << "CANTIDAD: " << units_max_value << endl;
    cout << "VALOR TOTAL: " << price_max_value * units_max_value << endl;
}

void Search_and_destroy()
{
    int id;
    cout << "ID del objeto a eliminar: ";
    cin >> id;
    int list_position = 0;
    while (id > productList[list_position].id)//Busca el producto a borrar.
    {
        if (productList[list_position].id == -1)
        {
            cout << "esa id no existe." << endl;
            break;
        }
        list_position ++;
    }

    do
    {
        productList[list_position] = productList[list_position +1];
        list_position ++;
    } while (productList[list_position].id != -1);//Cuando lo encuentra lo elimina y cubre el "hueco".
    cout << "Lista actualizada:" << endl;
    Show_products();
}

void Save_file()
{
    string list = "";
    int list_position = 0;
    while (productList[list_position].id != -1)
    {
        list += to_string(productList[list_position].id) + " ";
        list += to_string(productList[list_position].price) + " ";
        if (productList[list_position +1].id != -1)//Esto para que no guarde una linea vacia al final.
        {
            list += to_string(productList[list_position].units);
        }
        else
        {
            list += to_string(productList[list_position].units) + "\n";
        }
        list_position ++;
    }
    ofstream products_file("products.txt");
    products_file << list;
    products_file.close();
    cout << "Lista Guardada." << endl;
}