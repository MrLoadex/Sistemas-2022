#include <Animal.h>

Animal::Animal() {}
Animal::~Animal() {}
void Animal::SetCode(int pCode) { code = pCode; }
void Animal::SetName(string pNombre) { name = pNombre; }
string Animal::GetName() { return name; }
int Animal::GetCode() { return code; }