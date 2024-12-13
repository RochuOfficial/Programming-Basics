// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 1
#define FAILURE 0

// ---------- DEFINE FUNCTIONS ----------
void menu();
void calculateFactors(int n);
bool isPrime (int n);

// ---------- MAIN ----------
int main(){

    int choice(1), number(0);

    while(choice != 0){
        menu();
        cin >> choice;

        cout << endl;

        switch (choice){
            case 1:
                cout << "Podaj liczbe calkowita: ";
            cin >> number;

            cout << "Dzielniki liczby " << number << " to:" << endl;
            calculateFactors(number);

            if (isPrime(number)) cout << "Liczba " << number << " jest liczba pierwsza" << endl;
            else cout << "Liczba " << number << " nie jest liczba pierwsza" << endl;
            break;

            case 0:
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
    cout << endl;
    cout << "Co chcesz zrobic?" << endl;
    cout << "----------------------------" << endl;
    cout << "1. Obliczyc dzielniki liczby" << endl;
    cout << "0. Zakonczyc program" << endl;
    cout << "Wybierz: ";
}

void calculateFactors(const int n){
    for (int i = 1; i <= n; i++){
        if (n % i == 0) cout << i << endl;
    }
}

bool isPrime (const int n){
    if (n <= 1) return false;

    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }

    return true;
}
