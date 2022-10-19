#include <stdbool.h>

bool checkXMatrix(int** grid, int gridSize, int* gridColSize){
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            // check diagonals
            if (j == i || j == gridSize - i - 1) {
                if (grid[i][j] == 0)
                    return false;
            } else if (grid[i][j] != 0)
                return false;
        }
    }
    return true;
}