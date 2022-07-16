#include <iostream>
using namespace std;

int main()
{
    double x,y;
    int aux=0;
    while (aux <5){
       cout << "x"<< aux <<": ";
        cin >> x;
        y = 2 * x + 1;
        cout << "A 'X' "<< x << " le corresponde 'Y' "<< y << "." << endl;
        aux+=1;
    }

    return 0;
}