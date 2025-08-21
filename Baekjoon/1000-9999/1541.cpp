#include <iostream>
#include <string>

int main() {
    std::string input;
    int numList[26] = {0,};
    char operList[26] = {0, };

    operList[0] = '+';
    std::cin >> input;

    int numIdx = 0;
    int operIdx = 1;
    int minusStartIdx = 51;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '-' || input[i] == '+') {
            if (input[i] == '-' && minusStartIdx == 51) minusStartIdx = operIdx;
            operList[operIdx] = input[i];
            numIdx++;
            operIdx++;
        }
        else
            numList[numIdx] = numList[numIdx] * 10 + (input[i] - '0');
    }

    for (int i = minusStartIdx; i <= numIdx; i++) {
        if (operList[i] == '-')
            continue;
        operList[i] = '-';
    }

    int sum = 0;
    for (int i = 0; i <= numIdx; i++) {
        if (operList[i] == '-') sum -= numList[i];
        else sum += numList[i];
    }

    std::cout << sum << std::endl;
    return 0;

}