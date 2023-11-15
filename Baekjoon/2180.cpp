#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
#define DIVISOR 40000

using namespace std;
using ll = long long;
using ld = long double;

struct compare { // condition 반대로
    bool operator()(pair<ll, ll> a, pair<ll, ll> b) { 
        if (b.first == 0 && b.second == 0) return true;
        if (a.second * b.first > b.second * a.first) return true; //b_k / a_k < b_{k+1} / a_{k+1}
        return false;
    }
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compare> pq;

int N;
int main() {
    fastio;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        pq.push({a, b});
    }

    ll t = 0;
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        a %= DIVISOR;
        t %= DIVISOR;
        b %= DIVISOR;
        t = (((a + 1) * t % DIVISOR) + b) % DIVISOR;
    }
    cout << t << endl;
    return 0;
}