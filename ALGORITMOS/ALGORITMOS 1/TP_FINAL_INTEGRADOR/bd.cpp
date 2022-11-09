#include <iostream>
//Intente usar <archivo.h> pero tira error al compilar, aunque le pase la direccion.
#include "./Animal/Animal.h"
#include "./Animal/Oviparous/Oviparous.h"
#include "./Animal/Oviparous/Pelican/Pelican.h"
#include "./Animal/Oviparous/Goose/Goose.h"
#include "./Animal/Oviparous/Cocodrile/Cocodrile.h"
#include "Animal/Mammal/Mammal.h"
#include "./Animal/Mammal/Bat/Bat.h"
#include "./Animal/Mammal/SeaLion/SeaLion.h"
#include "./Animal/Mammal/Whale/Whale.h"
#include "./Zoo/Zoo.h"
using namespace std;


Animal* SelectAnimal(Zoo* pZoo);//Devuelve un puntero a animal
int SelectAnimalMenu(); //Menu que utiliza la clase SelectAnimal, queda mas entendible asi
void LoopZooAnimals(Zoo* pZoo);

int main()
{
    Zoo* zooPark = new Zoo;

    LoopZooAnimals(zooPark);

    delete[] zooPark;
    system("pause");
    return 0;
}

Animal* SelectAnimal(Zoo* pZoo)
{     
    int pOption = SelectAnimalMenu();
    switch (pOption)
    {
    case 1:
        return new Goose;
        break;
    case 2:
        return new Pelican;
        break;
    case 3:
        return new Cocodrile;
        break;
    case 4:
        return new Bat;
        break;
    case 5:
        return new Whale;
        break;
    case 6:
        return new SeaLion;
        break;
    default:
    cout << "Opcion invalida" << endl;
        break;
    }
    return 0;
}

int SelectAnimalMenu()
{
    int option;//se usa en el switch para elegir el animal.
    cout << "Que animal desea inertar?" << endl;
    cout << "1. Ganso" << endl;
    cout << "2. Pelicano" << endl;
    cout << "3. Cocodrilo" << endl;
    cout << "4. Murcielago" << endl;
    cout << "5. Ballena" << endl;
    cout << "6. Leon Marino" << endl;
    cin >> option;
    return option;
}

void LoopZooAnimals(Zoo* pZoo)
{
    Animal* animal;
    string name;
    for(int i = 0; i < 5; i++)
    {
        animal = SelectAnimal(pZoo);
        cout << "Seleccione el nombre del animal:";
        cin >> name;
        animal->SetName(name);
        pZoo->AddAnimal(animal, i);
    }

    for(int i = 0; i < 5; i++)
    {
        animal = pZoo->GetAnimal(i);
        cout << "El animal " << i+1 << " es el/la: ";
        cout << animal->GetName() << endl;
    }
}