// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
double calculateSeries(double x, int n);
double factorial (int n);

// ---------- MAIN ----------
int main(){

    int n(0);
    double x(0.0);

    cout << "Podaj wartosc x: ";
    cin >> x;

    do {
        cout << "Podaj wartosc N: ";
        cin >> n;

        if (n < 1) cout << "Wartosc N musi byc wieksza od 0!" << endl;
    } while (n < 1);

    const double result = calculateSeries(x, n);

    cout << "Wynik szeregu to: " << result << endl;

    return 0;
}

// ---------- FUNCTIONS ----------
double calculateSeries(const double x, const int n){
    double series(0.0);

    for (int i = 1; i <= n; i++){
        series += (pow(x, i) / factorial(i));
    }

    return series;
}

double factorial (const int n){
    double result(1.0);

    for (int i = 1; i <= n; i++){
        result *= i;
    }

    return result;
}
