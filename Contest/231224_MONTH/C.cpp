#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

struct Company {
    ll groupID;
    string name;
    ll price;
    ll stock;
};

Company cv[102];
int main() {
    fastio;
    
    ll N, M, Q; cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        int G, P; string H;
        cin >> G >> H >> P;
        cv[i].groupID = G;
        cv[i].name = H;
        cv[i].price = P;
        cv[i].stock = 0;
    }
    while (Q--) {
        int q; cin >> q;
        if (M < 0) M = 0;
        if (q == 1) {
            string A; ll B; cin >> A >> B;
            for (auto &elem : cv) {
                if (elem.name == A) {
                    if (M >= B * elem.price) {
                        elem.stock += B;
                        M -= B * elem.price;
                        break;
                    }
                }
            }
        } else if (q == 2) {
            string A; ll B; cin >> A >> B;
            for (auto &elem : cv) {
                if (elem.name == A) {
                    ll sell = min(elem.stock, B);
                    elem.stock -= sell;
                    M += sell * elem.price;
                    break;
                }
            }
        } else if (q == 3) {
            string A; ll C; cin >> A >> C;
            for (auto &elem : cv) {
                if (elem.name == A) {
                    elem.price += C;
                    break;
                }
            }
        } else if (q == 4) {
            ll D, C; cin >> D >> C;
            for (auto &elem : cv) {
                if (elem.groupID == D) elem.price += C;
            }
        } else if (q == 5) {
            ll D, E; cin >> D >> E;
            for (auto &elem : cv) {
                if (elem.groupID == D) {
                    elem.price = (100 + E) * elem.price / 100;
                    elem.price /= 10;
                    elem.price *= 10;
                }
            }
        } else if (q == 6) {
            cout << M << endl;
        } else if (q == 7) {
            ll total = M;
            for (auto &elem : cv) {
                total += elem.stock * elem.price;
            }
            cout << total << endl;
        }
    }
    
    return 0;
}