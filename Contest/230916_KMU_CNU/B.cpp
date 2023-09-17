#include <iostream>

int main() {
    int cnt = 0;

    int N, s;
    std::cin >> N;

    int result = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> s;
        if (s != 0) {
            cnt++;
        } else {
            result = (cnt > result) ? cnt : result;
            cnt = 0;
        }
    }
    result = (cnt > result) ? cnt : result;
    std::cout << result << std::endl;
    return 0;
}