#include "funzioniInComune.h"
double factorial(int n)
{
    double fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

double normaInf(vector<vector<double>> matrix)
{
    double max = 0;
    for (int i = 0; i < matrix.size() ; i++)
    {
        max += abs(matrix[0][i]);
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        double sum = 0;
        for (int j = 0; j < matrix[i].size(); j++)
        {
            sum = sum + abs(matrix[i][j]);
        }

        if (sum > max)
            max = sum;
    }
    return max;
}

vector<vector<double>> pascalMatrix(int n)
{
    try
    {
        if (n < 0)
            throw 505;
        vector<vector<double>> P = vector<vector<double>>(n, vector<double>(n, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                P[i-1][j-1] = factorial(i + j - 2) / (factorial(i - 1) * factorial(j - 1));
            }
        }

        return P;
    }
    catch (const exception &e)
    {
        cerr << "L'argomento passato è minore di 0" << '\n';
    }
    return vector<vector<double>>();
}

void printMatrix(vector<vector<double>> matrix, ofstream &file)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            file << matrix[i][j] << ", ";
        }
        file << "<br/>";
    }
}

vector<vector<double>> triMatrix(int n)
{
    try
    {
        if (n < 0)
            throw 505;
        vector<vector<double>> matrix = vector<vector<double>>(n, vector<double>(n, 0));

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
    return vector<vector<double>>();
}

vector<vector<double>> multiplyMatrix(const vector<vector<double>> &matriceA, const vector<vector<double>> &matriceB)
{
    int righeA = matriceA.size();
    int colonneA = matriceA[0].size();
    int colonneB = matriceB[0].size();

    vector<vector<double>> risultato(righeA, vector<double>(colonneB, 0));

    for (int i = 0; i < righeA; i++)
    {
        for (int j = 0; j < colonneB; j++)
        {
            for (int k = 0; k < colonneA; k++)
            {
                risultato[i][j] += matriceA[i][k] * matriceB[k][j];
            }
        }
    }

    return risultato;
}

vector<vector<float>> toFloat(const vector<vector<double>> &matrix)
{
    vector<vector<float>> result(matrix.size(), vector<float>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[i][j] = matrix[i][j];
        }
    }
    return result;
}

vector<vector<double>> toDouble(const vector<vector<float>> &matrix)
{
    vector<vector<double>> result(matrix.size(), vector<double>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[i][j] = matrix[i][j];
        }
    }
    return result;
}

vector<vector<float>> Gauss(const vector<vector<double>>& A, const vector<vector<double>>& b){

    vector<vector<float>> Ab = toFloat(A);
    for(int i = 0; i < b.size(); i++){
        Ab[i].push_back(b[i][0]);
    }

    int n = Ab.size();
    for(int i = 0; i < n; i++){
        float maxEl = abs(Ab[i][i]);
        int maxRow = i;
        for(int k = i + 1; k < n; k++){
            if(abs(Ab[k][i]) > maxEl){
                maxEl = abs(Ab[k][i]);
                maxRow = k;
            }
        }

        for(int k = i; k < n + 1; k++){
            float tmp = Ab[maxRow][k];
            Ab[maxRow][k] = Ab[i][k];
            Ab[i][k] = tmp;
        }

        for(int k = i + 1; k < n; k++){
            float c = -Ab[k][i] / Ab[i][i];
            for(int j = i; j < n + 1; j++){
                if(i == j){
                    Ab[k][j] = 0;
                }else{
                    Ab[k][j] += c * Ab[i][j];
                }
            }
        }
    }

    vector<vector<float>> x(n, vector<float>(1, 0));
    for(int i = n - 1; i >= 0; i--){
        x[i][0] = Ab[i][n] / Ab[i][i];
        for(int k = i - 1; k >= 0; k--){
            Ab[k][n] -= Ab[k][i] * x[i][0];
        }
    }

    return x;
}

vector<vector<double>> A = {
    {3, 1, -1, 0},
    {0, 7, -3, 0},
    {0, -3, 9, -2},
    {0, 0, 4, -10}};

vector<vector<double>> B = {
    {2, 4, -2, 0},
    {1, 3, 0, 1},
    {3, -1, 1, 2},
    {0, -1, 2, 1}};

int matricola[7] = {5, 4, 6, 2, 8, 4, 3};