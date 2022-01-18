#include <iostream>
#include <iomanip>
const int maksymalna_wielkosc_trojkata = 50;
using namespace std;
int main() {
    int wielkosc_trojkata = 0;
    cout << "Podaj wielkosc trojkata : ";
    cout << endl;
    if(wielkosc_trojkata > maksymalna_wielkosc_trojkata) {
        cout << "Trojkat nie moze byc wiekszy niz: " << maksymalna_wielkosc_trojkata;
        cout << endl;
    }
    cin >> wielkosc_trojkata;
    int trojkat[maksymalna_wielkosc_trojkata][maksymalna_wielkosc_trojkata];
    cout << endl;
    int pole_w_trojkacie = 0;
    for (int w = 0; w < wielkosc_trojkata; w++) {
        for (int k = 0; k < pole_w_trojkacie + 1; k++) {
            if (k == 0 || k == pole_w_trojkacie) {
                trojkat[w][k] = 1;
            } else {
                trojkat[w][k] = trojkat[w - 1][k - 1] + trojkat[w - 1][k];
            }
        }
        pole_w_trojkacie++;
    }
    int odstepy;
    pole_w_trojkacie = 0;
    odstepy = wielkosc_trojkata - 1;
    for (int i = 0; i < wielkosc_trojkata; i++) {
        for (int j = 0; j < odstepy; j++) {
            cout << "     ";
        } for (int l = 0; l < pole_w_trojkacie + 1; l++) {
            cout << setw(5) << trojkat[i][l] << "     ";
        }
        odstepy--;
        cout << endl;
        pole_w_trojkacie++;
    }
    return 0;
}
