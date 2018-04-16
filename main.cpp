#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 15;
int ships = 10;
int grid[rows][elements];

void makeGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            grid[i][j] = 0;
        }
    }
}

void showGrid() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int shipNum() {
    int h = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            if (grid[i][j] == 1) {
                h++;
            }
        }
    }
    return h;
}

void setShips() {
    int s = 0;
    while(s < ships) {
        int shipX = rand() % 10;
        int shipY = rand() % 10;
        if(grid[shipX][shipY] != 1) {
            s++;
            grid[shipX][shipY] = 1;
        }
    }
}

bool attack(int shipX, int shipY) {
    if (grid[shipX][shipY] == 1) {
        grid[shipX][shipY] = 2;
        return true;
    } else {
        return false;
    }
}

int main() {
    srand(time(NULL));
    makeGrid();
    setShips();
    int pos1, pos2;
    char giveUp;
    while (1) {
        cout << "Input the X location of your target. "; cin >> pos1 ;
        cout << "Input the Y location of your target. "; cin >> pos2;
        if (attack(pos1, pos2)) {
            cout << "You sunk a battleship." << endl;
        } else {
            cout << "Try again." << endl;
            cout << "There are " << shipNum() << " ships left." << endl;
            cout << "Do you wish to give up? (y/n)"; cin >> giveUp;
            if (giveUp == 'y') {
                break;
            }
        }
    }
    cout << "You have chosen to give up." << endl;
    cout << endl;
    showGrid();
    cout << endl;
    cout << "0 = Grid Spaces" << endl;
    cout << "1 = Ships" << endl;
    cout << "2 = Ships Sunk" << endl;
    return 0;
}
