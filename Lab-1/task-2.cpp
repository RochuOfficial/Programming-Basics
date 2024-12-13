#include <iostream>

using namespace std;

int main() {

    int numbers[3] = {0};
    int sum(0);
    double average(0), harmonicMean(0);

    for (int i = 0; i < 3; i++) {
        cout << "Podaj " << i + 1 << " liczbe: ";
        cin >> numbers[i];
    }

    sum = numbers[0] + numbers[1] + numbers[2];
    average = sum / 3.0;
    harmonicMean = 3.0 / (1.0/numbers[0] + 1.0/numbers[1] + 1.0/numbers[2]);

    cout << endl <<"Suma liczb: " << sum << endl;
    cout << "Srednia liczb: " << average << endl;
    cout << "Srednia harmoniczna: " << harmonicMean << endl;

    return 0;
}
