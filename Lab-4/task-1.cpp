// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <iomanip>

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
void menu();
long long unsigned int factorialI(int);
long long unsigned int factorialR(long long unsigned int);
long long unsigned int newtonSymbolR(int, int);
long long unsigned int newtonSymbolI(int, int);
void displayPascalTriangleR(int);
void displayPascalTriangleI(int);

// ---------- MAIN ----------
int main(){

    int choice, rows;
    long long unsigned int number1, number2, result;

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Podaj liczbe: ";
                cin >> number1;
                result = factorialI(number1);
                cout << "Silnia itercyjnie: " << result << endl;
                result = factorialR(number1);
                cout << "Silnia rekurencyjnie: " << result << endl;
                break;

            case 2:
                cout << "Podaj liczbe \"n\": ";
                cin >> number1;
                cout << "Podaj liczbe \"k\": ";
                cin >> number2;
                result = newtonSymbolR(number1, number2);
                cout << "Wartosc symbolu Newtona to: " << result << endl;
                break;

            case 3:
                do{
                    cout << "Podaj liczbe rzedow: ";
                    cin >> rows;
                    if (rows > 20) cout << endl << "Dla bezpieczenstwa programu," << endl
                        << "liczba rzedow musi byc mniejsza od 20!" << endl;
                } while (rows > 20);
                displayPascalTriangleR(rows);
                displayPascalTriangleI(rows);
                break;

            case 0:
                cout << "Zamykanie programu" << endl;
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
    cout << "----------------------------------" << endl;
    cout << "-       Co chcesz zrobic ?       -" << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Oblicz silnie" << endl;
    cout << "2. Oblicz wartosc symbolu Newtowna" << endl;
    cout << "3. Wyswietl trojkat Pascala" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

long long unsigned int factorialI(const int number){
    long long int sum = 1;

    for (int i = 1;  i <= number; i++){
        sum *= i;
    }

    return sum;
}

long long unsigned int factorialR(const long long unsigned int number){
    if (number == 0)
        return 1;
    else
        return number * factorialR(number - 1);
}

long long unsigned int newtonSymbolR(const int n, const int k){
    return factorialR(n) / (factorialR(k) * factorialR(n-k));
}

long long unsigned int newtonSymbolI(const int n, const int k){
    return factorialI(n) / (factorialI(k) * factorialI(n-k));
}

void displayPascalTriangleI(const int rows){
    cout << endl << "Funckja iteracyjna:" << endl;
    for (int row = 0; row < rows; row++){
        cout << setw(2) << row + 1 << ". ";

        cout << setw((rows - row) * 3) << "";

        for (int symbol = 0; symbol <= row; symbol++){
            cout << setw(6) << newtonSymbolI(row, symbol);
        }

        cout << endl;
    }
}

void displayPascalTriangleR(const int rows){
    cout << endl <<  "Funkcja rekurencyjna:" << endl;
    for (int row = 0; row < rows; row++){
        cout << setw(2) << row + 1 << ". ";

        cout << setw((rows - row) * 3) << "";

        for (int symbol = 0; symbol <= row; symbol++){
            cout << setw(6) << newtonSymbolR(row, symbol);
        }

        cout << endl;
    }
}
