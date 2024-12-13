// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

// ---------- DEFINE FUNCTIONS ----------
void menu();
double calculateRectangle();
double calculateTriangle();
double calculateCircle();

// ---------- MAIN ----------
int main(){

    char choice;
    double result(0.0);

    while (choice != 'q' || choice != 'Q'){
        menu();
        cin >> choice;

        switch (choice){
            case 'p':
            case 'P':
                result = calculateRectangle();
                cout << "Pola prostokata to: " << result << endl;
                break;

            case 't':
            case 'T':
                result = calculateTriangle();
                cout << "Pole trojkata to: " << result << endl;
                break;

            case 'k':
            case 'K':
                result = calculateCircle();
                cout << "Pole kola to: " << result << endl;
                break;

            case 'q':
            case 'Q':
                cout << "Zamykanie programu" << endl;
                return SUCCESS;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
    }
    return FAILURE;
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << endl <<"Pole jakiej figure chcesz obliczyc?" << endl;
    cout << "-----------------------------------" << endl;
    cout << "\"P\". Prostokat" << endl;
    cout << "\"T\". Trojkat" << endl;
    cout << "\"K\". Kolo" << endl;
    cout << "\"Q\". Koniec" << endl;
    cout << "Podaj litere: ";
}

double calculateRectangle(){
    double a(0.0), b(0.0);

    cout << "Podaj 1. bok: ";
    cin >> a;
    cout << "Podaj 2. bok: ";
    cin >> b;

    return a*b;
}

double calculateTriangle(){
    double a(0.0), h(0.0);

    cout << "Podaj dlugosc podstawy: ";
    cin >> a;
    cout << "Podaj wysokosc: ";
    cin >> h;

    return 0.5*a*h;
}

double calculateCircle(){
    double radius(0.0);

    cout << "Podaj promien: ";
    cin >> radius;

    return M_PI*pow(radius, 2);
}
