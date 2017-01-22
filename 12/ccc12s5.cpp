#include <iostream>
#include <cstring>

using namespace std;

int main (void) {
    int rows, cols, r, c, catNum;
    cin >> rows >> cols >> catNum;
    
    int cages[rows][cols];
    bool cats[rows][cols];
    memset(cages, 0, sizeof(cages[0][0]) * rows * cols);
    memset(cats, 0, sizeof(cats[0][0]) * rows * cols);
    
    for (int i = 0; i < catNum; i++) {
        cin >> r >> c;
        cats[r-1][c-1] = 1;
    }
    
    cages[0][0] = 1;
    for (int i = 1; i < rows; i++) {
        if (!cats[i][0])
            cages[i][0] = cages[i-1][0];
    }
    for (int j = 1; j < cols; j++) {
        if (!cats[0][j])
            cages[0][j] = cages[0][j-1];
    }
    
    for (int j = 1; j < cols; j++) {
        for (int i = 1; i < rows; i++) {
            if (!cats[i][j])
                cages[i][j] = cages[i-1][j] + cages[i][j-1];
        }
    }
    cout << cages[rows-1][cols-1] << endl;
    
    
    return 0;
}
