#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    
    string a; cin >> a;

    auto plus = a.find('+');
    if (plus == string::npos) {
        cout << "No Money" << endl;
        return 0;
    }
    int cnt = 0;
    for (auto &c : a) {
        if (c == '+') cnt++;
    }
    if (cnt != 1) {
        cout << "No Money" << endl;
        return 0;
    }
    string left = a.substr(0, plus);
    string right = a.substr(plus+1, a.size()-plus-1);

    if (left.length() == 0 || right.length() == 0) {
        cout << "No Money" << endl;
        return 0;
    }
    for (auto &c : left) {
        if (isalpha(c)) {
            cout << "No Money" << endl;
            return 0;
        }
    }
    for (auto &c : right) {
        if (isalpha(c)) {
            cout << "No Money" << endl;
            return 0;
        }
    }

    if (left != right || stoi(left) > 1000 || stoi(right) > 1000 ||
        stoi(left) <= 0 || stoi(right) <= 0) {
        cout << "No Money" << endl;
        return 0;
    }
    cout << "CUTE" << endl;
    return 0;
}