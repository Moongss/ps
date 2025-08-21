#include <bits/stdc++.h>
#define endl "\n"

using ll = long long;
using namespace std;

vector<ll> v;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }

    ll distance = gcd(v[2] - v[1], v[1] - v[0]);
    for (int i = 3; i < v.size(); i++) {
        distance = gcd(distance, v[i] - v[i - 1]);
    }

    int cnt = 0;
    for (int i = v.front(); i <= v.back(); i += distance) {
        cnt++;
    }

    cout << cnt - v.size() << endl;
    return 0;
}