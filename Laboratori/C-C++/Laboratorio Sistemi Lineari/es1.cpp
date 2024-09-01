#include <cmath>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define N 4

// a)
double normaInf(double matrix[N][N])
{
    double max = 0;
    for (int i = 0; i < N; i++)
    {
        max += abs(matrix[0][i]);
    }

    for (int i = 1; i < N; i++)
    {
        double sum = 0;
        for (int j = 0; j < N; j++)
        {
            sum = sum + abs(matrix[i][j]);
        }

        if (sum > max)
            max = sum;
    }
    return max;
}

// b)
double factorial(int n)
{
    double fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

double **pascalMatrix(int n)
{
    try
    {
        if (n < 0)
            throw 505;
        double **P = new double *[n];
        for (int i = 0; i < n; i++)
        {
            P[i] = new double[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                P[i][j] = factorial(i + j) / (factorial(i) * factorial(j));
            }
        }

        return P;
    }
    catch (const exception &e)
    {
        cerr << "L'argomento passato è minore di 0" << '\n';
    }
    return NULL;
}

void printMatrix(double **matrix, double n, ofstream& file)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            file << matrix[i][j] << " ";
        }
        file << "<br/>";
    }
}

// c)
double **triMatrix(int n)
{
    try
    {
        if (n < 0)
            throw 505;
        double **matrix = new double *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new double[n];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    matrix[i][j] = 2;
                else if (abs(i - j) == 1)
                    matrix[i][j] = -1;
                else
                    matrix[i][j] = 0;
            }
        }

        return matrix;
    }
    catch (const exception &e)
    {
        cerr << "L'argomento passato è minore di 0" << '\n';
    }
    return NULL;
}

int main()
{
    ofstream file;
    file.open("ES1RISULTATI.md");
    if(!file.is_open()){
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }

    double A[N][N] = {
        {3, 1, -1, 0},
        {0, 7, -3, 0},
        {0, -3, 9, -2},
        {0, 0, 4, -10}};

    double B[N][N] = {
        {2, 4, -2, 0},
        {1, 3, 0, 1},
        {3, -1, 1, 2},
        {0, -1, 2, 1}};

    file << "# a)\n";
    file << "La norma della matrice A e': " << normaInf(A) << "<br/>";
    file << "La norma della matrice B e': " << normaInf(B) << "<br/>";

    int n1 = 10;
    double **P = pascalMatrix(n1);
    file << "\n# b)\n";
    file << "Matrice di Pascal:<br/>";
    printMatrix(P, n1, file);

    // Matricola usata: 5462843
    int matricola[7] = {5, 4, 6, 2, 8, 4, 3};
    int n2 = 10 * (matricola[1] + 1) + matricola[0];
    double **T = triMatrix(n2);
    file << "\n# c)\n";
    file << "Matrice tridiagonale:<br/>";
    printMatrix(T, n2, file);
    file.close();
    return 0;
}