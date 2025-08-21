#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> A;
    std::priority_queue<int, std::vector<int>, std::greater<int> > B;

    int N, tmp;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        A.push(tmp);
    }

    for (int i = 0; i < N; i++) {
        std::cin >> tmp;
        B.push(tmp);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        result += A.top() * B.top();
        A.pop(); B.pop();
    }
    std::cout << result << std::endl;
    return 0;
}