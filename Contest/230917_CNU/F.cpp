#include <iostream>

int N, M;
int start[200001] = {0, };

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k, s, e;
        std::cin >> k >> s >> e;
        if (start[k] <= s) {
            std::cout << "YES\n";
            start[k] = e;
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}