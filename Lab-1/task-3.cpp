#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double radius(0), height(0), coneVolume(0), globeVolume(0);

    cout << "Podaj promien: ";
    cin >> radius;
    cout << "Podaj wysokosc: ";
    cin >> height;

    coneVolume = 1.0/3.0 * M_PI * pow(radius, 2) * height;
    globeVolume = 4.0/3.0 * M_PI * pow(radius, 3);

    cout << endl << "Objestosc kuli o promieniu " << radius << " to: " << globeVolume << endl;
    cout << endl << "Objestosc stozka o promieniu " << radius << " i wysokosci " << height <<
        " to: " << coneVolume << endl;

    return 0;
}
