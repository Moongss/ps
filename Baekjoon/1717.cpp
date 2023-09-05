#include <iostream>

int parents[1000001];

int findParent(int x) {
    if (x == parents[x])
        return x;
    return parents[x] = findParent(parents[x]);
}

void Union(int a, int b) {
    int aParent = findParent(a);
    int bParent = findParent(b);
    parents[bParent] = aParent; //ÀÌ°É parents[b] = ~·Î ÇØ¹ö·È´Ù. ¿ÏÀü ³ëµå ²÷¾î¸ÔÀº¼À.
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parents[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int operation;
        int a, b;

        std::cin >> operation;
        std::cin >> a >> b;
        if (operation == 0)
            Union(a, b);
        else {
            if (findParent(a) == findParent(b))
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
    return 0;
}