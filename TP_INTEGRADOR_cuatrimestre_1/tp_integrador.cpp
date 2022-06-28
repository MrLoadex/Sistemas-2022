#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef string tInvitados[500];
int total_de_invitados= 0;
tInvitados lista_de_invitados = {};
void Cargar_lista_de_invitados();//Carga las variables globales total_de_invitados y lista_de_invitados.
void Guardar_lista_de_invitados();//Guarda la informacion modificada en el archivo de texto.
void Mostrar_invitados(); //Muestra el los invitados por pantalla
void Agregar_invitado(); //Solicita los datos del invitado, los guarda en la variable total_de_invitados y en el txt. El nro de ticket es asignado por el nro de posicion -1
string Capitalize(string texto);//Devuelve el texto dado como parametro en Capitalize, se utiliza para el nombre.
void Modificar_datos(string invitado, string dato, string valor); //Se le ingresa como parametro el dato a modificar y el valor que se le desea asignar
void Que_modificar();//Le da la opcion al usuario de lo que puede modificar.
void Eliminar_invitado();//Solicita un nro de ticket y elimina los datos.
void Mostrar_asistentes(); //Comprueba quienes confirmaron su asistencia.
void Menu();//Un menu para ir accediendio a las funciones

int main ()
{
    Cargar_lista_de_invitados();
    system("clear");
    //Que_modificar();
    //Mostrar_invitados();
    Menu();
    Guardar_lista_de_invitados();  
    return 0;
}

void Cargar_lista_de_invitados()
{
    ifstream archivo_invitados;
    archivo_invitados.open("invitados.txt");
    if (archivo_invitados.is_open())
    {
        string invitado;
        int contador = 0;
        system("clear");
        while(!archivo_invitados.eof()){ // Este while va recorriendo linea por linea del archivo e imprimiendo por pantalla.
            getline(archivo_invitados,invitado);
            lista_de_invitados[contador] = invitado;
            contador +=1;
        }
        total_de_invitados = contador - 1; //Termina en una linea vacia, asi que le resto uno para trabajar mejor.
    }
    else
    {
        ofstream archivo_invitados;
        archivo_invitados.open("invitados.txt");
        cout << "No se encontró ninguna lista de invitados, se creó una nueva en su lugar." << endl;
    }
    archivo_invitados.close();
}

void Mostrar_invitados()
{
    int invitados_mostrar;
    system("clear");
    cout << "Lista de invitados:" << endl <<
    "TICKET, APELLIDO Y NOMBRE, DNI, ASISTENCIA\n";
    int i = 0;
    while(i < total_de_invitados)
    {
        if (lista_de_invitados[i] != "ELIMINADO")
        {
            cout << lista_de_invitados[i] << endl;
            invitados_mostrar ++;
        }
        i ++;
    }
    invitados_mostrar --;
    cout << "Usted tiene " << invitados_mostrar << " invitados." << endl;
}

void Guardar_lista_de_invitados()
{
    ofstream archivo_invitados;
    archivo_invitados.open("invitados.txt");
    int i = 0;
    string lista_str;
    while(i < total_de_invitados)
    {
        lista_str += lista_de_invitados[i] + "\n";
        i++;
    }
    archivo_invitados << lista_str;
    archivo_invitados.close();
    cout << "\nLista actualizada con exito!\n";
}

void Agregar_invitado()
{
    system("clear");
    int dni, asistencia_eleccion;
    string invitado, nombre, asistencia, ticket= to_string(total_de_invitados + 1);
    cout << "Apellido y Nombre del invitado: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "DNI (sin puntos ni guones): ";
    cin >> dni;
    cout <<"Confirmó asistencia? \n1) Si confirmo. \n2) No confirmo.\n";
    cin >> asistencia_eleccion;
    if (asistencia_eleccion == 1) //if para saber si asistio o no.
    {
        asistencia = "confirmo";
    }
    else
    {
        asistencia= "no confirmo";
    }
    if (ticket.size() == 1)//Verifica cantidad de digitos de la variable ticket para agregarle 00.
    {
        ticket = "00" + ticket;
    }
    else if (ticket.size() == 2)
    {
       ticket= "0" + ticket; 
    }
    nombre = Capitalize(nombre);
    invitado = ticket+", "+ nombre + ", " + to_string(dni) + ", " + asistencia;
    lista_de_invitados[total_de_invitados] = invitado;
    cout << lista_de_invitados[total_de_invitados];
    total_de_invitados ++;
    Guardar_lista_de_invitados();
    cout << nombre+ " fue añadido/a a la lista." << endl;
    
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

void Modificar_datos(string invitado, string dato, string valor)
{
    int posicion_dato = 0, posicion_invitado;
    string dato_aux = "", ticket, nombre, dni, asistencia;
    for(int i = 0; invitado[i]!='\0' ; i++)//Recorre caracter por caracter.
    {
        if(invitado[i] !=',')//Comprueba si el caracter no es una coma
        {
            dato_aux += invitado[i]; // Si no es una coma lo almacena en dato_aux
        }
        else // Si es una coma comprueba que dato almacenó.
        {
             if (posicion_dato == 0) // comprueba si tiene el dato " ticket "
        {  
            if (dato != "ticket")//Comprueba que el dato a modificar no sea ticket
            {
                ticket = dato_aux; //Al no ser ticket  conserva el valor anterior
            }
            else // de ser ticket el dato a modificar le asigna el nuevo valor
            {
                ticket = valor;
            }
            posicion_invitado = stoi(ticket) -1; //Extraiga la posicion del invitado
        }
        else if (posicion_dato == 1) // nombre
        {
             if (dato != "nombre")
            {
                nombre = dato_aux;
            }
            else
            {
                nombre = valor;
            }
        }
        else if (posicion_dato == 2) //dni
        {
             if (dato != "dni")
            {
                dni = dato_aux;
            }
            else
            {
                dni = valor;
            }
        }
        else if (posicion_dato == 3) //asistencia
        {
             if (dato != "asistencia")
            {
                asistencia = dato_aux;
            }
            else
            {
                asistencia = valor;
            }
        }
        posicion_dato ++;
        dato_aux = "";
        }
        if (i == invitado.size()-1)// Para guardar la ultima variable tuve que manejar una excepcion, ya qye no hay , al final
        {
            if (dato != "asistencia")
            {
                asistencia = dato_aux;
            }
            else
            {
                asistencia = valor;
            }
        }
    }
    //Recopila los datos viejos y el nuevo y los almacena en la variable globarl.
    lista_de_invitados[posicion_invitado] = ticket + "," + Capitalize(nombre) + "," + dni + "," + asistencia;
    Guardar_lista_de_invitados();
}

void Que_modificar(){
    int seleccion, ticket;
    string dato, valor, invitado;
    system("clear");
    Mostrar_invitados();
    cout << "Ingrese el numero de ticket del invitado del que desea modificar algun dato: " << endl;
    cin >> ticket;
    invitado = lista_de_invitados[ticket-1];
    if (invitado != "ELIMINADO") //Comprobamos que el invitado no hjaya sido eliminado..
    {
        system("clear");
        cout << "Usted seleccionó a " + invitado + " asistencia al evento." << endl <<
        "Seleccione que desea modificar:" << endl <<
        "1) Nombre" << endl << "2) DNI" << endl << "3) Asistencia" << endl;
        cin >> seleccion;
        system("clear");
        if (seleccion == 1)
        {
            dato = "nombre";
            cout << "Ingrese el nuevo nombre: ";
            cin.ignore();
            getline(cin, valor);
        }
        else if (seleccion == 2)
        {
            dato = "dni";
            cout << "Ingrese el nuevo DNI: ";
            cin >> valor;
        }
        else if (seleccion == 3)
        {
            dato = "asistencia";
            cout << "Confirmó asistencia? \n1)Si \n2)No" << endl;
            cin >> seleccion;
            if (seleccion == 1)
            {
                valor = "confirmo";
            }
            else
            {
                valor = "no confirmo";
            }

        }
        Modificar_datos(invitado, dato, " " + valor);
    }
    else//Si el invitado fue eliminado saldra un mensaje informandole
    {
        cout << "ESTE TICKET FUE ELIMINADO!" << endl << endl << "El invitado debe ser registrado nuevamente" << endl << endl;
    }
}

void Eliminar_invitado()
{
    int ticket;
    system("clear");
    Mostrar_invitados();
    cout << "Seleccione el ticket invitado que desea eliminar: ";
    cin >> ticket;
    lista_de_invitados[ticket-1] = "ELIMINADO";
    Guardar_lista_de_invitados();
    cout << "Eliminado con exito!";
    


    
}

void Mostrar_asistentes()
{
    string invitado, total_asistentes = "", asistencia;
    int asistentes = 0;
    for(int ticket = 0; ticket < total_de_invitados ; ticket ++)
    {
        invitado = lista_de_invitados[ticket];

        for(int letra = 0; invitado[letra]!='\0' ; letra++)
        {
            asistencia += invitado[letra];
            if(invitado[letra] ==',')
            {
                asistencia = "";
            }
            if (letra == invitado.size()-1)
            {
                if (asistencia == " confirmo")
                {
                    total_asistentes += lista_de_invitados[ticket] + " asistencia.\n";
                    asistentes ++;//cuenta los asistentes que hay.
                }
                
            }
        }
    }
    system("clear");
    cout << "Lista de asistentes: " << endl;
    cout << total_asistentes << endl <<
    "Hay un total de " << asistentes << " asistentes." << endl;


}

void Menu()
{
    int seleccion = 0;
    bool primer_inicio = true;
    while (seleccion != 4)
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
        "4) Salir" << endl <<
        "Opcion: ";
        cin >> seleccion;
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
            system("clear");
            cout <<
            "1) Agregar invitados" << endl <<
            "2) Modificar datos de los invitados" << endl << 
            "3) Eliminar un invitado" << endl <<
            "Opcion: ";
            cin >> seleccion;
            if (seleccion == 1)
            {
                Agregar_invitado();
            }
            else if (seleccion == 2)
            {
                Que_modificar();
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
