#include "funzioniInComune.cpp"

int main()
{
    ofstream file;
    file.open("ES2RISULTATI.md");
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

    file << "# Matrice di Pascal:<br/>\n";
    printMatrix(P, file);

    file << "\n# Matrice tridiagonale:<br/>\n";
    printMatrix(T, file);

    file << "\n# Prodotto tra matrici\n";

    vector<vector<double>> xA(A.size(), vector<double>(1, 1));
    vector<vector<double>> xB(B.size(), vector<double>(1, 1));

    vector<vector<double>> bA = multiplyMatrix(A, xA);
    vector<vector<double>> bB = multiplyMatrix(B, xB);

    vector<vector<double>> xT(T.size(), vector<double>(1, 1));
    vector<vector<double>> bT = multiplyMatrix(T, xT);

    vector<vector<double>> xP(P.size(), vector<double>(1, 1));
    vector<vector<double>> bP = multiplyMatrix(P, xP);

    file << "\n## Prodotto tra A e xA:<br/>\n";
    printMatrix(bA, file);
    file << "\n## Prodotto tra B e xB:<br/>\n";
    printMatrix(bB, file);
    file << "\n## Prodotto tra T e xT:<br/>\n";
    printMatrix(bT, file);
    file << "\n## Prodotto tra P e xP:<br/>\n";
    printMatrix(bP, file);

    file << "\n# Risoluzione di sistemi lineari\n";
    vector<vector<float>> xA1 = Gauss(A, bA);
    vector<vector<float>> xB1 = Gauss(B, bB);
    vector<vector<float>> xT1 = Gauss(T, bT);
    vector<vector<float>> xP1 = Gauss(P, bP);

    file << "\n## Soluzione del sistema lineare Ax = bA:<br/>\n";
    printMatrix(toDouble(xA1), file);
    file << "\n## Soluzione del sistema lineare Bx = bB:<br/>\n";
    printMatrix(toDouble(xB1), file);
    file << "\n## Soluzione del sistema lineare Tx = bT:<br/>\n";
    printMatrix(toDouble(xT1), file);
    file << "\n## Soluzione del sistema lineare Px = bP:<br/>\n";
    printMatrix(toDouble(xP1), file);

    file.close();

    return 0;
}