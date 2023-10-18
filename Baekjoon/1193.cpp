#include <iostream>

int main() {
    int cnt = 1;
    int sum = 0;
    int N;
    int a, b;

    std::cin >> N;
    while (sum < N) {
        sum += cnt;
        cnt++;
    }
    cnt--;
    a = 1;
    b = cnt;

    int tmp = 0;
    while (sum > N) {
        sum--;
        tmp++;
    }

    a += tmp; b -= tmp;
    if (cnt % 2 == 1)
        std::cout << a << "/" << b << std::endl;
    else
        std::cout << b << "/" << a << std::endl;
    return 0;
}