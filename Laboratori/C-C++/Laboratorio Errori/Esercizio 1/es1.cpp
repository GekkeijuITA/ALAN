#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define MATR_LEN 7

int main()
{
    ofstream file("ES1RISULTATI.md");
    if (!file)
    {
        cerr << "Errore nell'apertura del file, prova a guardare se il file ES1RISULTATI.md è stato creato altrimenti crealo nella stessa cartella dell'eseguibile" << endl;
        return 1;
    }

    double matricola[MATR_LEN] = {5,7,0,3,1,1,7};
    file << "Matricola usata: ";
    for(int i = 0 ; i < MATR_LEN ; i++)
    {
        file << matricola[i];
    }

    double a;
    for(int i = 0 ; i < MATR_LEN ; i++)
    {
        a += (matricola[0] + 1) * pow(10,i);
    }
    double b = (matricola[1] + 1) * pow(10,20);
    double c = -b;

    file << "\na: " << a << "\n";
    file << "b: " << b << "\n";
    file << "c: " << c << "\n";

    double res1 = (a+b)+c;
    double res2 = a+(b+c);

    file << "(a+b)+c = " << res1 << "\n";
    file << "a+(b+c) = " << res2 << "\n";

    return 0;
}