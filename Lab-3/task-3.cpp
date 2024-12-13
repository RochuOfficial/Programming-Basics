// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

// ---------- DEFINE FUNCTIONS ----------
void menu();
void displayTable(int interval);

using namespace std;

// ---------- MAIN ----------
int main(){

    char choice;
    int interval(0);

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 't':
            case 'T':
                cout << "Co ile stopni wyswietlic wartosci?: ";
                cin >> interval;
                displayTable(interval);
                break;

            case 'n':
            case 'N':
                cout << "Zamykanie programu" << endl;
                return SUCCESS;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
    }
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "Czy chcesz wyswietlic tabele?" << endl;
    cout << "Tak (t), Nie (n): ";
}

void displayTable(int interval){
    double sinVal(0.0), cosVal(0.0), tanVal(0.0), cotVal(0.0);

    cout << setfill('-') << setw(95) << "-" << endl;
    cout << setfill(' ');
    cout << setw(15) << "Stopnie"
             << setw(15) << "Radiany"
             << setw(15) << "Sinus"
             << setw(15) << "Cosinus"
             << setw(15) << "Tangens"
             << setw(15) << "Cotangens" << endl;
        cout << setfill('-') << setw(95) << "-" << endl;
        cout << setfill(' ');

    for (int angle = 0; angle <= 90; angle+=interval){
        const double radianAngle = angle * M_PI / 180.0;

        sinVal = sin(radianAngle);
        cosVal = cos(radianAngle);
        tanVal = sinVal/cosVal;
        cotVal = cosVal/sinVal;

        cout << fixed << setprecision(4) << setw(15) << angle
             << setw(15) << radianAngle
             << setw(15) << sinVal
             << setw(15) << cosVal;
             if (angle == 90)
                cout << fixed << setprecision(4) << setw(15) << "N/D";
             else
                cout << fixed << setprecision(4) << setw(15) << tanVal;
             if (angle == 0)
                cout << fixed << setprecision(4) << setw(15) << "N/D" << endl;
             else
                cout << fixed << setprecision(4) << setw(15) << cotVal << endl;
    }
    cout << endl << endl;
}
