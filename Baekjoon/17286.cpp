#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

pair<int, int> a, b, c, d;

double getDistance(pair<int, int> a, pair<int, int> b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return (sqrt(x * x + y * y));
}

int main() {
    fastio;
    
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;
    cin >> d.first >> d.second;

    double result = 424242;

    result = min(result, getDistance(a, b) + getDistance(b, c) + getDistance(c, d));
    result = min(result, getDistance(a, b) + getDistance(b, d) + getDistance(c, d));
    result = min(result, getDistance(a, c) + getDistance(c, b) + getDistance(b, d));
    result = min(result, getDistance(a, c) + getDistance(c, d) + getDistance(d, b));
    result = min(result, getDistance(a, d) + getDistance(d, c) + getDistance(c, b));
    result = min(result, getDistance(a, d) + getDistance(b, d) + getDistance(b, c));

    cout << (int)result << endl;
    return 0;
}