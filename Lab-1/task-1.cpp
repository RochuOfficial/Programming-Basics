#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double angle(0.0), radian(0.0);

    cout << "Podaj kat w stopniach: ";
    cin >> angle;

    radian = angle * M_PI / 180;

    cout << angle << " w radianach to: " << radian << endl;

    return 0;
}
