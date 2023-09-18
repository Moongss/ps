#include <iostream>

int main() {
    int N, D;
    char arr[10][10];
    std::cin >> N >> D;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (D == 1) {
                if (arr[i][j] == 'b') std::cout << 'p';
                if (arr[i][j] == 'd') std::cout << 'q';
                if (arr[i][j] == 'q') std::cout << 'd';
                if (arr[i][j] == 'p') std::cout << 'b';
            } else {
                if (arr[i][j] == 'b') std::cout << 'd';
                if (arr[i][j] == 'd') std::cout << 'b';
                if (arr[i][j] == 'q') std::cout << 'p';
                if (arr[i][j] == 'p') std::cout << 'q';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}