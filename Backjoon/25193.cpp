#include <iostream>
#include <string>

int N;
std::string S;

int main() {
    std::cin >> N;
    std::cin >> S;

    int chickenCnt = 0;
    int otherCnt = 1;
    int result[100001] = {0,};
    for (int i = 0; i < N; i++){ 
        if (S[i] == 'C')
            chickenCnt++;
        else
            otherCnt++;
    }

    int tmp = 0;
    while (chickenCnt) {
        tmp %= otherCnt;
        result[tmp]++;
        
        tmp++;
        chickenCnt--;
    }

    std::cout << result[tmp - 1] << std::endl;
    return 0;
}