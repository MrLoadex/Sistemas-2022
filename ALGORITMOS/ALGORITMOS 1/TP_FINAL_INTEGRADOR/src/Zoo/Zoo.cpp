#include <Zoo.h>
Zoo::Zoo(){}
Zoo::~Zoo() {}
void Zoo::AddAnimal(Animal* pAnimalPtr, int i){animalList[i] = pAnimalPtr;}
Animal* Zoo::GetAnimal(int i){return animalList[i];}