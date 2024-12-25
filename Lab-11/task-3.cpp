// Mateusz Rochowski, 258669
#include <iostream>
#include <limits>
#include <fstream>
#include <iomanip>
#include <cstring>

// ------- DEFINE CONSTANTS -------
#define FILE_LENGTH 20
#define KEY_LENGTH 5
#define LINE_BUFFER_SIZE 256

using namespace std;

// ------- DEFINE FUNCTIONS -------
void pause();
void cinClearBuffer();
int encryptingAlgorythm(const char* fileName, const char* key, int keyLength);

// ------- MAIN -------
int main() {
    char filename[FILE_LENGTH], key[KEY_LENGTH];

    cout << "Podaj nazwe pliku: ";
    while (true) {
        cin.getline(filename, FILE_LENGTH);
        if (cin.fail()) {
            cinClearBuffer();
            cout << endl << "Nazwa pliku nie moze byc dluzsza niz " << FILE_LENGTH << " znakow!" << endl;
            cout << "Podaj nazwe pliku: ";
        }
        else break;
    }

    cout << "Podaj " << KEY_LENGTH-1 << " znakowy klucz: ";
    while (true) {
        cin.getline(key, KEY_LENGTH);
        if (cin.fail()) {
            cinClearBuffer();
            cout << endl << "Klucz nie moze byc dluzszy niz " << KEY_LENGTH-1 << " znakow!" << endl;
            cout << "Podaj " << KEY_LENGTH-1 << " znakowy klucz: ";
        }
        else break;
    }

    if (!encryptingAlgorythm(filename, key, KEY_LENGTH-1)) {
        cout << endl << "Plik zmodyfikowany pomyslnie!" << endl;
        pause();
        return 0;
    }

    pause();
    return 1;
}

// ------- DEFINE FUNCTIONS -------
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int encryptingAlgorythm(const char* fileName, const char* key, const int keyLength) {
    fstream file(fileName, ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cout << endl << "Blad podczas otwierania pliku: " << strerror(errno) << endl;
        return 1;
    }

    char lineBuffer[LINE_BUFFER_SIZE] = {'\0'};
    long long bytesRead;

    while (!file.eof()) {
        file.read(lineBuffer, sizeof(lineBuffer));
        bytesRead = file.gcount();

        if (bytesRead > 0) {
            if (lineBuffer[bytesRead - 1] == '\n') {
                bytesRead--;
                lineBuffer[bytesRead] = '\0';
            }

            for (int i = 0; i < bytesRead; i++) {
                lineBuffer[i] ^= key[i % keyLength];
            }

            file.seekg(-bytesRead, ios::cur);
            file.write(lineBuffer, bytesRead);
            file.seekp(0, ios::cur);
            file.clear();
        }
        else if (file.fail() && !file.eof()) {
            cinClearBuffer();
            cout << endl << "Linia za dluga i zostala odcieta!" << endl;
        }
    }

    file.close();
    return 0;
}
