#include <iostream>
#include <string>

std::string str;
int main() {
    std::cin >> str;

    int sum = 0;
    for (auto ch : str) {
        if ('A' <= ch && ch <='C')
            sum += 3;
        else if ('D' <= ch && ch <= 'F')
            sum += 4;
        else if ('G' <= ch && ch <= 'I')
            sum += 5;
        else if ('J' <= ch && ch <= 'L')
            sum += 6;
        else if ('M' <= ch && ch <= 'O')
            sum += 7;
        else if ('P' <= ch && ch <= 'S')
            sum += 8;
        else if ('T' <= ch && ch <= 'V')
            sum += 9;
        else if ('W' <= ch && ch <= 'Z')
            sum += 10;
    }

    std::cout << sum << std::endl;
    return 0;
}