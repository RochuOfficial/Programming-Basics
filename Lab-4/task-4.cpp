// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <iostream>

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
void menu();
void calculate(float*, float*, bool);

// ---------- MAIN ----------
int main(){

    int choice;
    float yearG, yearM;
    bool MtoG = false;

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                MtoG = true;
                cout << "Podaj rok z kalendarza muzlumanskiego: ";
                cin >> yearM;
                break;

            case 2:
                MtoG = false;
                cout << "Podaj rok z kalendarza gregorianskiego: ";
                cin >> yearG;
                break;

            case 0:
                cout << "Zakmykanie programu!" << endl;
                return SUCCESS;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }

        calculate(&yearG, &yearM, MtoG);

        if(MtoG)
            cout << "Rok " << yearM << " w kalendarzu gregorianskim to: " << yearG << endl;
        else
            cout << "Rok " << yearG << " w kalendzarzu muzlumanskim to: " << yearM << endl;

        cout << endl;
    }
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "------------------------------------------------------------" << endl;
    cout << "-                    Co chcesz zrobic ?                    -" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "1. Przelicz date z kalendarza muzlumanskiego na gregorianski" << endl;
    cout << "2. Przelicz date z kalendarza gregorianskiego na muzlumanski" << endl;
    cout << "0. Zakonczyc program" << endl;
    cout << "Wybierz: ";
}
void calculate(float* pG, float* pM, const bool MtoG){
    if(MtoG)
        *pG = *pM - (*pM/33.0) + 621.0;

    else
        *pM = *pG - 621.0 + (*pG - 621.0) / 32.0;
}
