#include <iostream>
#include <cmath>

using namespace std;

#define MATR_LEN 7

int main()
{
    double matricola[MATR_LEN] = {5,7,0,3,1,1,7};
    cout << "Matricola usata: ";
    for(int i = 0 ; i < MATR_LEN ; i++)
    {
        cout << matricola[i];
    }
    cout << endl;

    double a;
    for(int i = 0 ; i < MATR_LEN ; i++)
    {
        a += (matricola[0] + 1) * pow(10,i);
    }
    double b = (matricola[1] + 1) * pow(10,20);
    double c = -b;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    double res1 = (a+b)+c;
    double res2 = a+(b+c);

    cout << endl;

    cout << "(a+b)+c = " << res1 << endl;
    cout << "a+(b+c) = " << res2 << endl;

    return 0;
}