// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <algorithm>

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
void menu();
string convertDecimal(int, int);
string convertToBase7(int);

// ---------- MAIN ----------
int main(){

    int choice, number, base;

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                do{
                    cout << "Podaj system na jaki chcesz przeliczyc liczbe: ";
                    cin >> base;

                    if(base<2 || base>36)
                        cout << "System musi byc z przedzialu od 2 do 36!" << endl;
                } while(base<2 || base>36);
                do{
                    cout << "Podaj liczbe w systemie 10. (0 - 100 000): ";
                    cin >> number;

                    if(number<0 || number>100000)
                        cout << "Liczba musi byc z przedzialu od 0 do 100 000!" << endl;
                } while(number<0 || number>100000);

                cout << "liczba " << number << " w systemie " << base << " to: " << convertDecimal(number, base) << endl;
                break;

            case 2:
                cout << "Podaj liczbe w systemie 10.: ";
                cin >> number;
                cout << "Liczba " << number << " w systemie 7. to: " << convertToBase7(number) << endl;
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
    cout << "----------------------------------------" << endl;
    cout << "-          Co chcesz zrobic ?          -" << endl;
    cout << "----------------------------------------" << endl;
    cout << "1. Przelicz liczbe na dowolny system" << endl;
    cout << "2. Przelicz liczbe na system 7." << endl;
    cout << "0. Zakoncz program" << endl;
    cout << "Wybierz: ";
}

string convertDecimal(int decimal, const int base){
    if (decimal == 0) return "0";

    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const bool isNegative = decimal < 0;
    decimal = abs(decimal);
    string result;

    while(decimal > 0){
        const int residual = decimal % base;
        result += digits[residual];
        decimal /= base;
    }

    if(isNegative) result += '-';

    reverse(result.begin(), result.end());

    return result;
}

string convertToBase7(const int number){
    if (number == 0) return "0";

    string base7;
    int num = abs(number);

    while(num > 0){
        base7 = to_string(num % 7) + base7;
        num /= 7;
    }

    return (number > 0 ? "" : "-") + base7;
}
