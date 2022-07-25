#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct{
    int ticket;
    string nombre;
    int dni;
    int edad;
    int asistente;
    int control;//Cuando control es 1 significa que es el ultimo
}tInvitado;
typedef tInvitado tInvitados[500];
tInvitados lista_de_invitados = {};
void Cargar_lista_de_invitados();//Carga las variables globales total_de_invitados y lista_de_invitados.
void Guardar_lista_de_invitados();//Guarda la informacion modificada en el archivo de texto.
void Mostrar_invitados(); //Muestra el los invitados por pantalla
void Agregar_invitado(); //Solicita los datos del invitado, los guarda en la variable total_de_invitados y en el txt. El nro de ticket es asignado por el nro de posicion -1
string Capitalize(string texto);//Devuelve el texto dado como parametro en Capitalize, se utiliza para el nombre.
void Modificar_datos(); //Se le ingresa como parametro el dato a modificar y el valor que se le desea asigna
void Eliminar_invitado();//Solicita un nro de ticket y elimina los datos.
void Mostrar_asistentes(); //Comprueba quienes confirmaron su asistencia.
void Menu();//Un menu para ir accediendio a las funciones
void Menu_modificar();//Submenu para modificar datos.
void Menu_asistencia();//Submenu para confirmar asistencia.

int main ()
{ 
    system("cls");
    Cargar_lista_de_invitados();
    Menu();
    Guardar_lista_de_invitados();
}

void Cargar_lista_de_invitados()
{
    ifstream archivo_invitados;
    archivo_invitados.open("invitados.txt");    
    int posicion_lista = 0;//posicion_lista se ira sumando para saber que espacio de memoria tenemos que ocupar en el array lista_de_invitados;
    if (archivo_invitados.is_open())
    {
        while (!archivo_invitados.eof())
        {
            archivo_invitados >> lista_de_invitados[posicion_lista].control;
            archivo_invitados >> lista_de_invitados[posicion_lista].ticket;
            archivo_invitados >> lista_de_invitados[posicion_lista].dni;
            archivo_invitados >> lista_de_invitados[posicion_lista].edad;
            archivo_invitados >> lista_de_invitados[posicion_lista].asistente;
            char aux;
            archivo_invitados.get(aux);
            getline(archivo_invitados, lista_de_invitados[posicion_lista].nombre),
            posicion_lista ++;//sumo uno para guardar los datos en el siguiente espacio de memoria de lista_de_invitados
        }
        if (lista_de_invitados[0].control == 0)
        {
            lista_de_invitados[0].control = 1;//Esto evita estar recorriendo todo el array de forma innecesaria.
        }
    }
    else//Si no hay ningun archivo crea uno.
    {
        ofstream archivo_invitados;
        archivo_invitados.open("invitados.txt");
        lista_de_invitados[0].control = 1;
        cout << "No se encontró ninguna lista de invitados, se creó una nueva en su lugar." << endl;
    }
    archivo_invitados.close();
}

void Mostrar_invitados()
{
    int posicion_invitado = 0;
    while (lista_de_invitados[posicion_invitado].control == 1)
    {
        //Convierto los datos de cada usuario en strings Para crear un solo string e imprimirlo en un cuadro.
        string ticket, nombre, dni, edad, asistente;
        if (lista_de_invitados[posicion_invitado].ticket < 10)//Para prolijidad de impresion agrego ceros segun corresponda a los tickets
        {
            ticket = "  00" + to_string(lista_de_invitados[posicion_invitado].ticket) + " ";
        }
        else if (lista_de_invitados[posicion_invitado].ticket < 100)
        {
            ticket = "  0" + to_string(lista_de_invitados[posicion_invitado].ticket) + " ";
        }
        if (lista_de_invitados[posicion_invitado].asistente == 0)
        {
            asistente = "    No    ";
        }
        else
        {
            asistente = "    Si    ";
        }
        //Agrego los espacios necesarios a la variable nombre para generar el cuadro que esta abajo
        nombre = " " + lista_de_invitados[posicion_invitado].nombre;
        int aux = 22-nombre.size();
        for(int i = 0; i < aux; i++)
        {
            nombre = nombre + " ";
        }        
        dni = " " + to_string(lista_de_invitados[posicion_invitado].dni);
        for(int i = dni.size(); i < 10; i++)
        {
            dni += " ";
        }
        edad = to_string(lista_de_invitados[posicion_invitado].edad);//Convierto edad en un string
        if ( stoi(edad) < 100) {edad = " " + edad + " ";} else {edad = " " + edad;}
        //IMPRIMO UN CUADRO EN CONSOLA (solo estetico)
        if (posicion_invitado == 0)
        {
            system("cls");
            cout << endl;
            cout << "==========================================================" << endl;
            cout << "|TICKET|  NOMBRE Y APELLIDO   |  D.N.I.  |EDAD|ASISTENTE |" << endl;
            cout << "|======|======================|==========|====|==========|" << endl;     
        }
        //Creo un string para imprimir el invitado de forma mas prolija
        cout << "|"<< ticket << "|" << nombre << "|" << dni <<"|" << edad << "|" << asistente << "|" << endl;

        if (lista_de_invitados[posicion_invitado+1].control == 1)
        {
            cout << "|======|======================|==========|====|==========|" << endl;
        }
        else
        {
            cout << "==========================================================" << endl;
        }
        posicion_invitado ++;
    }
}

void Mostrar_asistentes()
{
    string nombre;
    int nro_invitado = 0, ticket, total_asistentes = 0;
    cout << "Asistentes: " << endl;
    while (lista_de_invitados[nro_invitado].control == 1)
    {
        if (lista_de_invitados[nro_invitado].asistente == 1)
        {
        total_asistentes ++;
            string ticket, nombre, edad, asistente, dni; //Para prolojidad del codigo, convierto los datos de cada usuario en strings.
            if (lista_de_invitados[nro_invitado].ticket < 10)//Para prolijidad de impresion agrego ceros segun corresponda a los tickets
            {
                ticket = "  00" + to_string(lista_de_invitados[nro_invitado].ticket)+ " ";
            }
            else if (lista_de_invitados[nro_invitado].ticket < 100)
            {
                ticket = "  0" + to_string(lista_de_invitados[nro_invitado].ticket) + " ";
            }
            if (lista_de_invitados[nro_invitado].asistente == 0)
            {
                asistente = "    No    ";
            }
            else
            {
                asistente = "    Si    ";
            }
            nombre = " " + lista_de_invitados[nro_invitado].nombre;
            int aux = 22-nombre.size();
            for(int i = 0; i < aux; i++)
            {
                nombre = nombre + " ";
            }  
            dni = " " + to_string(lista_de_invitados[nro_invitado].dni);
            for(int i = dni.size(); i < 10; i++)
            {
                dni += " ";
            }
            edad = to_string(lista_de_invitados[nro_invitado].edad);
            if ( stoi(edad) < 100) {edad = " " + edad + " ";} else {edad = " " + edad;}
            //IMPRIMO UN CUADRO EN CONSOLA (solo estetico)
            if (total_asistentes == 1)
            {
                system("cls");
                cout << endl;
                cout << "==========================================================" << endl;
                cout << "|TICKET|  NOMBRE Y APELLIDO   |  D.N.I.  |EDAD|ASISTENTE |" << endl;
                cout << "|======|======================|==========|====|==========|" << endl;       
            }
            cout << "|"<< ticket << "|" << nombre << "|" << dni <<"|" << edad << "|" << asistente << "|" << endl;

        }
        nro_invitado ++;
    }
    cout << "==========================================================" << endl;
    cout << "Al momento " << total_asistentes << " asistentes confirmados." << endl;
}

void Guardar_lista_de_invitados()
{
    ofstream archivo_invitados("invitados.txt");
    int i = 0;
    string ticket, nombre, apellido, dni, edad, asistente, control, lista = "";
    while (lista_de_invitados[i].control == 1)
    {
        ticket = to_string(lista_de_invitados[i].ticket);
        dni = to_string(lista_de_invitados[i].dni);
        edad = to_string(lista_de_invitados[i].edad);
        asistente = to_string(lista_de_invitados[i].asistente);
        control = to_string(lista_de_invitados[i].control);
        nombre = lista_de_invitados[i].nombre;
        lista += control + " " + ticket + " " + dni + " " + edad + " " + asistente + " " + nombre + "\n";
        i ++;
    }
    archivo_invitados << lista;
    archivo_invitados.close();
    cout << "\nLista actualizada con exito!\n";
}

void Agregar_invitado()
{
    int cantidad_invitados = 0;
    //BUSCO EL ULTIMO INVITADO CARGADO EN EL ARRAY.
    while (lista_de_invitados[cantidad_invitados].control == 1)
    {
        cantidad_invitados ++;//Mientras control sea 1 el invitado esta cargado y pasara al siguiente en el array.
    }
    int dni, edad, asistente;
    string nombre;
    //Comprueba si no hay ningun invitado. De ser asi comienza por la posicion 0.
    if (cantidad_invitados == 1 && lista_de_invitados[0].ticket == 0)
    {
        cantidad_invitados = 0;
        lista_de_invitados[0].ticket = 1;
        /*Si cantidad_invitados es 1 existe la posibilidad de que el array este vacio, por lo cual comprueba
        si ticket tambien es 0, de ser asi significa que el array, y por lo tanto el txt estan vacios, y comienza desde
        la posicion 0.*/  
    }
    else
    {
        lista_de_invitados[cantidad_invitados].ticket = lista_de_invitados[cantidad_invitados-1].ticket+1;
    }
    cout << "Nombre y Apellido completo (NO utilizar tildes ni la letra Ñ): ";
    cin.ignore();
    getline(cin,nombre);
    nombre = Capitalize(nombre);
    lista_de_invitados[cantidad_invitados].nombre = nombre;
    cout << "D.N.I.: ";
    cin >> dni;
    lista_de_invitados[cantidad_invitados].dni = dni;
    cout << "Edad: ";
    cin >> edad;
    lista_de_invitados[cantidad_invitados].edad = edad;
    cout << "Confirmo asistencia?" << endl <<
    "0) No" << endl <<
    "1) si" << endl <<
    "Opcion: ";
    cin >> asistente;
    lista_de_invitados[cantidad_invitados].asistente = asistente;
    lista_de_invitados[cantidad_invitados].control = 1;
}

void Modificar_datos()
{
    string nombre;
    int ticket, valor, opcion, posicion_invitado = 0;
    Mostrar_invitados();
    cout << "Ingrese el ticket de quen desee modificar algun dato: ";
    cin >> ticket;
    while (lista_de_invitados[posicion_invitado].control ==1)
    {
        if (lista_de_invitados[posicion_invitado].ticket == ticket)
        ticket = posicion_invitado;
        posicion_invitado ++;
    }
    system("cls");
    cout << "Que dato desea modificar?" << endl << 
    "1) Nombre" << endl <<
    "2) D.N.I." << endl <<
    "3) Edad" << endl <<
    "4) Asistente" << endl;
    cin >> opcion;
    if (opcion == 1)
    {
        cout << "Nuevo nombre:";
        cin.ignore();
        getline(cin, nombre);
        nombre = Capitalize(nombre);
        lista_de_invitados[ticket].nombre = nombre;
    }
    else if (opcion == 2)
    {
        cout << "Nuevo D.N.I.: ";
        cin >> valor;
        lista_de_invitados[ticket].dni = valor;
    }
    else if (opcion == 3)
    {
        cout << "Nueva edad: ";
        cin >> valor;
        lista_de_invitados[ticket].edad = valor;
    }
    else if (opcion == 4)
    {
        cout << "Confirmo asistencia?" << endl <<
        "0) No" << endl <<
        "1) Si" << endl;
        cin >> valor;
        lista_de_invitados[ticket].asistente = valor;
    }
}

void Eliminar_invitado()
{
    int posicion_invitado, ticket, eliminar = 0;
    Mostrar_invitados();
    cout << "Elimine por numero de ticket" << endl;
    cout << "Ticket: ";
    cin >> ticket;
    posicion_invitado = ticket - 1;
    while (lista_de_invitados[posicion_invitado].control == 1)
    {

        if (eliminar == 1 || lista_de_invitados[posicion_invitado].ticket == ticket)
        {
            if (eliminar == 0){eliminar = 1;}
            lista_de_invitados[posicion_invitado] = lista_de_invitados[posicion_invitado+1];
        }
        posicion_invitado ++; 
    } 
}

void Menu()
{
    int seleccion = -1;
    bool primer_inicio = true;
    while (seleccion != 0)
    {
        if (primer_inicio)
        {
            primer_inicio = false;
        }
        else
        {
            cout << "Precione enter para continuar ... ";
            cin.ignore();
            cin.get();
            system("cls");
        }
        cout <<
        "=============================================" << endl <<
        "|Seleccione La Opcion Que Desee:            |" << endl <<
        "|===========================================|" << endl <<
        "|[1] Ver Invitados                          |" << endl <<
        "|===========================================|" << endl <<
        "|[2] Ver Asistentes                         |" << endl <<
        "|===========================================|" << endl <<
        "|[3] Agregar Invitado                       |" << endl <<
        "|===========================================|" << endl <<
        "|[4] Confirmar Asistente                    |" << endl <<
        "|===========================================|" << endl <<
        "|[5] Modificar o Eliminar Invitado          |" << endl <<
        "|===========================================|" << endl <<
        "|[0] Salir                                  |" << endl <<
        "|===========================================|" << endl <<
        "                Opcion: ";
        cin >> seleccion;
        system("cls");
        
        switch(seleccion)
        {
            case 1:
                Mostrar_invitados();
                break;
            case 2:
                Mostrar_asistentes();
                break;
            case 3:
                Agregar_invitado();
                break;
            case 4:
                Menu_asistencia();
                break;
            case 5:
                Menu_modificar();
                break;
            case 0:
                cout << "Hasta pronto!";
                break;
            default:
                system("cls");
                cout << "Opcion no valida." << endl;
                break;
        }
    }
}

void Menu_modificar()
{
    int seleccion;

    cout <<
    "1) Modificar datos de los invitados" << endl << 
    "2) Eliminar un invitado" << endl <<
    "3) Atras" << endl <<
    "Opcion: ";
    cin >> seleccion;
    system("cls");
    switch (seleccion)
    {
    case 1:
        Modificar_datos();
        break;
    case 2:
        Eliminar_invitado();
        break;
    default:
        break;
    }
    
}

void Menu_asistencia()
{
    Mostrar_invitados();
    cout << "Seleccione el invitado que desea confirmar asistencia: ";
    int posicion_invitado = 0, ticket;
    cin >> ticket;
    while (lista_de_invitados[posicion_invitado].control == 1)
    {
        if (lista_de_invitados[posicion_invitado].ticket == ticket)
        {
            lista_de_invitados[posicion_invitado].asistente = 1;
        }
        posicion_invitado ++;  
    }
}

string Capitalize(string texto)
{
    for(int relleno=0; texto[relleno]!='\0' ; relleno++)
    {
    if(relleno == 0 or texto[relleno-1]==' ')
    {
        texto[relleno] = toupper(texto[relleno]);
    }
    else
    {
        texto[relleno] = tolower(texto[relleno]);
    }
}
return texto;
}
