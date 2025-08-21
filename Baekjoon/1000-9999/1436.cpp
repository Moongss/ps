#include <iostream>

int main() {
    int N;
    int count = 0;
    int currentValue = 666;
    int tmp;

    std::cin >> N;
    for (currentValue;;currentValue++) {
        tmp = currentValue;
        while (tmp >= 666) {
            if (tmp % 1000 == 666) {
                count++;
                break;
            }
            tmp /= 10;
        }
        if (count == N)
            break;
    }
    std::cout << currentValue;
}