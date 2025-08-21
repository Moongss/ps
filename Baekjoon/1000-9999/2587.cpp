#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v;

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int tmp; std::cin >> tmp;
        sum += tmp;
        v.push_back(tmp);
    }

    std::sort(v.begin(), v.end());
    std::cout << sum / 5 << std::endl << v[2] << std::endl;
    return 0;
}