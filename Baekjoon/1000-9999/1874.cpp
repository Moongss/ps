#include <iostream>
#include <stack>
#include <string>

int main() {
    int N, target;
    int cnt = 0;
    std::stack<int> numStack;
    std::string operationLog;

    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> target;

        if (numStack.empty()) {
            numStack.push(++cnt);
            operationLog += "+";
        }

        while (!numStack.empty() && cnt <= N && numStack.top() != target) {
            numStack.push(++cnt);
            operationLog += "+";
        }

        while (!numStack.empty() && cnt <= N && numStack.top() == target) {
            numStack.pop();
            operationLog += "-";
        }
    }

    if (!numStack.empty()) {
        std::cout << "NO\n";
    }
    else {
        for (int i = 0; i < operationLog.length(); i++) {
            std::cout << operationLog[i] << "\n";
        }
    }
    return 0;
}