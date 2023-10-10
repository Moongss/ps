#include <iostream>
#include <string>

int N;
std::string str;

int main() {
    std::cin >> N >> str;
    std::cout << str.substr(N - 5, 5) << std::endl;

    return 0;
}