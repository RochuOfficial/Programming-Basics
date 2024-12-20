// Mateusz Rochowski, 258669
// ------- IMPORT LIBRARIES -------
#include <iostream>
#include <limits>

using namespace std;

// ------- DEFINE FUNCTIONS -------
void checkInt(unsigned int& number);
void displayBits(unsigned int n);
void turnOnBit(unsigned int n);

int main() {

    unsigned int number, bits;

    cout << "Podaj liczbe od 0 do " << numeric_limits<unsigned int>::max() << ": ";
    checkInt(number);

    return 0;
}

// ------- FUNCTIONS -------
void checkInt(unsigned int& number) {
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Nie poprawna liczba!" << endl;
            cout << "Podaj liczbe od " << number << " do " << number << ": ";
        }
        else {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
}

void displayBits(const unsigned int n) {
    const int BITS = sizeof(unsigned int) * 8;

    for (int i = BITS - 1; i >= 0; i--) {
        cout << (n & (1 << i ? 1 : 0));
    }
    cout << endl;
}