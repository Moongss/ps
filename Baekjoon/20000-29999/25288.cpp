#include <iostream>
#include <string>

int main() {
    int N;
    std::string str;

    std::cin >> N;
    std::cin >> str;

    for (int i = 0; i < N; i++) {
        std::cout << str;
    }
    std::cout << std::endl;
    return 0;
}