#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v;
    int N;
    int K;

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int tmp; std::cin >> tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end(), std::greater<int>());
    std::cout << v[K - 1] << std::endl;
    return 0;
}