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
#define FILENAME_LEN 100

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
void clearScreen();
void pause();
void cinClearBuffer();
void menu();
bool loadBooks(const char* fileName, Book books[], int booksSize);
void getWriter(const Writer& writer);
void getAllWriters(const Book books[],int booksSize);
void getBook(const Book& book);
void displayBooks(const Book books[], int booksSize);
bool saveAuthorsBooks(const char* author, const Book books[], int booksSize);
void sortBooks(Book books[], int booksSize);
void copyBooks(const Book source[], Book destination[], int booksSize);
bool saveBooks(const Book books[], int booksSize);
void displayTypes(const Book books[], int booksSize);
void chosenTypesBook(const Book books[], const char* type, int booksSize);

// ---------- MAIN ----------
int main() {
    Book books[ARRAY_SIZE];
    int choice;
    char fileName[FILENAME_LEN], authorChoice[NAME_LEN], typeChoice[TYPE_LEN];

    cout << "Podaj nazwe pliku z ksiazkami: ";
    while (true) {
        cin.getline(fileName, FILENAME_LEN);
        if (cin.fail()) {
            cinClearBuffer();
            cout << endl << "Niepoprawna nazwa pliku!" << endl;
            cout << "Podaj nazwe pliku: ";
        }
        else if (strcmp(fileName, "q") == 0 || strcmp(fileName, "Q") == 0) return 0;
        else break;
    }

    clearScreen();

    while (!loadBooks(fileName, books, ARRAY_SIZE)) {
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

    clearScreen();
    cout << "********* Plik zostal poprawnie wczytany! **********" << endl << endl;

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
                cinClearBuffer();
                clearScreen();
                cout << "Podaj nowa nazwe pliku z ksiazkami: ";
                cin.getline(fileName, FILENAME_LEN);

                while (!loadBooks(fileName, books, ARRAY_SIZE)) {
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
                break;

            case 2:
                clearScreen();
                displayBooks(books, ARRAY_SIZE);
                break;

            case 3:
                cinClearBuffer();
                clearScreen();
                cout << endl << "Ktorego autora ksiazki chcesz zapisac?:" << endl;
                getAllWriters(books, ARRAY_SIZE);
                cout << endl << "Wybierz: ";
                while (true) {
                    cin.getline(authorChoice, NAME_LEN);
                    if (cin.fail()) {
                        cinClearBuffer();
                        cout << "Poprawnie wpisz nazwisko autora!" << endl;
                        cout << "Wybierz: ";
                    }
                    else break;
                }
                if (saveAuthorsBooks(authorChoice, books, ARRAY_SIZE)) {
                    cout << endl << "Ksiazki zostaly zapisane!" << endl;
                    break;
                }
                break;

            case 4:
                sortBooks(books, ARRAY_SIZE);
                break;

            case 5:
                cinClearBuffer();
                clearScreen();
                displayTypes(books, ARRAY_SIZE);
                cout << endl << "Wybierz: ";
                while (true) {
                    cin.getline(typeChoice, NAME_LEN);
                    if (cin.fail()) {
                        cinClearBuffer();
                        cout << "Poprawnie wpisz nazwisko autora!" << endl;
                        cout << "Wybierz: ";
                    }
                    else break;
                }
                clearScreen();
                chosenTypesBook(books, typeChoice, ARRAY_SIZE);
                break;

            case 0:
                cout << endl << "Zamykanie programu..." << endl;
                return 0;

            default:
                cout << endl << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        pause();
        clearScreen();
    }
}

// ---------- DEFINE FUNCTIONS ----------
void clearScreen() {
#ifdef _WIN32
    system("cls");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("clear");
#else
    cout << "Twoj system operacyjny nie wspomaga czyszczenia terminala!" << endl;
#endif
}

void pause() {
#ifdef _WIN32
    system("pause");
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    system("read -n 1 -p \"Press any key to continue...\"")
#else
    cout << "Twoj system operacyjny nie wspomaga pausowania!" << endl;
#endif
}

void cinClearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

void menu() {
    cout << "----------------------------------------------------" << endl;
    cout << "-                Co chcesz zrobic ?                -" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1. Wybierz inny plik" << endl;
    cout << "2. Wyswietl ksiazki" << endl;
    cout << "3. Zapisz ksiazki wybranego autora do pliku" << endl;
    cout << "4. Posortuj ksiazki alfabetycznie wedlug autorow" << endl;
    cout << "5. Wypisz ksiazki danego typu" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

bool loadBooks(const char* fileName, Book books[], const int booksSize) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << endl << "Blad przy otwieraniu pliku!: " << endl;
        perror("fopen");
        return false;
    }

    int counter = 0;
    char line[1024];

    while (inputFile.getline(line, sizeof(line))) {
        if (counter >= booksSize) {
            cout << endl << "Przekroczono maksymalna liczbe rekordow(" << booksSize - 1 << ")!" << endl;
            return false;
        }
        Writer* author = new Writer;
        int fieldCounter = 0;
        char lineCopy[1024];
        strcpy(lineCopy, line);

        char *token = strtok(lineCopy, ",");
        while (token != nullptr) {
            switch (fieldCounter) {
                case 0: // Title
                    strncpy(books[counter].title, token, TITLE_LEN-1);
                    books[counter].title[TITLE_LEN-1] = '\0';
                    break;
                case 1: // Type
                    strncpy(books[counter].type, token, TYPE_LEN-1);
                    books[counter].type[TYPE_LEN-1] = '\0';
                    break;
                case 2: // Year published
                    books[counter].yearPublished = stoi(token);
                    break;
                case 3: // Authors name
                    strncpy(author->name, token, NAME_LEN-1);
                    author->name[NAME_LEN-1] = '\0';
                    break;
                case 4: // Authors birth year
                    author->yearBorn = stoi(token);
                    break;
                default:
                    cout << endl << "Nie poprawny format pliku!" << endl;
                    delete author;
                    return false;
            }
            token = strtok(nullptr, ",");
            fieldCounter++;
        }
        if (fieldCounter != 5) {
            cout << endl << "Blad parsowania lini:" << endl << line << endl;
            delete author;
            return false;
        }
        books[counter].author = author;
        counter++;
    }
    inputFile.close();
    cout << endl << "Ksiazki zostaly wczytane" << endl << endl;
    return true;
}

void getWriter(const Writer* writer) {
    cout << writer->name << ", urodzony/a w " << writer->yearBorn << " roku" << endl;
}

void getAllWriters(const Book books[], const int booksSize) {
    for (int i = 0; i < booksSize; i++) {
        cout << books[i].author->name << endl;
    }
}

void getBook(const Book* book) {
    cout << "tytul: " << book->title << " - rok wydania " << book->yearPublished << ", autor: ";
    getWriter(book->author);
}

void displayBooks(const Book books[], const int booksSize) {
    for (int i = 0; i < booksSize; i++) {
        getBook(&books[i]);
        cout << endl;
    }
}

bool saveAuthorsBooks(const char* author, const Book books[], const int booksSize) {
    const size_t nameLen = strlen(author);
    char* fileName = new char[nameLen + 4 + 1];

    strcpy(fileName, author);
    strcpy(fileName+nameLen, ".txt");

    ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        for (int i = 0; i < booksSize; i++) {
            if (strcmp(author, books[i].author->name) == 0) {
                outputFile << books[i].title << endl;
            }
        }
        delete[] fileName;
        return true;
    }

    delete[] fileName;
    cout << endl << "Blad zapisu pliku:" << endl;
    perror("fopen");
    return false;
}

void sortBooks(Book books[], const int booksSize) {
    Book copiedBooks[booksSize]{};
    Book temp{};

    copyBooks(books, copiedBooks, booksSize);

#ifdef _WIN32
    for (int i = 0; i < booksSize; i++) {
        for (int j = 0; j < booksSize - i - 1; j++) {
            if (_stricmp(copiedBooks[j].author->name, copiedBooks[j+1].author->name) > 0) {
                temp = copiedBooks[j];
                copiedBooks[j] = copiedBooks[j+1];
                copiedBooks[j+1] = temp;
            }
        }
    }
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
    for (int i = 0; i < booksSize; i++) {
        for (int j = 0; j < booksSize - i - 1; j++) {
            if (strcasecmp(copiedBooks[j].author->name, copiedBooks[j+1].author->name) > 0) {
                temp = copiedBooks[j];
                copiedBooks[j] = copiedBooks[j+1];
                copiedBooks[j+1] = temp;
            }
        }
    }
#else
    cout << endl << "Twoj system operacyjny nie wspiera funckji porownujacych slowa" << endl;
    return;
#endif
    saveBooks(copiedBooks, booksSize);
}

void copyBooks(const Book source[], Book destination[], const int booksSize) {
    for (int i = 0; i < booksSize; i++) {
        strcpy(destination[i].title, source[i].title);
        strcpy(destination[i].type, source[i].type);
        destination[i].yearPublished = source[i].yearPublished;
        destination[i].author = source[i].author;
    }
}

bool saveBooks(const Book books[], const int booksSize) {
    ofstream outputFile("alphabetically.txt");

    if (outputFile.is_open()) {
        for (int i = 0; i < booksSize; i++) {
            outputFile << books[i].title << "," << books[i].type << "," << books[i].yearPublished << ","
            << books[i].author->name << "," << books[i].author->yearBorn << endl;
        }
        outputFile.close();
        cout << endl << "Ksiazki zostaly zapisane" << endl;
        return true;
    }
    outputFile.close();
    cout << endl << "Blad zapisu pliku:" << endl;
    perror("fopen");
    return false;
}

void displayTypes(const Book books[], const int booksSize) {
    for (int i = 0; i < booksSize; i++) {
        cout << books[i].type << endl;
    }
}

void chosenTypesBook(const Book books[], const char* type, const int booksSize) {
    if (type[0] != '\0') {
        for (int i = 0; i < booksSize; i++) {
            if (strcmp(type, books[i].type) == 0) {
                getBook(&books[i]);
            }
        }
    }
    else {
        cout << endl << "Wybierz odpowiedni typ!" << endl;
    }
}
