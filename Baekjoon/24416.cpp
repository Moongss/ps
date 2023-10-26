#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

ll code1 = 0;
ll code2 = 0;
ll fib(int n) {
    if (n <= 2) {
        code1++;
        return 1;
    }
    return (fib(n - 1) + fib(n - 2));
}

int f[40];
ll fibonacci(int n) {
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        code2++;
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    fastio;
    int N; cin >> N;
    fib(N); fibonacci(N);
    cout << code1 << " " << code2 << endl;
    return 0;
}