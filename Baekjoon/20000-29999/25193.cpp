#include <iostream>
#include <string>

int N;
std::string S;

int main() {
    std::cin >> N;
    std::cin >> S;

    int chickenCnt = 0;
    int otherCnt = 1;
    for (int i = 0; i < N; i++){ 
        if (S[i] == 'C')
            chickenCnt++;
        else
            otherCnt++;
    }

    int result = chickenCnt / otherCnt;
    if (chickenCnt % otherCnt)
        result++;
    std::cout << result << std::endl;
    return 0;
}