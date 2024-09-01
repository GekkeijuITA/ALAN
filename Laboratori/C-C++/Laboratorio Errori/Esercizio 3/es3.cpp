#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

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

    ofstream file("ES3RISULTATI.md");
    if (!file)
    {
        cerr << "Errore nell'apertura del file, prova a guardare se il file ES3RISULTATI.md è stato creato altrimenti crealo nella stessa cartella dell'eseguibile" << endl;
        return 1;
    }

    file << "# Più grande d numero intero positivo tale che 1+2^-d > 1 è:\n";
    file << "## Doppia precisione: " << epsD << "\n";
    file << "## Singola precisione: " << epsF << "\n";
    file.close();
    return 0;
}