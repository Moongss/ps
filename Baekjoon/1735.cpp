#include <bits/stdc++.h>
#define endl "\n"

using ll = long long;
using namespace std;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll numerator = b * c + a * d;
    ll denominator = b * d;
    cout << numerator / gcd(numerator, denominator) << " " 
         << denominator / gcd(numerator, denominator) << endl;
    return 0;
}