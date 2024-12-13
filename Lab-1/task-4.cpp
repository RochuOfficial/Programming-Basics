#include <iostream>

using namespace std;

int main() {

    int year(0);

    cout << "Podaj rok: ";
    cin >> year;

    if (year <= 0) cout << "Podaj  liczbe dodatnia!" << endl;

    else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        cout << "Rok " << year << " jest przestepny!" << endl;
    else
        cout << "Rok " << year << " nie jest przestepny!" << endl;

    return 0;
}
