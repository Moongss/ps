#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define A 0
#define C 1
#define G 2
#define T 3

int S, P;
string s;
int cnt[4]; //A C G T;
int minCnt[4];

bool isValidPassword() {
    for (int i = 0; i < 4; i++) {
        if (cnt[i] < minCnt[i])
            return false;
    }
    return true;
}

int main() {
    fastio;
    
    cin >> S >> P;
    cin >> s;
    cin >> minCnt[A] >> minCnt[C] >> minCnt[G] >> minCnt[T];

    for (int i = 0; i < P; i++) {
        if (s[i] == 'A') cnt[A]++;
        if (s[i] == 'C') cnt[C]++;
        if (s[i] == 'G') cnt[G]++;
        if (s[i] == 'T') cnt[T]++;
    }

    int result = 0;
    for (int i = 0; i < S - P; i++) {
        if (isValidPassword()) result++;
        if (s[i] == 'A') cnt[A]--;
        if (s[i] == 'C') cnt[C]--;
        if (s[i] == 'G') cnt[G]--;
        if (s[i] == 'T') cnt[T]--;

        if (s[i + P] == 'A') cnt[A]++;
        if (s[i + P] == 'C') cnt[C]++;
        if (s[i + P] == 'G') cnt[G]++;
        if (s[i + P] == 'T') cnt[T]++;
    }
    if (isValidPassword()) result++;
    cout << result << endl;
    return 0;
}