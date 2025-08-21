#include <iostream>

int main() {
    int S, N, M;

    std::cin >> S >> N >> M;
    int tmp = 0;
    for (int i = 0; i < N + M; i++) {
        int command;

        std::cin >> command;
        if (command == 1) {
            if (tmp == S) {
                S *= 2;
            } else {
                tmp++;
            }
        } else {
            tmp--; 
        }
    }

    std::cout << S << std::endl;
    return 0;
}