#include "funzioniInComune.cpp"

int main()
{
    ofstream file;
    file.open("ES1RISULTATI.md");
    if(!file.is_open()){
        cerr << "Errore nell'apertura del file" << endl;
        return 1;
    }

    file << "# a)\n";
    file << "La norma della matrice A e': " << normaInf(A) << "<br/>";
    file << "La norma della matrice B e': " << normaInf(B) << "<br/>";

    int n = 10;
    vector<vector<double>> P = pascalMatrix(n);
    file << "\n# b)\n";
    file << "Matrice di Pascal:<br/>";
    printMatrix(P, file);

    // Matricola usata: 5462843
    int n2 = 10 * (matricola[1] + 1) + matricola[0];
    vector<vector<double>> T = triMatrix(n2);
    file << "\n# c)\n";
    file << "Matrice tridiagonale:<br/>";
    printMatrix(T, file);
    file.close();
    return 0;
}