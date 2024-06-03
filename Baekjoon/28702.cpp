#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll inf = (1LL << 63) - 1;

int main() {
    fastio;
    
    int num;
    int idx = 0;
    for (int i = 0; i < 3; i++) {
        string str; cin >> str;
        if (str[0] >= '0' && str[0] <= '9') {
            num = stoi(str);
            idx = i;
        }
    }

    for (int i = idx; i < 3; i++) {
        num += 1;
    }

    if (num % 3 == 0 && num % 5 == 0) {
        cout << "FizzBuzz" << endl;
    } else if (num % 3 == 0) {
        cout << "Fizz" << endl;
    } else if (num % 5 == 0) {
        cout << "Buzz" << endl;
    } else {
        cout << num << endl;
    }
    return 0;
}