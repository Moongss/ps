#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v;
    int N;

    std::cin >> N;
    while (N) {
        v.push_back(N % 10);
        N /= 10;
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    
    for (auto i : v) {
        std::cout << i;
    }
    std::cout << std::endl;
    return 0;
}