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
bool checkPythagoras(int a, int b, int c);
void menu();

// ---------- MAIN ----------
int main(){

    int a(0), b(0), c(0), choice(0);

    while(true){
        menu();
        cin >> choice;

        switch (choice){
            case 1:
                cout << "Podaj \"a\": ";
                cin >> a;
                cout << "Podaj \"b\": ";
                cin >> b;
                cout << "Podaj \"c\": ";
                cin >> c;

                if (checkPythagoras(a, b, c)) cout << "Liczby sa liczbami pitagorejskimni!" << endl;
                else cout << "Liczby nie sa liczbami pitagorejskimi!" << endl;
                break;

            case 0:
                cout << "Zamykanie programu" << endl;
                return SUCCESS;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;

        }
    }
}

// ---------- FUNCTIONS ----------
bool checkPythagoras(const int a, const int b, const int c){
    if (pow(c, 2) == pow(a, 2) + pow(b, 2) ||
        pow(a, 2) == pow(c, 2) + pow(b, 2) ||
        pow(b, 2) == pow(a, 2) + pow(c, 2)) return true;
    else return false;
}

void menu(){
    cout << endl << "Co chcesz zrobic?" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1. Sprawdz czy liczby sa liczbami pitagoreskimi" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}
