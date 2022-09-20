#ifndef iostream
    #include <iostream>
    #include <iostream>
    #include <string>
    #include <fstream>
#endif
#include "../lista/list.h"
using namespace std;

tStudentPlusControl students = Load_disk_students("./lista/students.txt");

int Function_selector();

int main()
{
    int selection;
    while (selection != 0)
    {
        selection = Function_selector();
        system("pause");
        system("cls");
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
    cout << "6) Guardar." << endl;
    cout << "0) Salir." << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        Show_students(students);
        break;
    case 2:
        Search_student(true, students);
        break;
    case 3:
        Show_students(students);
        students = Destroy_student(students);
        break;
    case 4:
        students = Add_student(students);
        break;
    case 5:
        students = Menu_Organize(students);
        Show_students(students);
        break;
    case 6:
        Save_disk_students( "./lista/students.txt" ,students);
    break;
    case 0:
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
    return selection;
}