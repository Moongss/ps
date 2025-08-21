#include <iostream>
#include <algorithm>
#include <vector>

int N;
int cnt[1001] = {0, };
std::vector<int> v;

int main() {
    int sum = 0;
    int max = -1;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        std::cin >> tmp;
        v.push_back(tmp);

        sum += tmp;
        cnt[tmp]++;
    }

    for (int i = 1; i <= N; i++) {
        max = std::max(max, cnt[i] * i);
    }
    std::cout << sum + max << std::endl;

    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    return 0;    
}