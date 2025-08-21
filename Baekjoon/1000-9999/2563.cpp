#include <iostream>

int arr[101][101];

int main() {
    int T;
    std::cin >> T;

    int cnt = 0;
    while (T--) {
        int a, b;
        std::cin >> a >> b;
        for (int i = a; i < a + 10; i++) {
            for (int j = b; j < b + 10; j++) {
                if (!arr[i][j]) {
                    arr[i][j] = 1;
                    cnt++;
                }
            }
        }
    }

    std::cout << cnt << std::endl;
    return 0;
}