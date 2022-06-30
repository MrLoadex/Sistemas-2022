#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct{
    int ticket;
    string nombre;
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

int main ()
{ 
    Cargar_lista_de_invitados();
    Menu();
    Guardar_lista_de_invitados();
}

void Cargar_lista_de_invitados()
{
    ifstream archivo_invitados;
    archivo_invitados.open("invitados.txt");
    //posicion_lista se ira sumando para saber que espacio de memoria tenemos que ocupar en el array lista_de_invitados;
    int posicion_lista = 0, vacio = 1;//vacio es para saber si hay algun elemento en la lista. 
    //linea va tomando el valor de cada linea del archivo
    string valor = "", linea; //va tomando el valor de los diferentes datos antes de guardarlos donde corresponden.
    if (archivo_invitados.is_open())
    {
        while (!archivo_invitados.eof())
        {
            getline(archivo_invitados,linea);
            int dato = 0; // dato = (ticket = 0, nombre = 1, edad = 2, asistencia = 3)
            for(int i = 0; linea[i]!='\0' ; i++)
            {
                if(linea[i] != ',')//quiero saber cuando es una coma, por que es el sentinela que avisa del cambio de valor
                {
                    valor += linea[i];//Valor va tomando el valor de cada caracter de linea[i] y los va guadando y sumando
                }
                else//Si es una coma entonces significa que ya capturo un dato completo.
                {
                //Dependiendo del valor de dato es la variable a la que se le asignara el valor de la variable valor.
                    if (dato == 0)//ticket
                    {
                        lista_de_invitados[posicion_lista].ticket = stoi(valor);
                    }
                    else if (dato == 1)//nombre
                    {
                        lista_de_invitados[posicion_lista].nombre = valor;
                    }
                    else if (dato == 2)//edad
                    {
                        lista_de_invitados[posicion_lista].edad = stoi(valor);
                    }
                    else if(dato == 3)//asistente
                    {
                        lista_de_invitados[posicion_lista].asistente = stoi(valor);
                    }
                    else if(dato == 4)//control
                    {
                        lista_de_invitados[posicion_lista].control = stoi(valor);
                        if (stoi(valor) != 0)
                        {
                            vacio = 0;
                        }
                    }
                    valor = "";//reiniciamos la variable valor.
                    dato ++;//Pasamos al siguiente valor
                    
                }
            }
        posicion_lista ++; //sumo uno para guardar los datos en el siguiente espacio de memoria de lista_de_invitados
        }
        if (vacio == 1)
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
        string ticket, nombre, edad, asistente; //Para prolojidad del codigo, convierto los datos de cada usuario en strings.
        if (lista_de_invitados[posicion_invitado].ticket < 10)//Para prolijidad de impresion agrego ceros segun corresponda a los tickets
        {
            ticket = "00" + to_string(lista_de_invitados[posicion_invitado].ticket);
        }
        else if (lista_de_invitados[posicion_invitado].ticket < 100)
        {
            ticket = "0" + to_string(lista_de_invitados[posicion_invitado].ticket);
        }
        if (lista_de_invitados[posicion_invitado].asistente == 0)
        {
            asistente = "    No    ";
        }
        else
        {
            asistente = "    Si    ";
        }
        nombre = " " + lista_de_invitados[posicion_invitado].nombre;
        int aux = 36-nombre.size();
        for(int i = 0; i < aux; i++)
        {
            nombre = nombre + " ";
        }
        edad = to_string(lista_de_invitados[posicion_invitado].edad);
        if ( stoi(edad) < 100) {edad = " " + edad + " ";} else {edad = " " + edad;}
        //IMPRIMO UN CUADRO EN CONSOLA (solo estetico)
        if (posicion_invitado == 0)
        {
            system("clear");
            cout << endl;
            cout << "=============================================================" << endl;
            cout << "|TICKET|               NOMBRE               |EDAD|ASISTENTE |" << endl;
            cout << "|======|====================================|====|==========|" << endl;     
        }
        cout << "|   "<< ticket << "|" << nombre << "|" << edad << "|" << asistente << "|" << endl;

        if (lista_de_invitados[posicion_invitado+1].control == 1)
        {
            cout << "|======|====================================|====|==========|" << endl;
        }
        else
        {
            cout << "=============================================================" << endl;
        }
        posicion_invitado ++;
    }
}

void Guardar_lista_de_invitados()
{
    ofstream archivo_invitados("invitados.txt");
    int i = 0;
    string ticket, nombre, edad, asistente, control, lista = "";
    while (lista_de_invitados[i].control == 1)
    {
        ticket = to_string(lista_de_invitados[i].ticket);
        nombre = lista_de_invitados[i].nombre;
        edad = to_string(lista_de_invitados[i].edad);
        asistente = to_string(lista_de_invitados[i].asistente);
        control = to_string(lista_de_invitados[i].control);
        lista += ticket + "," + nombre + "," + edad + "," + asistente + "," + control + ",\n";
        i ++; 
    }
    archivo_invitados << lista;
    archivo_invitados.close();
    cout << "\nLista actualizada con exito!\n";
}

void Agregar_invitado()
{
    int cantidad_invitados = 0;
    while (lista_de_invitados[cantidad_invitados].control == 1){
        cantidad_invitados ++;//Mientras entre al ciclo ira sumando invitados.
    }//Mientras control sea 1 el invitado esta cargado
    int edad, asistente;
    string nombre;
    if (cantidad_invitados == 1 && lista_de_invitados[0].ticket == 0)//Compruebo si el control es 1, de no ser asi le asigno el valor correspondiente al ticket, en funcion del valor anterior
    {
        cantidad_invitados = 0;
        lista_de_invitados[0].ticket = 1;  
    }
    /*Si es 1 existe la posibilidad de que *el array este vacio, por lo cual comprueba
    si ticket tambien es 0, de ser asi significa que el array y por lo tanto el txt estan vacios y comienza desde
    la posicion 0.*/
    else
    {
        lista_de_invitados[cantidad_invitados].ticket = lista_de_invitados[cantidad_invitados-1].ticket+1;
    }
    cout << "Nombre (por favor evite tildes y la letra ñ): ";
    cin.ignore();
    getline(cin,nombre);
    nombre = Capitalize(nombre);
    lista_de_invitados[cantidad_invitados].nombre = nombre;
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

string Capitalize(string texto)
{
    for(int relleno=0; texto[relleno]!='\0' ; relleno++)
    {
    if(texto[relleno-1]==' ' or relleno == 0)
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
    system("clear");
    cout << "Que dato desea modificar?" << endl << 
    "1) Nombre" << endl <<
    "2) Edad" << endl <<
    "3) Asistente" << endl;
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
        cout << "Nueva edad: ";
        cin >> valor;
        lista_de_invitados[ticket].edad = valor;
    }
    else if (opcion == 3)
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
    posicion_invitado--;
    while (lista_de_invitados[posicion_invitado].control == 1)
    {
        if (lista_de_invitados[posicion_invitado].ticket == ticket)
        {
            eliminar = 1;
        }
        if (eliminar == 1)
        {
            lista_de_invitados[posicion_invitado] = lista_de_invitados[posicion_invitado+1];
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
            string ticket, nombre, edad, asistente; //Para prolojidad del codigo, convierto los datos de cada usuario en strings.
            if (lista_de_invitados[nro_invitado].ticket < 10)//Para prolijidad de impresion agrego ceros segun corresponda a los tickets
            {
                ticket = "00" + to_string(lista_de_invitados[nro_invitado].ticket);
            }
            else if (lista_de_invitados[nro_invitado].ticket < 100)
            {
                ticket = "0" + to_string(lista_de_invitados[nro_invitado].ticket);
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
            int aux = 36-nombre.size();
            for(int i = 0; i < aux; i++)
            {
                nombre = nombre + " ";
            }
            edad = to_string(lista_de_invitados[nro_invitado].edad);
            if ( stoi(edad) < 100) {edad = " " + edad + " ";} else {edad = " " + edad;}
            //IMPRIMO UN CUADRO EN CONSOLA (solo estetico)
            if (total_asistentes == 1)
            {
                system("clear");
                cout << endl;
                cout << "=============================================================" << endl;
                cout << "|TICKET|               NOMBRE               |EDAD|ASISTENTE |" << endl;
                cout << "|======|====================================|====|==========|" << endl;     
            }
            cout << "|   "<< ticket << "|" << nombre << "|" << edad << "|" << asistente << "|" << endl;
        }
        nro_invitado ++;
    }
    cout << "=============================================================" << endl;
    cout << "Al momento " << total_asistentes << " asistentes confirmados." << endl;
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
            system("clear");
        }
        cout <<"Seleccione la opcion que desee: " << endl <<
        "1) Ver lista de invitados" << endl <<
        "2) Ver lista de asistentes" << endl <<
        "3) Modificar lista de invitados" << endl <<
        "0) Salir" << endl <<
        "Opcion: ";
        cin >> seleccion;
        system("clear");
        if (seleccion == 1)
        {
            Mostrar_invitados();
        }
        else if (seleccion == 2)
        {
            Mostrar_asistentes();
        }
        else if (seleccion == 3)
        {
            cout <<
            "1) Agregar invitados" << endl <<
            "2) Modificar datos de los invitados" << endl << 
            "3) Eliminar un invitado" << endl <<
            "4) Atras" << endl <<
            "Opcion: ";
            cin >> seleccion;
            system("clear");
            if (seleccion == 1)
            {
                Agregar_invitado();
            }
            else if (seleccion == 2)
            {
                Modificar_datos();
            }
            else if (seleccion == 3)
            {
                Eliminar_invitado();
            }
        }
        else
        {
            system("clear");
            cout << "Opcion no valida." << endl;
        }
    }
}
