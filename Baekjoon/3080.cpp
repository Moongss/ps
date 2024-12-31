#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define lower(v, x) (int)(lower_bound(all(v), x) - v.begin())
#define upper(v, x) (int)(upper_bound(all(v), x) - v.begin())

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_mset tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
ll fact[28];
string in;
ll MOD = 1e9 + 7;

void init() {
    fact[0] = 1;
    for (ll i = 1; i <= 27; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
}

struct Trie {
    vector<pair<char, Trie *>> vv;
    bool end;

    Trie() {
        end = false;
        vv.clear();
    }

    ~Trie() {
        for (auto [k, v] : vv) {
            delete v;
        }
    }

    void insert(string s) {
        Trie *cur = this;
        for (char &c : s) {
            Trie *next = NULL;
            for (auto [k, v]: cur->vv) {
                if (k == c) {
                    next = v; break;
                }
            }
            if (!next) {
                next = new Trie();
                cur->vv.push_back({c, next});
            }
            cur = next;
        }
        cur->end = true;
    }

    ll query() {
        ll ret = fact[vv.size() + (end ? 1 : 0)];
        for (auto [k, v]: vv) {
            ret *= v->query() % MOD;
            ret %= MOD;
        }
        return ret % MOD;
    }
};

int main() {
    fastio;
    
    init();
    cin >> N;

    Trie *root = new Trie();
    for (int i = 0; i < N; i++) {
        cin >> in;
        root->insert(in);
    }
    cout << root->query() << endl;

    delete root;
    return 0;
}