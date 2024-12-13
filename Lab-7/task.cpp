// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>
#include <iomanip>

// ---------- DEFINE CONSTANTS ----------
#define MATRIX_SIZE 5
#define DISPLAY_WIDTH 4

using namespace std;

// ---------- DEFINE FUNCTIONS ----------
void menu();
void fillMatrix(int givenMatrix[][MATRIX_SIZE], int rows, int columns, int minValue, int maxValue);
void displayMatrix(int givenMatrix[][MATRIX_SIZE], int rows, int columns);
void findMaxValue(int givenMatrix[][MATRIX_SIZE], int rows, int columns, int maxValuesArray[]);
void sortColumns(int givenMatrix[][MATRIX_SIZE], int rows, int columns, bool upToDown);
void transposeMatrix(int givenMatrix[][MATRIX_SIZE], int rows, int columns);
void copyMatrix(int source[][MATRIX_SIZE], int destination[][MATRIX_SIZE], int rows, int columns);
bool checkSymmetry(int givenMatrix[][MATRIX_SIZE], int rows, int columns);
void dynamicFill(int** matrix, int rows, int columns, int minValue, int maxValue);
void dynamicMatrixMain();
void dynamicMMenu();
void deleteDynamicM(int** matrix, int rows);
void displayDynamicMatrix(int** matrix, int rows, int columns);

// ---------- MAIN ----------
int main(){

    int choice, bottomCutOff, upperCutOff;
    int matrix[MATRIX_SIZE][MATRIX_SIZE], maxValue[MATRIX_SIZE];
    bool matrixFilled = false, upToDown;
    char sortChoice;

    for (int i = 0; i < MATRIX_SIZE; i++){
        maxValue[i] = -1;
    }

    while(true){
        menu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Podaj dolna granice: ";
                cin >> bottomCutOff;
                cout << "Podaj gorna granice: ";
                cin >> upperCutOff;

                fillMatrix(matrix, MATRIX_SIZE, MATRIX_SIZE, bottomCutOff, upperCutOff);
                matrixFilled = true;

                cout << "Macierz zostala wypelniona!" << endl;
                break;

            case 2:
                if(!matrixFilled){
                    cout << "Najpierw wypelnij macierz!" << endl;
                    break;
                }
                cout << "Twoja macierz:" << endl << endl;
                displayMatrix(matrix, MATRIX_SIZE, MATRIX_SIZE);
                break;

            case 3:
                if(!matrixFilled){
                    cout << "Najpierw wypelnij macierz!" << endl;
                    break;
                }

                findMaxValue(matrix, MATRIX_SIZE, MATRIX_SIZE, maxValue);

                cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;

                cout << "Wiersz(e) z najwieksza suma:" << endl;
                for (int i = 0; i < MATRIX_SIZE; i++){
                    if (maxValue[i] >= 0){
                        for (int j = 0; j < MATRIX_SIZE; j++){
                            cout << setw(DISPLAY_WIDTH) << matrix[maxValue[i]][j];
                        }
                        cout << endl;
                    }
                }
                break;

            case 4:
                if(!matrixFilled){
                    cout << "Najpierw wypelnij macierz!" << endl;
                    break;
                }
                do{
                cout << "Jak chcesz posortowac kolumny? (G - od gory | D - od dolu): ";
                cin >> sortChoice;

                if (sortChoice != 'G' && sortChoice != 'g' &&
                       sortChoice != 'D' && sortChoice != 'd'){
                    cout << endl << "Wybierz wlasciwa opcje!" << endl;
                       }

                }while(sortChoice != 'G' && sortChoice != 'g' &&
                       sortChoice != 'D' && sortChoice != 'd');

                if (sortChoice == 'G' || sortChoice == 'g') upToDown = true;
                else upToDown = false;

                sortColumns(matrix, MATRIX_SIZE, MATRIX_SIZE, upToDown);
                cout << "Macierz zostala posortowana!";
                break;

            case 5:
                if(!matrixFilled){
                    cout << "Najpierw wypelnij macierz!" << endl;
                    break;
                }
                transposeMatrix(matrix, MATRIX_SIZE, MATRIX_SIZE);
                cout << "Transpozycja ukonczona!" << endl;
                break;

            case 6:
                if(!matrixFilled){
                    cout << "Najpierw wypelnij macierz!" << endl;
                    break;
                }
                if (checkSymmetry(matrix, MATRIX_SIZE, MATRIX_SIZE))
                    cout << endl << "Macierz jest symetryczna!" << endl;
                else
                    cout << endl << "Macierz nie jest symetryczna!" << endl;
                break;

            case 7:
                dynamicMatrixMain();
                break;

            case 0:
                cout << "Zamykanie programu..." << endl;
                return 0;

            default:
                cout << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl << endl;
    }
}

// ---------- FUNCTIONS ----------
void menu(){
    cout << "---------------------------------------------" << endl;
    cout << "-                GLOWNE MENU                -" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1. Wypelnij macierz" << endl;
    cout << "2. Wyswietl macierz" << endl;
    cout << "3. Znajdz wiersz z najwieksza suma" << endl;
    cout << "4. Posortuj kolumny" << endl;
    cout << "5. Dokonaj transpozycji macierzy" << endl;
    cout << "6. Sprawdz symetrie macierzy" << endl;
    cout << "7. Stworz dynamiczna macierz" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "Wybierz: ";
}

void fillMatrix(int givenMatrix[][MATRIX_SIZE], const int rows, const int columns, const int minValue, const int maxValue){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(i == j || i < j){
                givenMatrix[i][j] = minValue + rand() % (maxValue - minValue + 1);
            }
            else{
                givenMatrix[i][j] = givenMatrix[j][i];
            }
        }
    }
}

void displayMatrix(int givenMatrix[][MATRIX_SIZE], const int rows, const int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << setw(DISPLAY_WIDTH) << givenMatrix[i][j];
        }
        cout << endl;
    }
}

void findMaxValue(int givenMatrix[][MATRIX_SIZE], const int rows, const int columns, int maxValuesArray[]){
    int sum = 0;
    int sumArray[rows];

    cout << endl << "Macierz:" << setw(DISPLAY_WIDTH*MATRIX_SIZE) << "Suma:" << endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            sum += givenMatrix[i][j];
            cout << setw(DISPLAY_WIDTH) << givenMatrix[i][j];
        }
        cout << setw(2*DISPLAY_WIDTH) << sum << endl;

        sumArray[i] = sum;
        sum = 0;
    }

    int maxValue = sumArray[0];
    for (int i = 1; i < rows; i++){
        if (sumArray[i] > maxValue){
            maxValue = sumArray[i];
        }
    }

    for (int i = 0; i < rows; i++){
        if (sumArray[i] == maxValue){
            maxValuesArray[i] = i;
        }
    }
}

void sortColumns(int givenMatrix[][MATRIX_SIZE], const int rows, const int columns, const bool upToDown){
    int temp;
    if (upToDown){
        for (int i = 0; i < columns; i++){
            for (int j = 0; j < rows - 1; j++){
                for (int k = 0; k < rows - j - 1; k++){
                    if (givenMatrix[k][i] > givenMatrix[k+1][i]){
                        temp = givenMatrix[k][i];
                        givenMatrix[k][i] = givenMatrix[k+1][i];
                        givenMatrix[k+1][i] = temp;
                    }
                }
            }
        }
    }
    else{
        for (int i = 0; i < columns; i++){
            for (int j = 0; j < rows - 1; j++){
                for (int k = 0; k < rows - j - 1; k++){
                    if (givenMatrix[k][i] < givenMatrix[k+1][i]){
                        temp = givenMatrix[k][i];
                        givenMatrix[k][i] = givenMatrix[k+1][i];
                        givenMatrix[k+1][i] = temp;
                    }
                }
            }
        }
    }
}

void transposeMatrix(int givenMatrix[][MATRIX_SIZE], const int rows, const int columns){
    int matrixCopy[MATRIX_SIZE][MATRIX_SIZE];

    copyMatrix(givenMatrix, matrixCopy, rows, columns);

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            givenMatrix[i][j] = matrixCopy[j][i];
        }
    }
}

void copyMatrix(int source[][MATRIX_SIZE], int destination[][MATRIX_SIZE], const int rows, const int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            destination[i][j] = source[i][j];
        }
    }
}

bool checkSymmetry(int givenMatrix[][MATRIX_SIZE], const int rows, const int columns){
    bool isSymmetric = true;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            if (givenMatrix[i][j] != givenMatrix[j][i]){
                isSymmetric = false;
                break;
            }
        }
    }

    return isSymmetric;
}

// ---------- DYNAMIC MATRIX FUNCTIONS ----------

void dynamicMatrixMain(){
    int choice = 1, m, n, bottomCutOff, upperCutOff;
    bool freedMemory = false;

    cout << endl << "Podaj liczbe wierszy: ";
    cin >> m;
    cout << "Podaj liczbe kolumn: ";
    cin >> n;
    cout << "Podaj dolna granice: ";
    cin >> bottomCutOff;
    cout << "Podaj gorna granice: ";
    cin >> upperCutOff;

    int** dynamicMatrix = new int*[m];
    for (int i = 0; i < m; i++){
        dynamicMatrix[i] = new int[n];
    }

    dynamicFill(dynamicMatrix, m, n, bottomCutOff, upperCutOff);

    cout << endl << "Macierz zostala swtorzona!" << endl << endl;

    while(choice != 0 || !freedMemory){
        dynamicMMenu();
        cin >> choice;

        switch(choice){
            case 1:
                cout << endl << "Podaj dolna granice: ";
                cin >> bottomCutOff;
                cout << "Podaj gorna granice: ";
                cin >> upperCutOff;
                dynamicFill(dynamicMatrix, m, n, bottomCutOff, upperCutOff);
                cout << endl << "Dynamiczna macierz zostala wypelniona!" << endl;
                freedMemory = false;
                break;

            case 2:
                cout << endl << "Twoja dynamiczna macierz:" << endl;
                displayDynamicMatrix(dynamicMatrix, m, n);
                break;

            case 3:
                if (!freedMemory){
                    cout << endl << "Najpierw zwolnij pamiec bierzacej macierzy!" << endl;
                    break;
                }
                cout << endl << "Podaj liczbe wierszy: ";
                cin >> m;
                cout << "Podaj liczbe kolumn: ";
                cin >> n;
                cout << "Podaj dolna granice: ";
                cin >> bottomCutOff;
                cout << "Podaj gorna granice: ";
                cin >> upperCutOff;

                dynamicMatrix = new int*[m];
                for (int i = 0; i < m; i++){
                    dynamicMatrix[i] = new int[n];
                }

                dynamicFill(dynamicMatrix, m, n, bottomCutOff, upperCutOff);
                freedMemory = false;
                break;

            case 4:
                deleteDynamicM(dynamicMatrix, m);
                freedMemory = true;
                cout << endl << "Pamiec zostala zwolniona!" << endl;
                break;

            case 0:
                if (!freedMemory){
                    cout << endl << "Najpierw zwolnij pamiec!" << endl;
                    break;
                }
                cout << endl << "Zamykanie dynamicznej macierzy..." << endl;
                break;

            default:
                cout << endl << "Wybierz wlasciwa opcje!" << endl;
                break;
        }
        cout << endl << endl;
    }
}

void dynamicMMenu(){
    cout << "---------------------------------------------" << endl;
    cout << "-         DYNAMICZNA MACIERZ - MENU         -" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "1. Wypelnij macierz" << endl;
    cout << "2. Wyswietl macierz" << endl;
    cout << "3. Stworz nowa macierz" << endl;
    cout << "4. Zwolnij pamiec" << endl;
    cout << "0. Zakoncz dynamiczna macierz" << endl;
    cout << "Wybierz: ";
}

void dynamicFill(int** matrix, const int rows, const int columns, const int minValue, const int maxValue){
    srand(time(nullptr));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            matrix[i][j] = minValue + rand() % (maxValue - minValue + 1);
        }
    }
}

void deleteDynamicM(int** matrix, const int rows){
    for (int i = 0; i < rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

void displayDynamicMatrix(int** matrix, const int rows, const int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            cout << setw(DISPLAY_WIDTH) << matrix[i][j];
        }
        cout << endl;
    }
}
