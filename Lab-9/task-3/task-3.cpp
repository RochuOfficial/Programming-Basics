// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <limits>

// ---------- DEFINE CONSTANTS ----------
#define NAME_LENGHT 12
#define LASTNAME_LENGHT 20
#define TITLE_LENGHT 20
#define AUTHORS_ARRAY_SIZE 3
#define BOOKS_ARRAY_SIZE 4

using namespace std;

// ---------- DEFINE STRUCTURES ----------
struct Writer{
    int yearBorn;
    char name[NAME_LENGHT];
    char lastName[LASTNAME_LENGHT];
};

struct Book{
    char title[TITLE_LENGHT];
    int publishedYear;
    Writer* author;
};

// ---------- DEFINE FUNCTIONS ----------
void menu();
int loadAuthors(Writer authors[], int authorsSize);
void fillBooks(Book books[], Writer authors[], int booksSize, int authorsSize);
void displayAuthors(const Writer authors[], int authorsSize);
void displayBooks(const Book books[], int booksSize);
void getWriter(const Writer& writer);
void getBook(const Book& book);

// ---------- MAIN ----------
int main(){

    Book books[BOOKS_ARRAY_SIZE];
    Writer authors[AUTHORS_ARRAY_SIZE];
    int choice;
    bool authorsLoaded = false, booksFilled = false;

    while (true){
        menu();
        while (true){
            cin >> choice;
            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Wybierz wlasciwa opcje!" << endl;
                cout << "Wybierz: ";
            }
            else break;
        }

        switch (choice){
            case 1:
                if (!loadAuthors(authors, AUTHORS_ARRAY_SIZE)){
                    break;
                }
                authorsLoaded = true;
                break;

            case 2:
                if (!authorsLoaded){
                    cout << endl << "Najpierw wczytaj autorow!" << endl;
                    break;
                }
                fillBooks(books, authors, BOOKS_ARRAY_SIZE, AUTHORS_ARRAY_SIZE);
                cout << endl << "Ksiazki zostaly zapisane." << endl;
                booksFilled = true;
                break;

            case 3:
                if (!authorsLoaded){
                    cout << endl << "Najpierw wczytaj autorow!" << endl;
                    break;
                }
                cout << endl << "Autorzy:" << endl;
                displayAuthors(authors, AUTHORS_ARRAY_SIZE);
                break;

            case 4:
                if (!authorsLoaded){
                    cout << endl << "Najpierw wczytaj autorow!" << endl;
                    break;
                }
                if (!booksFilled){
                    cout << endl << "Najpierw wypelnij ksiazki!" << endl;
                    break;
                }
                cout << endl << "Ksiazki:" << endl;
                displayBooks(books, BOOKS_ARRAY_SIZE);
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
    cout << "1. Wczytaj autorow z pliku" << endl;
    cout << "2. Wypelnij ksiazki" << endl;
    cout << "3. Wyswietl autorow" << endl;
    cout << "4. Wyswietl ksiazki" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

int loadAuthors(Writer authors[], const int authorsSize){
    int counter = 0;
    char line[256];
    Writer entry{};

    ifstream inputFile("writers.txt");

    if (!inputFile.is_open()) {
        cout << endl << "Blad przy otwieraniu pliku!: " << endl;
        perror("fopen");
        return 1;
    }

    while (inputFile.getline(line, sizeof(line))){
        if (counter >= authorsSize){
            cout << "Przekroczono maksymalny zakres rekordow(" << authorsSize - 1 << ")!" << endl;
            return 1;
        }

        if (sscanf(line, "%11[^,], %19[^,], %d", entry.name, entry.lastName, &entry.yearBorn) == 3){
            authors[counter++] = entry;
        }
        else {
            cout << "Nie mozna sparsowac linii:" << endl << line << endl;
            inputFile.close();
            return 1;
        }
    }
    cout << endl << "Autorzy zostali wczytani." << endl;
    inputFile.close();
    return 0;
}

void fillBooks(Book books[], Writer authors[], int booksSize, int authorsSize){
    int choice;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < booksSize; i++){
        cout << endl << "Podaj tytul " << i+1 << ". ksiazki: ";
        while (true){
            cin.getline(books[i].title, TITLE_LENGHT);

            if (cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Ksiazka moze miec maksymalnie " << TITLE_LENGHT - 1 << " znakow!" << endl;
                cout << "Podaj tytul ksiazki: ";
            }
            else break;
        }

        cout << "Podaj rok wydania " << i+1 << ". ksiazki: ";
        while (true){
            cin >> books[i].publishedYear;

            if (cin.fail() || books[i].publishedYear <= 0){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Rok wydania musi byc liczba calowita nieujemna!" << endl;
                cout << "Podaj rok wydania ksiazki: ";
            }
            else break;
        }

        cout << "Przypisz autora " << i+1 << ". ksiazki:" << endl;
        displayAuthors(authors, authorsSize);
        cout << "Wybierz: ";
        while (true){
            cin >> choice;

            if (cin.fail() || choice <= 0 || choice > authorsSize){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << endl << "Liczba musi byc z zakresu od 1 do " << authorsSize << "!" << endl;
                displayAuthors(authors, authorsSize);
                cout << "Wybierz: ";
            }
            else {
                books[i].author = &authors[--choice];
                break;
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void displayAuthors(const Writer authors[], const int authorsSize){
    cout << endl;
    for (int i = 0; i < authorsSize; i++){
        cout << i+1 << ". "; getWriter(authors[i]);
    }
}

void displayBooks(const Book books[], const int booksSize){
    for (int i = 0; i < booksSize; i++){
        cout << i+1 << ". ";
        getBook(books[i]);
        cout << endl;
    }
}

void getWriter(const Writer& writer){
    cout << writer.name << " " << writer.lastName << ", urodzony w " << writer.yearBorn << " roku." << endl;
}

void getBook(const Book& book){
    cout << "Tytul: \"" << book.title << "\", wydana w " << book.publishedYear << " roku, autor: ";
    getWriter(*book.author);
}
