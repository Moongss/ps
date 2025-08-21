#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using ull = unsigned long long int;

ull N, K;
ull len;

void hanoi(int src, int dst, ull target) {
    while (N) {
        len = 1ULL << (N - 1);
        int mid = 6 - src - dst;
        if (target < len) {N--; dst = mid;}
        else if (target == len) {cout << src << " " << dst << endl; break;}
        else if (target > len) {N--; src = mid; target -= len;}
    }
}

int main() {
    cin >> N >> K;
    hanoi(1, 3, K);
    return 0;
}