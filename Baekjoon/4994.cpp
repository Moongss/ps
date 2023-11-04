#include <bits/stdc++.h>

#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

void solve(int N, ll cur) {
    queue<ll> q;
    q.push(cur);
    while (!q.empty()) {
        ll elem = q.front();
        q.pop();

        if (elem > N && elem % N == 0) {
            cout << elem << endl;
            break;
        }
        q.push(elem * 10);
        q.push(elem * 10 + 1);
    }
}

int main() {
    fastio;
    int N;

    while (true) {
        cin >> N;
        if (N == 0) break;
        else solve(N, 1);
    }
    return 0;
}