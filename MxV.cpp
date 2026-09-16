#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

using namespace std;

int main() {

    int n=20000;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> x(n);
    vector<double> y(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1.0;
        }
    }

    for (int i = 0; i < n; i++) {
        x[i] = 1.0;
        y[i] = 0.0;
    }

    auto inicio1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto fin1 = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo1 = fin1 - inicio1;



    for (int i = 0; i < n; i++) {
        y[i] = 0.0;
    }

    auto inicio2 = chrono::high_resolution_clock::now();
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto fin2 = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo2 = fin2 - inicio2;


    cout << fixed << setprecision(6);
    cout << "\nResultados para n = "<< n <<" :\n";
    cout << "Tiempo primer metodo:  "
         << tiempo1.count() << " seg" << endl;
    cout << "Tiempo segundo metodo: "
         << tiempo2.count() << " seg" << endl;
    return 0;
}
