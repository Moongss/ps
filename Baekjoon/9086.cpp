#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        std::string str;
        std::cin >> str;

        std::cout << str[0] << str[str.length()-1] << std::endl;
    }
    return 0;
}