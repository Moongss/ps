#include <iostream>
#include <string>


std::string str;

int main() {
    std::cin >> str;

    int result = 0;
    if (str.length() >= 4) {
        for (int i = 0; i < str.length()-3; i++) {
            if (str[i] == 'D' && str[i + 1] == 'K' && str[i + 2] == 'S' && str[i + 3] == 'H')
                result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
