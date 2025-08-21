#include <iostream>

int main() {
    int max = -1;
    int num;
    std::pair<int, int> coord;

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            std::cin >> num;
            if (max < num) {
                coord = std::make_pair(i, j);
                max = num;
            }
        }
    }
    std::cout << max << std::endl;
    std::cout << coord.first << " " << coord.second << std::endl;
    return 0;
}