#include <iostream>
#include <queue>
#include <vector>

using ll = long long;

int N, M;
int A, B, S, E;
std::vector<std::pair<ll, ll> > C[10001];

bool bfs(ll mid) {
    bool visit[10001] = {0, };
    visit[S] = true;

    std::queue<int> q;
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == E)
            return true;

        for (auto elem : C[cur]) {
            if (visit[elem.first] || elem.second < mid)
                continue;
            visit[elem.first] = true;
            q.push(elem.first);
        }
    }
    return false;
}
int main() {
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> A >> B;

        ll tmp;
        std::cin >> tmp;

        C[A].push_back(std::make_pair(B, tmp));
        C[B].push_back(std::make_pair(A, tmp));
    }

    ll lo = 1;
    ll hi = 1e+9 + 1;
    std::cin >> S >> E;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        bool isPossible = bfs(mid);

        if (!isPossible) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << lo << std::endl;
    return 0;
}