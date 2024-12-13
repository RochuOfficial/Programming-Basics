// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <limits>
#include <string>
#include <cstring>

// ---------- DEFINE CONSTANTS ----------
#define NAME_LEN 20
#define TITLE_LEN 50
#define TYPE_LEN 20
#define ARRAY_SIZE 10
#define FILENAME_LEN 50

using namespace std;

// ---------- DEFINE STRUCTURES ----------
struct Writer {
    char name[NAME_LEN];
    int yearBorn;
};

struct Book {
    char title[TITLE_LEN];
    char type[TYPE_LEN];
    int yearPublished;
    Writer* author;
};

// ---------- DEFINE FUNCTIONS ----------
void cinClearBuffer();
void menu();
bool loadAuthors(const char* fileName, Book books[], int booksSize);

// ---------- MAIN ----------
int main() {
    Book books[ARRAY_SIZE];
    int choice;
    char fileName[FILENAME_LEN];

    cout << "Podaj nazwe pliku z ksiazkami: ";
    while (true) {
        cin.getline(fileName, FILENAME_LEN);
        if (cin.fail()) {
            cinClearBuffer();
            cout << endl << "Niepoprawna nazwa pliku!" << endl;
            cout << "Podaj nazwe pliku: ";
        }
        else break;
    }

    while (!loadAuthors(fileName, books, ARRAY_SIZE)) {
        cout << endl << "Podaj nazwe pliku: ";
        while (true) {
            cin.getline(fileName, FILENAME_LEN);
            if (cin.fail()) {
                cinClearBuffer();
                cout << endl << "Niepoprawna nazwa pliku!" << endl;
                cout << "Podaj nazwe pliku: ";
            }
            else break;
        }
    }

    while (true) {
        menu();
        while (true) {
            cin >> choice;
            if (cin.fail()) {
                cinClearBuffer();
                cout << endl << "Twoj wybor powienien byc liczba calkowita nieujemna!" << endl;
                cout << "Wybierz: ";
            }
            else break;
        }

        switch (choice) {
            case 1:
                cout << "Podaj nowa nazwe pliku z ksiazkami: ";
                while (true) {
                    cin.getline(fileName, FILENAME_LEN);
                    if (cin.fail()) {
                        cinClearBuffer();
                        cout << endl << "Niepoprawna nazwa pliku!" << endl;
                        cout << "Podaj nazwe pliku: ";
                    }
                    else break;
                }
                break;

            case 2:
                cout << endl << "Opcja 2" << endl;
                break;

            case 0:
                cout << endl << "Zamykanie programu..." << endl;
                return 0;

            default:
                cout << endl << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl;
        cinClearBuffer();
    }
}

// ---------- DEFINE FUNCTIONS ----------
void cinClearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void menu() {
    cout << "----------------------------------------------" << endl;
    cout << "-             Co chcesz zrobic ?             -" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1. Wybierz inny plik" << endl;
    cout << "2. Opcja 2" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

bool loadAuthors(const char* fileName, Book books[], const int booksSize) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << endl << "Blad przy otwieraniu pliku!: " << endl;
        perror("fopen");
        return false;
    }

    int counter = 0;
    char line [512], title[TITLE_LEN], type[TYPE_LEN], name[NAME_LEN];
    int yearBorn, yearPublished;

    while (inputFile.getline(line, sizeof(line))) {
        if (counter >= booksSize) {
            cout << endl << "Przekroczono maksymalna liczbe rekordow(" << booksSize - 1 << ")!" << endl;
            return false;
        }

        sscanf(line, "%s, %s, %d, %s, %d", title, type, &yearPublished, name, &yearBorn);

        Writer* author = new Writer();
        strncpy(author->name, name, NAME_LEN);
        author->name[NAME_LEN - 1] = '\0';
        author->yearBorn = yearBorn;

        strncpy(books[counter].title, title, TITLE_LEN);
        books[counter].title[TITLE_LEN - 1] = '\0';
        strncpy(books[counter].type, type, TYPE_LEN);
        books[counter].type[TYPE_LEN - 1] = '\0';
        books[counter].yearPublished = yearPublished;
        books[counter].author = author;

        delete author;
        counter++;
    }
    inputFile.close();
    cout << endl << "Ksiazki zostaly wczytane" << endl;
    return true;
}
