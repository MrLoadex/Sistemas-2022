#include <string>


//Estructura de cada estudiante
typedef struct 
{
    int nota;
    std::string name;
} tStudent;

//maximo de estudiantes.
const short int N = 100;

//Lista de estudiantes.
typedef tStudent tStudentList[N];


//Estructura de control
struct tStudentPlusControl
{
    tStudentList list;
    int control;
};

bool operator>(tStudent opIzq, tStudent opDer);
bool operator<(tStudent opIzq, tStudent opDer);

//Carga el archivo de estudiantes, se le debe pasar el nombre del archivo
//Devuelve un listado de alumnos
tStudentPlusControl Load_disk_students(std::string studentsFilePath);

//Guarda la lista actual de estudiantes en el disco
bool Save_disk_students(std::string studentsFilePath, tStudentPlusControl students);

//Muestra la totalidad de los estudiantes en la lista
void Show_students(tStudentPlusControl students);

//devuelve un int con la posicion del alumno
//si es -1 significa que no existe
int Search_student(bool show_data,tStudentPlusControl students);

//Busca y elimina un estudiante de la lista
tStudentPlusControl Destroy_student(tStudentPlusControl students);

//Agrega un estudiante al final de la lista
tStudentPlusControl Add_student(tStudentPlusControl students);

//Organiza a los estudiantes de A-Z o Z-A.
//Se le debe pasar el argumento A-Z o Z-A.
tStudentPlusControl Organize(std::string order, tStudentPlusControl students);

//Un submenu para consultar si se debe ordenar de A-Z o de Z-A
tStudentPlusControl Menu_Organize(tStudentPlusControl students);