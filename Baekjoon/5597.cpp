#include <iostream>

int main() {
    int arr[31] = { 0, };
    for (int i = 0; i < 28; i++) {
        int tmp;
        std::cin >> tmp;
        arr[tmp]++;
    }

    for (int i = 1; i <= 30; i++) {
        if (arr[i] == 0) {
            std::cout << i << "\n";
        }
    }
    return 0;
}