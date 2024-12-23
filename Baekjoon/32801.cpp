#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int A, B; cin >> A >> B;
    int a, b, c;
    a = b = c = 0;
    for (int i = 1;i <= N; i++) {
        if (i % A == 0 && i % B == 0) c++;
        else if (i % A == 0) a++;
        else if (i % B == 0) b++;
    }
    cout << a << " " << b << " " << c << endl;
}