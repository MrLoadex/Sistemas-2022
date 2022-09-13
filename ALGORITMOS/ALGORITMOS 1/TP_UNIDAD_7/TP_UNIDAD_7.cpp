#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int total_students = 0;
const int N = 100;
typedef struct 
{
    string name;
} tStudent;
typedef tStudent tStudentList[N];
tStudentList student_list;
bool operator>(tStudent opIzq, tStudent opDer)
{
    return (opIzq.name > opDer.name);
}
bool operator<(tStudent opIzq, tStudent opDer)
{
    return (opIzq.name < opDer.name);
}

void Load_disk_students();
void Save_disk_students();
void Show_students();
int Search_student(bool show_data);
void Destroy_student();
void Add_student();
void Organize(string order);//orden ascending || descending
int Function_selector();
void Menu_Organize();

int main()
{
    Load_disk_students();
    int selection;
    while (selection != 0)
    {
        selection = Function_selector();
        system("pause");
    }
    Save_disk_students();
    return 0;
}

void Load_disk_students()
{
    ifstream students_file;
    students_file.open("students.txt");


    if (students_file.is_open())
    {
        while (!students_file.eof())
        {   
            getline(students_file,student_list[total_students].name);
            total_students ++;
        }
    }
    else//Si no hay ningun archivo crea uno.
    {
        ofstream students_file;
        students_file.open("students.txt");
        cout << "No habia registro de alumnos, se creo uno." << endl;
    }
    total_students--;
    students_file.close();
}

void Save_disk_students()
{
    string list ="";

    int save_selection;
    cout << "Desea guardar los cambios?" << endl;
    cout << "1) Si" << endl;
    cout << "0) No" << endl;
    cin >> save_selection;
    cin.ignore();
    if  (save_selection == 0)
    {
        cout << "Esta a punto? Perdera todos sus cambios!" << endl;
        cout << "Precione 0 para continuar o cualquier otro numero para actualizar la lista." << endl;
        cin >> save_selection;
        if  (save_selection == 0) {return;}
    }
    for(int i = 0; i <= total_students; i ++)
    {
        list += student_list[i].name;
        if (i != total_students)
        {
            list += "\n";
        }  
    }
    ofstream students_file("students.txt");
    students_file << list;
    students_file.close();
    cout << "\nLista actualizada con exito!\n";
}

void Show_students()
{
    for (int i = 0; i <= total_students; i++)
    {
        cout << student_list[i].name << endl;
    }   
}

void Destroy_student()
{   
    string student;
    int pos, confirmation_destroy;
    Show_students();
    cout << "ELIMINAR ALUMNO DE LA LISTA" << endl;
    pos = Search_student(false);
    if (pos == -1) {return;}
    //Confirmacion de eliminacion.
    cout << "Esta seguro que desea aliminar de la lista a " << student_list[pos].name << "?" << endl;
    cout << "1) SI" << endl;
    cout << "0) NO" << endl;
    cin >> confirmation_destroy;
    if (confirmation_destroy == 0) {return;}

    if (pos == -1) {return;}
    for (int i = pos; i < total_students; i++)
    {
        student_list[i] = student_list[i+1];
    }
    total_students--;
    cout << "Alumno eliminado." << endl;
}

void Add_student()
{
    string student;
    total_students ++;
    cout << "Nombre y apellido del alumno nuevo: ";
    cin.ignore();
    getline(cin, student);
    student_list[total_students].name = student;
    cout << endl <<"El alumno " << student << " fue agregado a la clase con exito!" << endl;
}

void Organize(string order)
{ 
    tStudent student_aux;
    bool ordering;

    for (int pos = 0; pos <= total_students; pos ++)
    {
        student_aux = student_list[pos];
        for (int i = pos; i <= total_students; i ++)
        {
            if ( order == "descending" && student_aux < student_list[i])
            {
                student_aux = student_list[pos];//AUX = DATO_VIEJO
                student_list[pos] = student_list[i]; // DATO_VIEJO -> LUGAR_NUEVO
                student_list[i] = student_aux; //LUGAR_VIEJO -> DATO_NUEVO
                student_aux = student_list[i]; //AUX -> DATO_VIEJO
            }
            else if (order == "ascending" && student_aux > student_list[i])
            {
                student_aux = student_list[pos];//AUX = DATO_VIEJO
                student_list[pos] = student_list[i]; // DATO_VIEJO -> LUGAR_NUEVO
                student_list[i] = student_aux; //LUGAR_NUEVO -> DATO_VIEJO
                student_aux = student_list[i]; //AUX -> DATO_VIEJO
            }
        }
    }
}

int Search_student(bool show_data)
{
    string student;
    cout << "Seleccione un estudiante: ";
    cin.ignore();
    getline(cin, student);
    for (int i = 0; i <= total_students; i++)
    {
        if (student == student_list[i].name)
        {
            if (show_data == true)
            {
                cout << "El estudiante " << student << " se encuentra en la poscion " << to_string(i+1) << " de la lista." << endl;
            }
            return i;
        }
        else if(i == total_students)
        {
            cout << "El alumno no existe" << endl;
            return -1;
        }
        
    }
    return 0;
}

int Function_selector()
{
    int selection;
    cout << "1) Mostrar lista de estudiantes." << endl;
    cout << "2) Buscar un estudiante." << endl;
    cout << "3) Eliminar un estudiante de la lista." << endl;
    cout << "4) Agregar un estudiante a la lista." << endl;
    cout << "5) Organizar lista de estudiantes." << endl;
    cout << "0) Salir." << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        Show_students();
        break;
    case 2:
        Search_student(true);
        break;
    case 3:
        Show_students();
        Destroy_student();
        break;
    case 4:
        Add_student();
        break;
    case 5:
        Menu_Organize();
        Show_students();
        break;
    case 0:
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
    return selection;
}

void Menu_Organize()
{
    int selection;
    system("clear");
    cout << "Organizar lista:" << endl;
    cout << "1) ascendente (A-Z)" << endl;
    cout << "2) descendente (Z-A)" << endl;
    cin >> selection;
    if (selection == 1) {Organize("ascending");}
    else if (selection = 2) {Organize("descending");}
    else {cout << "opcion incorrecta" << endl;}
}