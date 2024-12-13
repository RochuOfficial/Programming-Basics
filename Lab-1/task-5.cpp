// ------------------- IMPORT LIBRARIES -------------------
#include <iostream>
#include <cmath>
#include <utility>

// ------------------- DEFINE CONSTANT RETURN VALUES -------------------
#define SUCCESS 0
#define FAILURE 1

using namespace std;

// ------------------- FUNCTION DECLARATION -------------------
std::pair<double, double> quadratic(double a, double b, double c);
double linear(double a, double b);

// ------------------- MAIN -------------------
int main() {

    double a(0), b(0), c(0);

    cout << "Podaj wspolczynnik \"a\": ";
    cin >> a;
    cout << "Podaj wspolczynnik \"b\": ";
    cin >> b;
    cout << "Podaj wspolczynnik \"c\": ";
    cin >> c;

    if (a != 0) {
        // Quadratic Function
        std::pair<double, double> doubleResult(0, 0);
        doubleResult = quadratic(a, b, c);
        if(doubleResult.first == NULL && doubleResult.second == NULL) {
            cout << endl << "Funkcja nie ma rozwiazan w zbiorze liczb Rzeczywistych!" << endl;
            return SUCCESS;
        }

        else if (doubleResult.first != NULL && doubleResult.second == NULL) {
            cout << endl <<"Funckja ma 1 rozwiazanie rowne: " << doubleResult.first << endl;
            return SUCCESS;
        }

        else {
            cout << endl << "x1 = " << doubleResult.first << endl;
            cout << "x2 = " << doubleResult.second << endl;
            return SUCCESS;
        }
    }
    else if (a == 0 && b == 0) {
        // Constant Function
        if (c != 0) cout << endl << "Funkcja ma zero rozwiazan!" << endl;
        else cout << endl << "Funckja ma nieskonczenie wiele rozwiazan!" << endl;
        return SUCCESS;
    }

    else {
        // Linear Function
        double singleResult(0);
        singleResult = linear(b, c);
        cout << endl << "x1 = " << singleResult << endl;
        return SUCCESS;
    }
}

// ------------------- FUNCTIONS -------------------
std::pair<double, double> quadratic(double a, double b, double c) {
    double delta = pow(b, 2) - (4 * a * c);
    double x1(0), x2(0);

    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        return std::make_pair(x1, x2);
    }

    else if (delta == 0) {
        x1 = (-b) / (2 * a);
        x2 = NULL;
        return std::make_pair(x1, x2);
    }

    else {
        x1 = NULL;
        x2 = NULL;
        return std::make_pair(x1, x2);
    }
}

double linear(double a, double b) {
    return -b / a;
}
