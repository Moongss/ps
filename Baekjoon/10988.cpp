#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            std::cout << 0 << std::endl;
            return 0;
        }
        start++;
        end--;
    }
    std::cout << 1 << std::endl;
    return 0;
}