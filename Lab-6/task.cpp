// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <utility>

// ---------- DEFINE CONSTANTS ----------
#define ARRAY_SIZE 100
#define POLYNOMIAL_ARRAY_SIZE 5

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
void menu();
void fillArray(int[], int, int, int);
void displayArray(int[], int);
long int sqrtSum(int[], int);
pair<int, int> findMaxValue(const int[], int);
double calculateMean(const int[], int);
double calculateStandardDeviation(int[], int);
long int dotProduct(const int[], const int[], int);
double calculatePolynomialValue(const int[], int, int);

// ---------- MAIN ----------
int main(){

    int choice = 1, bottomCutoff, upperCutoff, polynomialValue;
    int x[ARRAY_SIZE], y[ARRAY_SIZE], polynomial[POLYNOMIAL_ARRAY_SIZE];
    long int result;
    pair<int, int> maxValue;

    fillArray(x, ARRAY_SIZE, 0, 10);
    fillArray(y, ARRAY_SIZE, 0, 10);

    while(choice != 0){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Podaj dolny przedzial: ";
                cin >> bottomCutoff;
                cout << "Podaj gorny przedzial: ";
                cin >> upperCutoff;
                fillArray(x, ARRAY_SIZE, bottomCutoff, upperCutoff);
                fillArray(y, ARRAY_SIZE, bottomCutoff, upperCutoff);
                cout << "Tabele zostaly wypelnione!";
                cout << endl << endl;
                break;

            case 2:
                cout << "Tabela X:" << endl;
                displayArray(x, ARRAY_SIZE);
                cout << endl << endl << "Tabela Y:" << endl;
                displayArray(y, ARRAY_SIZE);
                cout << endl << endl;
                break;

            case 3:
                result = sqrtSum(x, ARRAY_SIZE);
                cout << "Suma kwadratow tablicy X to: " << result;
                cout << endl << endl;
                break;

            case 4:
                maxValue = findMaxValue(y, ARRAY_SIZE);
                cout << "Najwieksza wartosc w tablicy Y:" << maxValue.first << endl;
                cout << "Jej indeks to: " << maxValue.second << endl;
                cout << endl << endl;
                break;

            case 5:
                cout << "Odchylenie standardowe tablicy X to: " << calculateStandardDeviation(x, ARRAY_SIZE) << endl;
                cout << endl << endl;
                break;

            case 6:
                cout << "Iloczyn skalarny tablic X i Y to: " << dotProduct(x, y, ARRAY_SIZE) << endl;
                cout << endl << endl;
                break;

            case 7:
                for (int i = 0; i < POLYNOMIAL_ARRAY_SIZE; i++){
                    cout << "Podaj " << i+1 << ". wspolczynnik: ";
                    cin >> polynomial[i];
                }
                cout << "Podaj punkt x: ";
                cin >> polynomialValue;
                cout << "Wartosc wielomianu w punkcie " << polynomialValue << " to: " <<
                    calculatePolynomialValue(polynomial, polynomialValue, POLYNOMIAL_ARRAY_SIZE) << endl;
                cout << endl << endl;
                break;

            case 0:
                cout << "Zamykanie programu..." << endl;
                return 0;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
    }
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "---------------------------------------------------------" << endl;
    cout << "-                    Co chcesz zrobic ?                 -" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "1. Zapelnij obie tablice" << endl;
    cout << "2. Wyswietl tablice" << endl;
    cout << "3. Oblicz sume kwadratow nieparzystych elementow tablicy X" << endl;
    cout << "4. Znajdz najwieksza wartosc w tabeli Y" << endl;
    cout << "5. Oblicz odchylenie standardowe tablicy X" << endl;
    cout << "6. Oblicz iloczyn skalarny tablic X i Y" << endl;
    cout << "7. Oblicz wartosc wielomianu w punkcie" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

void fillArray(int givenArray[], const int arraySize, const int minValue, const int maxValue){
    srand(time(nullptr));

    for (int i = 0; i < arraySize; i++){
        givenArray[i] = minValue + rand() % (maxValue - minValue + 1);
    }
}

void displayArray(int givenArray[], const int arraySize){
    for (int i = 0; i < arraySize; i++){
        if(i % 20 == 0) cout << endl;
        cout << setw(4) << givenArray[i];
    }
}

long int sqrtSum(int givenArray[], const int arraySize){
    long int sqrtSum = 0;

    for (int i = 0; i < arraySize; i++){
        if (i % 2 == 1) sqrtSum += pow(givenArray[i], 2);
    }

    return sqrtSum;
}

pair<int, int> findMaxValue(const int givenArray[], const int arraySize){
    int maxValue = givenArray[0];
    int index = 0;

    for (int i = 1; i < arraySize; i++){
        if (givenArray[i] >= maxValue){
            maxValue = givenArray[i];
            index = i;
        }
    }

    return {maxValue, index};
}

double calculateMean(const int givenArray[], const int arraySize){
    double mean = 0;

    for (int i = 0; i < arraySize; i++){
        mean += givenArray[i];
    }

    return mean / arraySize;
}

double calculateStandardDeviation(int givenArray[], const int arraySize){
    double sd = 0;
    const double mean = calculateMean(givenArray, arraySize);

    for (int i = 0; i < arraySize; i++){
        sd += pow((givenArray[i] - mean), 2);
    }

    return sqrt(sd / arraySize);
}

long int dotProduct(const int firstArray[], const int secondArray[], const int arraySize){
    long int product = 0;

    for(int i = 0; i < arraySize; i++){
        product += (firstArray[i] * secondArray[i]);
    }

    return product;
}

double calculatePolynomialValue(const int givenArray[], const int xValue, const int arraySize){
    double value = givenArray[0];

    for (int i = 1; i < arraySize; i++){
        value = value * xValue + givenArray[i];
    }

    return value;
}
