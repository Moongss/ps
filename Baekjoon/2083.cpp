#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    while (true) {
        string name;
        int age, kg;

        cin >> name >> age >> kg;
        if (name == "#" && age == 0 && kg == 0) break;

        if (age > 17 || kg >= 80) cout << name << " Senior" << endl;
        else cout << name << " Junior" << endl;
    }
    return 0;
}