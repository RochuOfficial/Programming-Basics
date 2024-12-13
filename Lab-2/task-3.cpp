// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// ---------- FUNCTIONS DECLARATION ----------
double calculateExp(double x, double eps);

// ---------- MAIN ----------
int main(){

    double eps(0.0), x(0.0);

    cout << "Podaj wartosc x: ";
    cin >> x;

    cout << "Podaj wartosc eps (dokladnosc): ";
    cin >> eps;

    const double result = calculateExp(x, eps);

    cout << "Wynik e^" << x << " to: " << result << endl;

    return 0;
}

// ---------- FUNCTIONS ----------
double calculateExp(const double x, const double eps){
    double sum(1.0), term(1.0);
    int i(1);

    while (fabs(term) > eps){
        term *= x/i;
        sum += term;
        i++;
    }

    return sum;
}
