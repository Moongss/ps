#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N, M;
std::vector<int> v[10001];

int solve(int N) {
    std::queue<int> q;
    bool visit[10001] = {false, };

    int cnt = 0;
    q.push(N);
    visit[N] = true;
    while (!q.empty()) {
        int elem = q.front();
        q.pop();

        cnt++;
        for (int i = 0; i < v[elem].size(); i++) {
            if (visit[v[elem][i]])
                continue;
            visit[v[elem][i]] = true;
            q.push(v[elem][i]);
        }
    }
    return cnt;
}

int main() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        std::cin >> s >> e;
        v[e].push_back(s);
    }

    std::vector<int> result;
    int max = -1;
    for (int i = 1; i <= N; i++) {
        int tmp = solve(i);
        if (tmp > max) {
            max = tmp;
            result.clear();
            result.push_back(i);
        } else if (tmp == max) {
            result.push_back(i);
        }
    }

    std::sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}