#include <iostream>

using ll = long long;

ll propagate[5000000];
ll num[1000001];
int N;

ll find(int target, int s, int e, int node) {
    if (s > target || e < target)
        return 0;
    if (s == e && s == target)
        return propagate[node];
    int mid = (s + e) / 2;
    return propagate[node] + 
           find(target, s, mid, node * 2) + 
           find(target, mid + 1, e, node * 2 + 1);
}

void update(int l, int r, int s, int e, int k, int node) {
    if (e < l || r < s) return;
    if (l <= s && e <= r) {
        propagate[node] += k;
        // std::cout << "node : " << node << std::endl;
        return;
    }

    int mid = (s + e) / 2;
    update(l, r, s, mid, k, node * 2);
    update(l, r, mid + 1, e, k, node * 2 + 1);
}

int main() {
    std::cin.tie(0)->sync_with_stdio(false);
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> num[i];
    }

    int M;
    std::cin >> M;
    while (M--) {
        int q, i, j, k, x;
        std::cin >> q;
        if (q == 1) {
            std::cin >> i >> j >> k;
            update(i, j, 1, N, k, 1);
        } else {
            std::cin >> x;
            std::cout << num[x] + find(x, 1, N, 1) << "\n";
        }
    }

    return 0;
}