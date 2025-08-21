#include <iostream>
#include <cmath>

//false: space
//true: star
bool arr[3074][6143] = {0, };

void putStar(int i, int j) {
    arr[i][j + 2] = true;
    arr[i + 1][j + 1] = true;
    arr[i + 1][j + 3] = true;
    for (int dx = 0; dx < 5; dx++) {
        arr[i + 2][j + dx] = true;
    }
}

void printResult(int k) {
    int rowMax = 3 * std::pow(2, k);
    int colMax = 6 * std::pow(2, k) - 1;
    for (int i = 0; i < rowMax; i++) {
        for (int j = 0; j < colMax; j++) {
            if (arr[i][j])
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << "\n";
    }
}

void solve(int row, int col, int k) {
    if (k == 0)
        return;
    
    col += 3 * std::pow(2, k - 1);
    if (k == 1)
        putStar(row, col);
    else
        solve(row, col, k - 1);

    row += 3 * std::pow(2, k - 1);
    col -= 3 * std::pow(2, k - 1);
    if (k == 1)
        putStar(row, col);
    else
        solve(row, col, k - 1);

    col += 3 * std::pow(2, k);
    if (k == 1)
        putStar(row, col);
    else
        solve(row, col, k - 1);
}

int main() {

    int N;
    int k;

    std::cin >> N;
    N /= 3;

    k = 0;
    while (N > 1) {
        N /= 2;
        k++;
    }

    if (k == 0)
        putStar(0, 0);
    else
        solve(0, 0, k);
    printResult(k);
    return 0;
}