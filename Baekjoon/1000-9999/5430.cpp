#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <memory.h>

std::deque<int> parseNumList(std::string arr) {
    int tmp = 0;
    std::deque<int> result;

    if (arr.length() == 2)
        return result;

    for (int i = 0; i < arr.length(); i++) {
        if (arr[i] == '[')
            continue;
        if (arr[i] >= '0' && arr[i] <= '9')
            tmp = tmp * 10 + arr[i] - '0';
        else if (arr[i] == ',' || arr[i] == ']') {
            result.push_back(tmp);
            tmp = 0;
        }
    }
    return result;
}

int main() {
    int caseTotal;
    int N;
    char p[100001];
    std::string array;
    std::deque<int> numberList;

    std::cin >> caseTotal;
    for (int i = 0; i < caseTotal; i++) {
        memset(p, 0, sizeof(p));
        std::cin >> p;
        std::cin >> N;
        std::cin >> array;

        numberList = parseNumList(array);
        int start = 0;
        int end = numberList.size() - 1;
        int cnt = 0;
        bool isReverse = false;
        while (p[cnt] != '\0') {
            if (p[cnt] == 'R') {
                isReverse = !isReverse;
            } else {
                if (isReverse)
                    end--;
                else
                    start++;
            }
            cnt++;
        }

        if (start > end + 1)
            std::cout << "error\n";
        else if (start == end + 1)
            std::cout << "[]\n";
        else {
            std::cout << "[";
            if (isReverse) {
                for (int i = end; i >= start; i--) {
                    std::cout << numberList[i];
                    if (i != start)
                        std::cout << ",";
                }
            } else {
                for (int i = start; i <= end; i++) {
                    std::cout << numberList[i];
                    if (i != end)
                        std::cout << ",";
                }
            }
            std::cout << "]\n";
        }
    }
    return 0;
}