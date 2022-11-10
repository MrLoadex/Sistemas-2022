#ifndef Animal_h
    #define Animal_h
#include <string>
using namespace std;
//SuperClase
class Animal
{
private:
    string name;
    int code;
public:
    Animal();
    ~Animal();
    virtual void SetName(string pNombre = "animal");
    virtual void SetCode(int pCode);
    virtual int GetCode();
    virtual string GetName();
};
#endif