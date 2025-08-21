#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    while (a + b <= c)
        c--;
    while (a + c <= b)
        b--;
    while (b + c <= a)
        a--;
    std::cout << a + b + c << std::endl;
    return 0;
}