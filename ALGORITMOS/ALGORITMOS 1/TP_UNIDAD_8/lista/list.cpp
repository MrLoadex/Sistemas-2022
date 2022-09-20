#include "list.h"
#ifndef iostream
    #include <iostream>
    #include <string>
    #include <fstream>
#endif
using namespace std;

bool operator>(tStudent opIzq, tStudent opDer)
{
    return (opIzq.name > opDer.name);
}
bool operator<(tStudent opIzq, tStudent opDer)
{
    return (opIzq.name < opDer.name);
}


tStudentPlusControl Load_disk_students(string studentsFilePath)
{
    int total_students = 0;
    tStudentPlusControl students;
    ifstream students_file;
    students_file.open(studentsFilePath);
    char aux;


    if (students_file.is_open())
    {
        while (!students_file.eof())
        {   
            students_file >> students.list[total_students].nota;
            students_file.get(aux);
            getline(students_file,students.list[total_students].name);
            total_students ++;
        }
    }
    else//Si no hay ningun archivo crea uno.
    {
        ofstream students_file;
        students_file.open(studentsFilePath);
        cout << "No habia registro de alumnos, se creo uno." << endl;
    }
    students_file.close();
    total_students--;
    students.control = total_students;
    return students;
}

bool Save_disk_students(string studentsFilePath, tStudentPlusControl students)
{
    string list ="";

    int save_selection;
    cout << "Desea guardar los cambios?" << endl;
    cout << "1) Si" << endl;
    cout << "0) No" << endl;
    cin >> save_selection;
    cin.ignore();
    if (save_selection == 0){ return false;}

    for(int i = 0; i <= students.control; i ++)
    {
        list += to_string(students.list[i].nota);
        list += " ";
        list += students.list[i].name;
        if (i != students.control)
        {
            list += "\n";
        }
    }
    ofstream students_file(studentsFilePath);
    students_file << list;
    students_file.close();
    cout << "\nLista actualizada con exito!\n";
    return true;
}

void Show_students(tStudentPlusControl students)
{
    int total_students = students.control;
    for (int i = 0; i <= total_students; i++)
    {
        cout << students.list[i].name << " nota: " << students.list[i].nota << endl;
    }   
}

int Search_student(bool show_data, tStudentPlusControl students)
{
    int total_students = students.control;
    string student;
    Show_students(students);
    cout << "Seleccione un estudiante: ";
    cin.ignore();
    getline(cin, student);
    for (int i = 0; i <= total_students; i++)
    {
        if (student == students.list[i].name)
        {
            if (show_data == true)
            {
                cout << "El estudiante " << student 
                << " tiene una nota de: " << students.list[i].nota
                << " y se encuentra en la poscion " << to_string(i+1) << " de la lista." << endl;
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

tStudentPlusControl Destroy_student(tStudentPlusControl students)
{
    int total_students = students.control;
    string student;
    int pos, confirmation_destroy;
    Show_students(students);
    cout << "ELIMINAR ALUMNO DE LA LISTA" << endl;
    pos = Search_student(false, students);
    if (pos == -1)//Confirma que exista el alumno
    {
        cout << "ALUMNO NO ENCONTRADO" << endl;
        return students;
    }
    //Confirmacion de eliminacion.
    cout << "Esta seguro que desea aliminar de la lista a " << students.list[pos].name << "?" << endl;
    cout << "1) SI" << endl;
    cout << "0) NO" << endl;
    cin >> confirmation_destroy;
    if (confirmation_destroy == 0) 
    {
        return students;
    }

    for (int i = pos; i < total_students; i++)
    {
        students.list[i] = students.list[i+1];
    }
    total_students--;
    cout << "Alumno eliminado." << endl;
    return students;
}

tStudentPlusControl Add_student(tStudentPlusControl students)
{
    string student;
    students.control ++ ;
    cout << "Nombre y apellido del alumno nuevo: ";
    cin.ignore();
    getline(cin, student);
    students.list[students.control].name = student;
    cout << endl <<"El alumno " << student << " fue agregado a la clase con exito!" << endl;
    return students;
}

tStudentPlusControl Organize(string order, tStudentPlusControl students)
{ 
    int total_students = students.control;
    tStudent student_aux;

    for (int pos = 0; pos <= total_students; pos ++)
    {
        student_aux = students.list[pos];
        for (int i = pos; i <= total_students; i ++)
        {
            if ( order == "Z-A" && student_aux < students.list[i])
            {

                student_aux = students.list[pos];//AUX = DATO_VIEJO
                students.list[pos] = students.list[i]; // DATO_VIEJO -> LUGAR_NUEVO
                students.list[i] = student_aux; //LUGAR_VIEJO -> DATO_NUEVO
                student_aux = students.list[pos]; //AUX -> DATO_NUEVO
            }
            else if (order == "A-Z" && student_aux > students.list[i])
            {
                student_aux = students.list[pos];//AUX = DATO_VIEJO
                students.list[pos] = students.list[i]; // DATO_VIEJO -> LUGAR_NUEVO
                students.list[i] = student_aux; //LUGAR_NUEVO -> DATO_VIEJO
                student_aux = students.list[pos]; //AUX -> DATO_NUEVO
            }
        }
    }
    return students;
}

tStudentPlusControl Menu_Organize(tStudentPlusControl students)
{
    int selection;
    cout << "Organizar lista:" << endl;
    cout << "1) ascendente (A-Z)" << endl;
    cout << "2) descendente (Z-A)" << endl;
    cin >> selection;
    if (selection == 1) {students = Organize("A-Z", students);}
    else if (selection = 2) {students = Organize("Z-A",students);}
    else {cout << "opcion incorrecta" << endl;}
    return students;
}