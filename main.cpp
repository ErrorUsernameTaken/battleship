#include <iostream>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 15;
int ships = 12;
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
        int shipX = rand() % 12;
        int shipY = rand() % 12;
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
    makeGrid();
    showGrid();
    /*
    cout << "---------------------------" << endl;
    setShips();
    showGrid();
    attack(1, 1);
    cout << "There are " << shipNum() << " ships left." << endl;
    */
    return 0;
}

