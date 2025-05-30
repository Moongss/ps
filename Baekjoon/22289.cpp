#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using cpx = complex<double>;
using vec = vector<cpx>;

ll w = 3;
ll mod = 998244353;

ll PowMod(ll a, ll b, ll mod) {
  ll ret = 1; a = a % mod;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

// 비재귀로.
//재귀도 있음..
void FFT(vec &A, bool inv) {
  int n = A.size();
  if (n == 1) return;
  vector<ll> rev(n, 0);
  for (int i = 0; i < n; i++) {
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
    if (i < rev[i]) swap(A[i], A[rev[i]]);
  }

  for (int i = 2; i <= n; i <<= 1) {
    cpx wp = cpx(cos(2 * M_PI / i), sin(2 * M_PI / i));
    if (inv) wp = cpx(cos(2 * M_PI / i), sin(-2 * M_PI / i));
    for (int j = 0; j < n; j += i) {
      cpx d(1, 0);
      for (int k = 0; k < i/2; k++) {
        cpx x = A[j + k];
        cpx y = A[j + k + i/2] * d;
        A[j + k] = x + y;
        A[j + k + i/2] = x - y;
        d *= wp;
      }
    }
  }

  if (inv) for (int i = 0; i < n; i++) A[i] /= n;
}


vec multiplyFFT(vec &A, vec &B) {
    int n = 1;
    while (n < A.size() + B.size()) n <<= 1;
    A.resize(n); B.resize(n);

    FFT(A, false);
    FFT(B, false);

    for (int i = 0; i < n; i++) {
        A[i] *= B[i];
    }

    FFT(A, true);
    return A;
}


void NTT(vector<ll> &A, bool inv) {
    int n = A.size();
    vector<ll> rev(n, 0);

    // sort 0 4 2 6 1 5 3 7 ...(ex.8)
    //i >> 1을 하면 기존 i의 마지막 비트를 뺀 값을 가져옴.
    // 그 i >> 1에 대한 비트 반전값(rev[i >> 1])이 이미 구해져 있음.
    // rev[i >> 1] >> 1을 하면 새로운 rev[i]의 왼쪽에 한 칸 밀린 상태가 됨.
    // 마지막 비트 i & 1을 확인해서 최상위 비트를 채워줌.
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
        if (i < rev[i]) swap(A[i], A[rev[i]]);
    }

    // w^p-1 = 1 (mod p)
    ll x = PowMod(w, (mod - 1) / n, mod);
    if (inv) x = PowMod(x, mod - 2, mod);

    vector<ll> root; root.push_back(1);
    for (int i = 1; i < n; i++) {
        root.push_back(root[i - 1] * x % mod);
    }

    for (int i = 2; i <= n; i <<= 1) {
        int step = n / i; // step(n = 8) : step 4 -> 2 -> 1
        for (int j = 0; j < n; j += i) {
            // first, i = 2. k = 0 -> [0, 1]
            // secon, i = 4, k = 0, 1 -> [0, 2, 1, 3]
            // third, i = 8, k = 0, 1, 2, 3 -> [0, 4, 2, 6, 1, 5, 3, 7]
            for (int k = 0; k < i / 2; k++) {
                // f(w_k) = A_even * f(w_k^2) + w_k * A_odd * f(w_k^2) 
                // bit로 나타내면 j != k라서, j|k로 비트연산 가능한거 같음.
                // 추가로 i/2도 안겹쳐서 비트연산 됨. 
                // j : i
                // i/2 : i >> 1
                // k : i >> 1보다 작음.

                ll u = A[j + k]; // A_even
                ll v = A[j + k + i / 2] * root[step * k] % mod; //A_odd * root
                A[j + k] = (u + v) % mod;
                A[j + k + i / 2] = (u - v + mod) % mod; //overflow 체크
            }
        }
    }

    ll t = PowMod(n, mod - 2, mod);
    if (inv) for (int i = 0; i < n; i++) A[i] = A[i] * t % mod;
}

vector<ll> multiplyNTT(vector<ll> &A, vector<ll> &B) {
    int n = 1;
    while (n < A.size() + B.size()) n <<= 1;
    A.resize(n); B.resize(n);

    // NTT
    NTT(A, false);
    NTT(B, false);

    for (int i = 0; i < n; i++) {
        A[i] = A[i] * B[i] % mod;
    }

    NTT(A, true);
    return A;
}

int main() {
    fastio;
    
    string A, B; cin >> A >> B;
    vec a, b;
    for (int i = 0; i < A.size(); i++) {
        a.push_back(A[i] - '0');
    }
    for (int i = 0; i < B.size(); i++) {
        b.push_back(B[i] - '0');
    }
    reverse(all(a)); reverse(all(b));
    // vector<ll> ret = multiplyNTT(a, b);
    vec ret = multiplyFFT(a, b);
    vector<ll> ans(ret.size());

    for (int i = 0; i < ret.size(); i++) {
        ans[i] = (ll)round(ret[i].real());
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i < ans.size()) {
            ans[i+1] += ans[i] / 10;
            ans[i] %= 10;
        }
    }

    reverse(all(ans));
    int i = 0; while (i < ans.size() && ans[i] == 0) i++;
    if (i == ans.size()) cout << 0 << endl;
    else while (i < ans.size()) cout << ans[i++];
    cout << endl;

    return 0;
}