// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <iostream>
#include <limits>

// ---------- DEFINE CONSTANTS ----------
#define NAME_LENGHT 10
#define LASTNAME_LENGHT 20

using namespace std;

// ---------- DEFINE STRUCTURES ----------
struct Person{
    char name[NAME_LENGHT];
    char lastName[LASTNAME_LENGHT];
    int age;
};

// ---------- DEFINE FUNCTIONS ----------
void menu();

// ---------- MAIN ----------
int main(){

    Person person{};
    int choice;
    bool infoFilled = false;

    while (true){
        menu();
        while (true){
            cin >> choice;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << endl << "Twoj wybor powienien byc liczba calkowita!" << endl;
                cout << "Wybierz: ";
            }
            else break;
        }

        switch (choice){
            case 1:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Podaj imie: ";
                while (true){
                    cin.getline(person.name, NAME_LENGHT);

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Twoje imie powinno miec maksymalnie " << NAME_LENGHT - 1 << " znakow!" << endl;
                        cout << "Podaj imie: ";
                    }
                    else break;
                }
                cout << "Podaj nazwisko: ";
                while (true){
                    cin.getline(person.lastName, LASTNAME_LENGHT);

                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Twoje nazwisko powinno miec maksymalnie " << LASTNAME_LENGHT - 1 << " znakow!" << endl;
                        cout << "Podaj nazwisko: ";
                    }
                    else break;
                }
                cout << "Podaj wiek: ";
                while (true){
                    cin >> person.age;

                    if (cin.fail() || person.age <= 0){
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Podaj liczbe calkowita nieujemna: ";
                    }

                    else break;
                }
                infoFilled = true;
                cout << endl << "Informacje zostaly zapisane" << endl;
                break;

            case 2:
                if (!infoFilled){
                    cout << endl << "Najpierw wypelnij informajce!" << endl;
                    break;
                }
                cout << endl << "Dane osoby:" << endl;
                cout << "Imie: " << person.name << endl;
                cout << "Nazwisko: " << person.lastName << endl;
                cout << "Wiek: " << person.age << endl;
                break;

            case 0:
                cout << "Zamykanie programu..." << endl;
                return 0;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl;
    }
}

// ---------- FUNCTIONS ----------

void menu(){
    cout << "----------------------------------------------" << endl;
    cout << "-             Co chcesz zrobic ?             -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Wczytaj informacje o osobie" << endl;
    cout << "2. Wyswietl informacje o osobie" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}
