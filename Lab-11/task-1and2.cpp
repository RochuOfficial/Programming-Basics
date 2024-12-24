// Mateusz Rochowski, 258669
// ------- IMPORT LIBRARIES -------
#include <iostream>
#include <limits>
#include <bits/fs_fwd.h>

// ------- DEFINE CONSTANTS -------
#define CHAR_SIZE 4

using namespace std;

// ------- DEFINE FUNCTIONS -------
void clearScreen();
void pause();
void cinClearBuffer();
void menu(unsigned int number);
int checkInt();
unsigned int checkUnsignedInt();
void displayBits(unsigned int n);
void turnOnBit(unsigned int n, int position);
void turnOffBit(unsigned int n, int position);
void changeBitState(unsigned int n, int position);
void checkBitState(unsigned int n, int position);
int encodeCharacters(const char* array);
void decodeCharacters(int encodedNumber);
void displayArray(const char* array, int arraySize);

// ------- MAIN -------
int main() {
    int choice, bitPosition, encodedCharacters = 0;
    char characters[CHAR_SIZE] = {}, decodeChoice;
    bool encodedNumbers = false;

    cout << "Podaj liczbe od 0 do " << numeric_limits<unsigned int>::max() << ": ";
    unsigned int number = checkUnsignedInt();

    clearScreen();
    while (true) {
        menu(number);
        choice = checkInt();

        switch (choice) {
            case 1:
                clearScreen();
                cout << "Podaj liczbe od 0 do " << numeric_limits<unsigned int>::max() << ": ";
                number = checkUnsignedInt();
                cout << endl << "Liczba zostala zapisana!" << endl;
                break;

            case 2:
                clearScreen();
                cout << endl << "Podaj pozycje bitu: ";
                bitPosition = checkInt();
                turnOnBit(number, bitPosition);
                break;

            case 3:
                clearScreen();
                cout << endl << "Podaj pozycje bitu: ";
                bitPosition = checkInt();
                turnOffBit(number, bitPosition);
                break;

            case 4:
                clearScreen();
                cout << endl << "Podaj pozycje bitu: ";
                bitPosition = checkInt();
                changeBitState(number, bitPosition);
                break;

            case 5:
                clearScreen();
                cout << endl << "Podaj pozycje bitu: ";
                bitPosition = checkInt();
                checkBitState(number, bitPosition);
                break;

            case 6:
                clearScreen();
                for (int i = 0; i < CHAR_SIZE; i++) {
                    cout << endl << "Podaj " << i+1 << ". znak: ";
                    while (true) {
                        cin >> characters[i];
                        if (cin.fail() || characters[i] == '\0') {
                            cinClearBuffer();
                            cout << endl << "Mozesz podac tylko 1 znak!" << endl;
                            cout << endl << "Podaj " << i+1 << ". znak: ";
                        }
                        else {
                            cinClearBuffer();
                            break;
                        }
                    }
                }
                encodedCharacters = encodeCharacters(characters);
                encodedNumbers = true;
                cout << endl << "Liczba kod to: " << encodedCharacters << endl;
                break;

            case 7:
                clearScreen();
                cout << endl << "Chcesz uzyc liczby z pkt. 6 czy podac wlasna liczbe ?" << endl;
                cout << "\"k\" - zakodowana z pkt. 6; \"w\" - wlasna: ";
                while (true) {
                    cin >> decodeChoice;
                    if (cin.fail()) {
                        cinClearBuffer();
                        cout << endl << "Mozesz wybrac tylko \"w\" lub \"k\"!" << endl;
                        cout << "Wybierz: ";
                    }
                    else {
                        cinClearBuffer();
                        break;
                    }
                }
                switch (decodeChoice) {
                    case 'k':
                    case 'K':
                        if (!encodedNumbers) {
                            clearScreen();
                            cout << "Najpierw zakoduj liczby!" << endl;
                            break;
                        }
                        decodeCharacters(encodedCharacters);
                        break;

                    case 'w':
                    case 'W':
                        clearScreen();
                        cout << "Podaj liczbe od 0 do " << numeric_limits<unsigned int>::max() << ": ";
                        const unsigned int decodeNumber = checkUnsignedInt();
                        decodeCharacters(decodeNumber);
                        break;
                }
                break;

            case 0:
                cout << endl << "Zamykanie programu...." << endl;
                return 0;

            default:
                cout << endl << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl;
        pause();
        clearScreen();
    }
}

// ------- FUNCTIONS -------
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void menu(const unsigned int number) {
    cout << "----------------------------------------------------" << endl;
    cout << "-                Co chcesz zrobic ?                -" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1. Podaj inna liczbe (twoja obecna liczba: " << number << ")" << endl;
    cout << "2. Wlacz bit na podanej pozycji" << endl;
    cout << "3. Wylacz bit na podanej pozycji" << endl;
    cout << "4. Zmien wartosc bitu na podanej pozycji" << endl;
    cout << "5. Sprawdz stan bitu" << endl;
    cout << "6. Zakoduj 4 znaki" << endl;
    cout << "7. Zdekoduj liczbe na 4 znaki" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

int checkInt() {
    int result;

    while (true) {
        cin >> result;
        if (cin.fail()) {
            cinClearBuffer();
            cout << "To nie jest liczba!" << endl;
            cout << "Podaj liczbe: ";
        }
        else {
            cinClearBuffer();
            return result;
        }
    }
}

unsigned int checkUnsignedInt() {
    unsigned int result;

    while (true) {
        cin >> result;
        if (cin.fail()) {
            cinClearBuffer();
            cout << "Nie poprawna liczba!" << endl;
            cout << "Podaj liczbe od 0 do " << numeric_limits<unsigned int>::max() << ": ";
        }
        else {
            cinClearBuffer();
            return result;
        }
    }
}

void displayBits(const unsigned int n) {
    const int BITS = sizeof(unsigned int) * 8;

    for (int i = BITS - 1; i >= 0; i--) {
        cout << ((n >> i) & 1);
        if (i % 4 == 0) cout << " ";
    }
    cout << endl;
}

void turnOnBit(unsigned int n, const int position) {
    if (position < 0 || position > numeric_limits<unsigned int>::digits) {
        cout << endl << "Niepoprawna pozycja bitu!" << endl;
        return;
    }

    const unsigned int mask = 1 << position;

    cout << endl << "Maska: "; displayBits(mask);

    cout << endl << "Przed: "; displayBits(n);

    n |= mask;

    cout << endl << "Po:    "; displayBits(n);
}

void turnOffBit(unsigned int n, const int position) {
    if (position < 0 || position > numeric_limits<unsigned int>::digits) {
        cout << endl << "Niepoprawna pozycja bitu!" << endl;
        return;
    }

    const unsigned int mask = ~(1 << position);

    cout << endl << "Maska: "; displayBits(mask);

    cout << endl << "Przed: "; displayBits(n);

    n &= mask;

    cout << endl << "Po:    "; displayBits(n);
}

void changeBitState(unsigned int n, const int position) {
    if (position < 0 || position > numeric_limits<unsigned int>::digits) {
        cout << "Niepoprawna pozycja bitu!" << endl;
        return;
    }

    const unsigned int mask = 1 << position;

    cout << endl << "Maska: "; displayBits(mask);

    cout << endl << "Przed: "; displayBits(n);

    n ^= mask;

    cout << endl << "Po:    "; displayBits(n);
}

void checkBitState(const unsigned int n, const int position) {
    if (position < 0 || position > numeric_limits<unsigned int>::digits) {
        cout << "Niepoprawna pozycja bitu!" << endl;
        return;
    }

    const unsigned int mask = 1 << position;

    cout << endl << "Maska:  "; displayBits(mask);
    cout << endl << "Liczba: "; displayBits(n);

    cout << endl << "Stan bitu: ";
    if ((n & mask) != 0) cout << "wlaczony" << endl;
    else cout << "wylaczony" << endl;
}

int encodeCharacters(const char* array) {
    int encodedCharacters = 0;
    int shift;

    for (int i = 0; i < CHAR_SIZE && array[i] != '\0'; i++) {
        const unsigned char character = array[i]; // & 0xFF;
        shift = i * 8;
        encodedCharacters |= (character) << shift;

        cout << endl << "Kodowana liczba: "; displayBits(encodedCharacters);
    }

    return encodedCharacters;
}

void decodeCharacters(int encodedNumber) {
    char decodedCharacters[CHAR_SIZE + 1], mask;
    int shift;

    decodedCharacters[CHAR_SIZE + 1] = '\0';
    for (int i = 0; i < CHAR_SIZE; i++) {
        shift = i * 8;
        decodedCharacters[i] = encodedNumber >> shift;
    }

    cout << endl << "Odkodowane znaki to:" << endl;
    displayArray(decodedCharacters, CHAR_SIZE);
}

void displayArray(const char* array, const int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}
