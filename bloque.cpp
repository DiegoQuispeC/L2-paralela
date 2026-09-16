#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    int n = 1500;
    int BlockS = 512;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
            B[i][j] = (i + j) * 3;
            C[i][j] = 0.0;
        }
    }

    auto inicio = chrono::high_resolution_clock::now();
    for (int i1 = 0; i1 < n; i1 += BlockS) {
        for (int j1 = 0; j1 < n; j1 += BlockS) {
            for (int k1 = 0; k1 < n; k1 += BlockS) {

                for (int i = i1; i < i1 + BlockS && i < n; i++) {
                    for (int j = j1; j < j1 + BlockS && j < n; j++) {
                        for (int k = k1; k < k1 + BlockS && k < n; k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }

            }
        }
    }
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo = fin - inicio;

    cout << fixed << setprecision(6);
    cout << "\nResultado para n = " << n << ":\n";
    cout << "Tamaño del bloque: " << BlockS  << endl;
    cout << "Tiempo de multiplicacion por bloques: "
         << tiempo.count() << " seg" << endl;

    return 0;
}