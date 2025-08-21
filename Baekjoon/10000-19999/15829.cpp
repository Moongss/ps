#include <iostream>
#define M 1234567891

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(NULL);
    // std::cout.tie(NULL);

    char ch;
    int length, a;
    unsigned long long r = 1;
    unsigned long long sum = 0;

    std::cin >> length;
    for (int i = 0; i < length; i++) {
        std::cin >> ch;
        a = (ch - 'a' + 1) % M;
        if (i != 0) r = (r * 31);
        r = r % M;
        sum = sum + (a * r) % M;
    }
    sum %= M;
    std::cout << sum << std::endl;
    return 0;
}