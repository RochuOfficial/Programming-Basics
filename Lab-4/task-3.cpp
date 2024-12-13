// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>

// ---------- DEFINE CONSTANTS ----------
#define SUCCESS 0
#define FAILURE 1

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
int rollDice();
void displayStats(int, int, int);
void win(int&);
void loss(int&);

// ---------- MAIN ----------
int main(){

    int randomSum, money(100), points(0), roll(1), round(1), wins(0), losses(0);
    char choice, play;
    bool firstRoll;

    cout << "Chcesz zagrac w gre? (t/n): ";
    cin >> choice;
    if (choice == 'n' || choice == 'N') return SUCCESS;

    while(true){
        roll = 1;
        points = 0;
        firstRoll = true;

        while(true){
            cout << endl << endl << "****** Rzut #" << roll <<" ******" << endl;
            randomSum = rollDice();

            cout << "Suma wyrzuconych oczek: " << randomSum << endl;

            if (roll == 2) firstRoll = false;

            if((randomSum == 7 || randomSum == 11) && firstRoll){
                cout << "Wygrales bo wyrzuciles " << randomSum << " w 1. rzucie!!!" << endl;
                win(money);
                wins++;
                break;
            }
            else if((randomSum == 2 || randomSum == 3 || randomSum == 12) && firstRoll){
                cout << "Przegrales bo wyrzuciles " << randomSum << " w 1. rzucie!!!" << endl;
                loss(money);
                losses++;
                break;
            }
            else if(randomSum >= 4 && randomSum <= 10 && randomSum != 7 && randomSum != points){
                points = randomSum;
                cout << "Liczba " << randomSum << " jest teraz twoimi punktami!" << endl;
            }
            else if(randomSum == points){
                cout << "Wygrales bo wyrzuciles " << randomSum << " 2. raz!!!" << endl;
                win(money);
                wins++;
                break;
            }
            else if(randomSum == 7 && !firstRoll){
                cout << "Przegrales bo wyrzuciles 7!!!" << endl;
                loss(money);
                losses++;
                break;
            }
            else {
                cout << "Jestes na 0!" << endl;
            }

            Sleep(2000);
            roll++;
        }


        Beep(750, 300); Beep(1000, 500);
        cout << endl << endl;
        cout << "------------------------------" << endl;
        cout << "Koniec Rundy!" << endl;
        cout << "Statystyki po " << round << " rundach:" << endl;
        displayStats(money, wins, losses);
        if (money < 1){
            cout << "Zbankrutowales!!!" << endl << "Kasyno zawsze wygrywa ;)" << endl;
            cout << "Nacisnij dowolny przycisk aby zakonczyc gre...";
            getch();
            break;
        }
        else if (money > 100) cout << "Gratulacje!" << endl <<"Jestes " << money-100 << "PLN na plusie!" << endl;
        else if(money == 100) cout << "Brawo!" << endl << "Wyszedles na 0!" << endl;
        else cout << "Slabo!" << endl << "Jestes " << 100-money <<"PLN na minusie!" << endl;
        round++;

        cout << endl << "Chcesz zagrac kolejna runde? (t/n): ";
        cin >> play;
        if (play == 'n' || play == 'N') break;
    }

    return SUCCESS;
}

// ---------- FUNCTIONS ----------

int rollDice(){
    srand(time(nullptr));
    return rand() % 11 + 2;
}

void displayStats(const int money, const int wins, const int losses){
    cout << "Masz na koncie " << money << "PLN" << endl;
    cout << "Wygrane: " << wins << endl;
    cout << "Przegrane: " << losses << endl;
    cout << endl;
}

void win(int &money){
    Beep(1500, 300);
    money += 30;
}

void loss(int &money){
    Beep(500, 300);
    money -= 20;
}
