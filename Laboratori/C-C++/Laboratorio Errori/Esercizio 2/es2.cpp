#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double factorial(int n)
{
    double fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

// Polinomio di Taylor
double Taylor(int N, double x)
{
    double res = 0;
    for (int n = 0; n <= N; n++)
    {
        res += (pow(x, n)) / (factorial(n));
    }
    return res;
}

int main()
{
    int N[] = {3, 10, 50, 100, 150};
    float x[] = {0.5, 30, -0.5, -30};

    ofstream file("ES2RISULTATI.md");
    if (!file)
    {
        cerr << "Errore nell'apertura del file, prova a guardare se il file ES2RISULTATI.md è stato creato altrimenti crealo nella stessa cartella dell'eseguibile" << endl;
        return 1;
    }

    // Algoritmo 1
    if (file.is_open())
    {
        file << "# Algoritmo 1:\n";

        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                double taylor = Taylor(N[i], x[j]);
                file << "## x: " << to_string(x[j]);
                file << ", N: " << to_string(N[i]) << "\n";
                file << "### Risultati\n";
                file << "Taylor: " << taylor << "\n";
                file << "Exp: " << exp(x[j]) << "\n";
            }
        }

        file << "\n # Algoritmo 2:\n";

        // Algoritmo 2
        for (int j = 0; j < 2; j++)
        {
            for (int i = 0; i < 5; i++)
            {
                file << "## x: " << to_string(-x[j]);
                file << ", N: " << to_string(N[i]) << endl;
                file << "### Risultati\n";
                file << "Taylor: " << 1 / Taylor(N[i], x[j]) << "\n";
                file << "Exp: " << exp(x[j]) << "\n";
            }
        }
    }
    file.close();
    cout << "File scritto correttamente" << endl;
    return 0;
}