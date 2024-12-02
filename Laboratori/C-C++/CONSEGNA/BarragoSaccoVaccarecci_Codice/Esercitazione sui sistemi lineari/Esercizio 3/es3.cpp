#include "../funzioniInComune.cpp"

vector<vector<double>> noise(int n)
{
    vector<vector<double>> v(n, vector<double>(1, 0));
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            v[i][0] = -0.01;
        else
            v[i][0] = 0.01;
    }
    return v;
}

vector<vector<double>> add(const vector<vector<double>> &A, const vector<vector<double>> &B)
{
    vector<vector<double>> C(A.size(), vector<double>(A[0].size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

int main()
{

    ofstream file;
    file.open("ES3RISULTATI.md");
    if (!file.is_open())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }

    int n = 10;
    vector<vector<double>> P = pascalMatrix(n);

    // Matricola usata: 5462843
    int n2 = 10 * (matricola[1] + 1) + matricola[0];
    vector<vector<double>> T = triMatrix(n2);

    //file << "# Matrice di Pascal:<br/>\n";
    //printMatrix(P, file);
//
    //file << "\n# Matrice tridiagonale:<br/>\n";
    //printMatrix(T, file);

    vector<vector<double>> xA(A.size(), vector<double>(1, 1));
    vector<vector<double>> xB(B.size(), vector<double>(1, 1));
    vector<vector<double>> xT(T.size(), vector<double>(1, 1));
    vector<vector<double>> xP(P.size(), vector<double>(1, 1));

    vector<vector<double>> dA = noise(A.size());
    vector<vector<double>> dB = noise(B.size());
    vector<vector<double>> dT = noise(T.size());
    vector<vector<double>> dP = noise(P.size());

    vector<vector<double>> bA = multiplyMatrix(A, xA);
    vector<vector<double>> bB = multiplyMatrix(B, xB);
    vector<vector<double>> bT = multiplyMatrix(T, xT);
    vector<vector<double>> bP = multiplyMatrix(P, xP);

    vector<vector<double>> temp = {{normaInf(bA)}};
    vector<vector<double>> dbA = multiplyMatrix(dA, temp);
    temp = {{normaInf(bB)}};
    vector<vector<double>> dbB = multiplyMatrix(dB, temp);
    temp = {{normaInf(bT)}};
    vector<vector<double>> dbT = multiplyMatrix(dT, temp);
    temp = {{normaInf(bP)}};
    vector<vector<double>> dbP = multiplyMatrix(dP, temp);

    file << "\n# Risoluzione di sistemi lineari\n";
    vector<vector<float>> xA1 = Gauss(A, add(bA, dbA));
    vector<vector<float>> xB1 = Gauss(B, add(bB, dbB));
    vector<vector<float>> xT1 = Gauss(T, add(bT, dbT));
    vector<vector<float>> xP1 = Gauss(P, add(bP, dbP));

    file << "\n## Soluzione del sistema lineare Ax = b + d:<br/>\n";
    printMatrix(toDouble(xA1), file);
    file << "\n## Soluzione del sistema lineare Bx = b + d:<br/>\n";
    printMatrix(toDouble(xB1), file);
    file << "\n## Soluzione del sistema lineare Tx = b + d:<br/>\n";
    printMatrix(toDouble(xT1), file);
    file << "\n## Soluzione del sistema lineare Px = b + d:<br/>\n";
    printMatrix(toDouble(xP1), file);

    file.close();

    return 0;
}