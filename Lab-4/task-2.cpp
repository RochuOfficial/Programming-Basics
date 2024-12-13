// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <iostream>

using namespace std;

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

// ---------- DEFINE FUNCTIONS ----------
void menu();
void valueArgument(int, int);
void referenceArgument(int&, int);

// ---------- MAIN ----------
int main(){

    int a, b, choice;

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Podaj liczbe \"a\": ";
                cin >> a;
                cout << "Podaj liczbe \"b\": ";
                cin >> b;

                cout << endl << "Liczby przed wyzerowaniem (main):" << endl << "a: " << a << endl << "b: " << b << endl;
                valueArgument(a, b);
                cout << endl << "Liczby po wyzerowaniu w funkcji wartosci (main):" << endl;
                cout << "a: " << a << endl << "b: " << b << endl;

                cout << endl << "--------------------------------------------------------------------" << endl << endl;

                cout << endl << "Liczby przed wyzerowaniem (main):" << endl << "a: " << a << endl << "b: " << b << endl;
                referenceArgument(a, b);
                cout << endl << "Liczby po wyzerowaniu w funkcji referencji (main):" << endl;
                cout << "a: " << a << endl << "b: " << b << endl;
                break;

            case 0:
                cout << "Zakmykanie programu!" << endl;
                return SUCCESS;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl;
    }
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "------------------------------------" << endl;
    cout << "-        Co chcesz zrobic ?        -" << endl;
    cout << "------------------------------------" << endl;
    cout << "1. Przetestowac zerowanie zmiennych" << endl;
    cout << "0. Zakonczyc program" << endl;
    cout << "Wybierz: ";
}

void valueArgument(int a, int b){
    cout << endl <<"Wartosci liczb w funkcji wartosci przed wyzerowaniem:" << endl;
    cout << "a: " << a << endl << "b: " << b << endl;

    a = 0;
    b = 0;

    cout << endl << "Wartosci liczb w funkcji wartosci po wyzerowaniu:" << endl;
    cout << "a: " << a << endl << "b: " << b << endl;
}

void referenceArgument(int &a, int b){
    cout << endl <<"Wartosci liczb w funkcji referencji przed wyzerowaniem:" << endl;
    cout << "a: " << a << endl << "b: " << b << endl;

    a = 0;
    b = 0;

    cout << endl << "Wartosci liczb w funkcji referencji po wyzerowaniu:" << endl;
    cout << "a: " << a << endl << "b: " << b << endl;
}
