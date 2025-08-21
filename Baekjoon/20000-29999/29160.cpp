#include <iostream>
#include <queue>
#include <algorithm>

int N, K;
std::priority_queue<int> player[12];

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);

    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int p, w;
        std::cin >> p >> w;
        player[p].push(w);
    }

    for (int i = 0; i < K; i++) {
        for (int j = 1; j <= 11; j++) {
            if (player[j].empty())
                continue;
            if (player[j].top() == 0)
                continue;
            
            int tmp = player[j].top();
            player[j].pop();
            player[j].push(tmp - 1);
        }
    }

    int result = 0;
    for (int i = 1; i <= 11; i++) {
        if (player[i].empty())
            continue;
        result += player[i].top();
    }
    std::cout << result << std::endl;
    return 0;
}