#include <iostream>
#include <string>

std::string N;
int B;
int sum;

int main() {
    std::cin >> N >> B;

    sum = 0;
    for (auto i : N) {
        if ('0' <= i && i <= '9')
            sum = sum * B + (i - '0');
        else
            sum = sum * B + (i - 'A' + 10);
    }
    std::cout << sum << std::endl;
    return 0;
}