#include <iostream>
#include <string>

std::string decodeStr;
std::string encodeStr;

int main() {
    std::cin >> decodeStr >> encodeStr;

    int cnt = 0;
    int decodeIdx = 0;
    int encodeIdx = 0;
    while (encodeIdx < encodeStr.length()) {
        if (decodeStr[decodeIdx] == encodeStr[encodeIdx]) {
            decodeIdx++;
            encodeIdx++;
        } else {
            encodeIdx++;
        }

        if (decodeIdx == decodeStr.length()) {
            cnt++;
            decodeIdx = 0;
        }
    }

    std::cout << cnt << std::endl;
    return 0;
}