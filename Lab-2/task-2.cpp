// Mateusz Rochowski, 258669
// ---------- IMPORT LIBRARIES ----------
#include <cstdlib>
#include <iostream>

using namespace std;

// ---------- DECLARE FUNCTIONS ----------
void downRight(int starCountFunction);
void upRight (int starCountFunction);
void upLeft (int starCountFunction);
void downLeft (int starCountFunction);
void doubleDown (int starCountFunction);
void doubleUp (int starCountFunction);

// ---------- MAIN ----------
int main()
{

    int starCount(0);

    cout << "Podaj liczbe gwiazdek: ";
    cin >> starCount;

    // Up -> Down && Left -> Right
    downRight(starCount);


    cout << endl << endl;

    // Down -> Up && Left -> Right
    upRight(starCount);

    cout << endl << endl;

    // Down -> Up && Right -> Left
    upLeft(starCount);

    cout << endl << endl;

    // Up -> Down && Right -> Left
    downLeft(starCount);

    cout << endl << endl;

    // Double side && Up -> Down
    doubleDown(starCount);

    cout << endl << endl;

    // Double side && Down -> Up
    doubleUp(starCount);

    return 0;
}

// ---------- FUNCTIONS ----------
void downRight(int starCountFunction){
    int currentStar(0), level(1);

    while (currentStar < starCountFunction){
        for (int i = 1; i <= level && currentStar < starCountFunction; i++){
            cout << "*";
            ++currentStar;
        }

        cout << endl;
        ++level;
    }
}

void upRight (int starCountFunction){
    int remainingStars(starCountFunction), levels(1);

    while (levels * (levels + 1) / 2 <= starCountFunction){
        levels++;
    }
    levels--;

    for (int level = levels; level >= 1; level--){
        for (int stars = 1; stars <= level && remainingStars > 0; stars++){
            cout << "*";
            remainingStars--;
        }
        cout << endl;
    }
}

void upLeft (int starCountFunction){
    int remainingStars(starCountFunction), levels(1);

    while (levels * (levels + 1) / 2 <= starCountFunction){
        levels++;
    }
    levels--;

    for (int level = levels; level >= 1; level--){
        for (int space = 1; space <= levels - level; space++){
            cout << " ";
        }
        for (int stars = 1; stars <= level && remainingStars > 0; stars++){
            cout << "*";
            remainingStars--;
        }
        cout << endl;
    }
}

void downLeft (int starCountFunction){
    int remainingStars(starCountFunction), levels(1);

    while(levels * (levels + 1) / 2 <= starCountFunction){
        levels++;
    }
    levels--;

    for (int level = 1; level <= levels; level++){
        for (int spaces = levels - level; spaces >= 1; spaces--){
            cout << " ";
        }

        for (int stars = 1; stars <= level && remainingStars > 0; stars++){
            cout << "*";
            remainingStars--;
        }
        cout << endl;
    }
}

void doubleDown (int starCountFunction){
    int remainingStars(starCountFunction), levels(1);

    while (levels * (levels + 1) / 2 <= starCountFunction){
        levels++;
    }
    levels--;

    for (int level = 1; level <= levels; level++){
        for (int space = levels - level; space >= 1; space--){
            cout << " ";
        }

        for (int stars = 1; stars <= 2 * level - 1 && remainingStars > 0; stars++){
            cout << "*";
            remainingStars--;
        }

        cout << endl;
    }
}

void doubleUp (int starCountFunction){
    int remainingStars(starCountFunction), levels(1);

    while (levels * (levels + 1) / 2 <= starCountFunction){
        levels++;
    }
    levels--;

    for (int level = 1; level <= levels; level++){
        for (int spaces = 1; spaces <= level; spaces++){
            cout << " ";
        }

        for (int stars = levels; stars >= 2 * level - 1 && remainingStars > 0; stars--){
            cout << "*";
            remainingStars--;
        }

        cout << endl;
    }
}
