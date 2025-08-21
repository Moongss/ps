#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    
    std::cin >> N;
    std::vector<int> v;
    long pre[200001] = {0, };

    v.push_back(0);
    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;
        v.push_back(num);
    }

    std::sort(v.begin(), v.end());
    for (int i = 1; i <= N; i++) {
        pre[i] = pre[i - 1] +  v[i];
    }

    long min = 4242424242;
    int result = 42;      
    for (int i = 1; i <= N; i++) {
        long current = v[i];
        long distance = 0;

        distance += current * (i - 1) - pre[i - 1];
        distance += (pre[N] - pre[i]) - current * (N - i);

        if (distance < min) {
            min = distance;
            result = current;
        }
    }

    std::cout << result << std::endl;
    return 0;
}