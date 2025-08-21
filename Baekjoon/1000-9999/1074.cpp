#include <iostream>
#include <cmath>

int solve(int level, int row, int col) {
    int MedianIndexByLevel = pow(2, level - 1);
    if (level == 1)
        return (row * 2 + col);
    
    int visitCountOfLevel = 0;
    if (row < MedianIndexByLevel && col >= MedianIndexByLevel)
        visitCountOfLevel = pow(2, 2 * level - 2);
    if (row >= MedianIndexByLevel && col < MedianIndexByLevel)
        visitCountOfLevel = 2 * pow(2, 2 * level - 2);
    if (row >= MedianIndexByLevel && col >= MedianIndexByLevel)
        visitCountOfLevel = 3 * pow(2, 2 * level - 2);

    row = (row - MedianIndexByLevel >= 0) ? row - MedianIndexByLevel : row;
    col = (col - MedianIndexByLevel >= 0) ? col - MedianIndexByLevel : col;

    return visitCountOfLevel + solve(level - 1, row, col );

}
int main(void) {
    int N, r, c;

    std::cin >> N >> r >> c;
    std::cout << solve(N, r, c) << std::endl;
    return 0;
}