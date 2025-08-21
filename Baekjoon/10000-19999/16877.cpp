#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll fibo[33];
bool check[33];
int g[3000001];
int N, P, result = 0;

void getFibo() {
    fibo[0] = fibo[1] = 1;
    for (int i = 2; i <= 32; i++) { //31 : 2178309
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }   
}

void getGrundy() {
    for (int i = 1; i <= 3000000; i++) {
        int j = 1;
        memset(check, 0, sizeof(check));
        while (fibo[j] <= i) {
            check[g[i - fibo[j]]] = true;
            j++;
        }

        j = 0;
        while (check[j]) j++;
        g[i] = j;
    }
}

int main() {
    fastio;
    
    getFibo();
    getGrundy();
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        result ^= g[p];
    }
    
    cout << (result ? "koosaga" : "cubelover") << endl;
    return 0;
}