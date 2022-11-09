#ifndef Zoo_h
    #define Zoo_h

#include "../Animal/Animal.h"
#include <string>
using namespace std;
class Zoo
{
private:
    Animal* animalList[5];//Lista contenedora
public:
    Zoo();
    ~Zoo();
    void AddAnimal(Animal* animal, int i); //Necesita el animal y la ubicacion en la lista
    Animal* GetAnimal(int i);//Devuelve un puntero a un tipo animal
};
#endif