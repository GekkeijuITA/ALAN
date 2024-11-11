#include <iostream>
#include <cmath>
#include <fstream>
#include <filesystem>

using namespace std;

#define FILE_NAME "ES3RISULTATI.md"

double epsDouble()
{
    double res = 0, prevRes;
    for (int d = 0;; d++)
    {
        prevRes = res;
        res = 1 + pow(2, -d);
        if (res <= 1)
            return d;
    }
}

float epsFloat()
{
    float res = 0, prevRes;
    for (int d = 0;; d++)
    {
        prevRes = res;
        res = 1 + pow(2, -d);
        if (res <= 1)
            return d;
    }
}

int main()
{
    float epsF = epsFloat();
    double epsD = epsDouble();

    ofstream file(FILE_NAME);
    if (!file)
    {
        cerr << "Errore nell'apertura del file, prova a guardare se il file " << FILE_NAME << " è stato creato altrimenti crealo nella stessa cartella dell'eseguibile" << endl;
        return 1;
    }

    file << "# Più grande d numero intero positivo tale che 1+2^-d > 1 è:\n";
    file << "## Doppia precisione: " << epsD << "\n";
    file << "## Singola precisione: " << epsF << "\n";
    file.close();
    cout << "Risultati scritti nel percorso: " << filesystem::absolute(FILE_NAME) << endl;
    return 0;
}