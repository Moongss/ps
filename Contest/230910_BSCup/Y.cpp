#include <iostream>
#include <string>

int main() {
    std::string str;

    char ch;
    int result = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            std::cin >> ch;
            if (ch == 'K') result += 0;
            if (ch == 'P') result += 1;
            if (ch == 'N') result += 3;
            if (ch == 'B') result += 3;
            if (ch == 'R') result += 5;
            if (ch == 'Q') result += 9;
            if (ch == 'k') result -= 0;
            if (ch == 'p') result -= 1;
            if (ch == 'n') result -= 3;
            if (ch == 'b') result -= 3;
            if (ch == 'r') result -= 5;
            if (ch == 'q') result -= 9;
        }
    }
    
    std::cout << result << std::endl;
    return 0;
}