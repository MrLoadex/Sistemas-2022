#include "structDin.h"
#ifndef iostream
    #include <iostream>
    #include <fstream>
    #include <string>
#endif
using namespace std;

struct tStudent
{
    string name;
    int nota[3];
    float avarage;
};

int Nstudents = 10;
tStudent *student_list = new tStudent[Nstudents];
int total_students = 0;

void Load_disk_students()
{
    ifstream students_file;
    students_file.open("./structDin/students.txt");
    
    if (students_file.is_open())
    {
        while (!students_file.eof())
        {
            students_file >> student_list[total_students].nota[0];
            students_file >> student_list[total_students].nota[1];
            students_file >> student_list[total_students].nota[2];
            getline(students_file,student_list[total_students].name);

            //caucula el promedio
            student_list[total_students].avarage = (student_list[total_students].nota[0] + student_list[total_students].nota[1]+ student_list[total_students].nota[2])/ 3;
            total_students ++;
        }
        total_students--;
    }
    else//Si no hay ningun archivo crea uno.
    {
        ofstream students_file;
        students_file.open("students.txt");
        cout << "No habia registro de alumnos, se creo uno." << endl;
    }
    students_file.close();
}

void ShowBestAvarage()
{
    //creo un array temporal para guardar las 3 mejores notas
    tStudent bestStudent[3];
    //se inicializan en 0 para evitar datos random.
    bestStudent[0].avarage = 0;
    bestStudent[1].avarage = 0;
    bestStudent[2].avarage = 0;
    int cont;
    for (int i = 0; i < total_students; i++)
    {
        if (student_list[i].avarage > bestStudent[2].avarage)
        {
            if (student_list[i].avarage > bestStudent[1].avarage)
            {
                if (student_list[i].avarage > bestStudent[0].avarage)
                {
                    bestStudent[1] = bestStudent[0];
                    bestStudent[2] = bestStudent[1];
                    bestStudent[0] = student_list[i];
                }
                else
                {
                    bestStudent[2] = bestStudent[1];
                    bestStudent[1] = student_list[i];
                }
            }
            else bestStudent[2] = bestStudent[i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "Los 3 mejores promedios son: " << endl;
        cout << i+1 << ": " << bestStudent[i].name << "con un promedio de " << bestStudent[i].avarage << endl;
    }
      
}

void DeletedDinamicStudentList()
{
    delete student_list;
    cout << "lista dinamica eliminada" << endl;
}