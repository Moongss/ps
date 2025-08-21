#include <iostream>

int x[1001];
int y[1001];

int main() {
    for (int i = 0; i < 3; i++) {
        int a, b;
        std::cin >> a >> b;
        x[a]++;
        y[b]++;
    }

    for (int i = 0; i <= 1000; i++) {
        if (x[i] == 1)
            std::cout << i << " ";
    }
    for (int i = 0; i <= 1000; i++) {
        if (y[i] == 1)
            std::cout << i << std::endl;
    }
    return 0;
}