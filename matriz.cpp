#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    int n = 1750;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }

    auto inicio = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo = fin - inicio;

    cout << fixed << setprecision(6);
    cout << "\nResultado para n = " << n << ":\n";
    cout << "Tiempo de multiplicacion: "
         << tiempo.count() << " seg" << endl;

    return 0;
}