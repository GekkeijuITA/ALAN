#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

double factorial(int n);
double normaInf(vector<vector<double>> matrix);
vector<vector<double>> pascalMatrix(int n);
void printMatrix(vector<vector<double>> matrix, ofstream &file);
vector<vector<double>> triMatrix(int n);
vector<vector<double>> multiplyMatrix(const vector<vector<double>> &matriceA, const vector<vector<double>> &matriceB);
vector<vector<float>> toFloat(const vector<vector<double>> &matrix);
vector<vector<double>> toDouble(const vector<vector<float>> &matrix);
vector<vector<float>> Gauss(const vector<vector<double>>& A, const vector<vector<double>>& b);