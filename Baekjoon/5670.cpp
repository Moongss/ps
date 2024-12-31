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

struct Trie {
    map<char, Trie *> nxt;
    bool end = 0;
    int words = 0;

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (nxt[i]) delete nxt[i];
        }
    }

    void insert(string s) { 
        Trie *cur = this;
        for (auto c : s) {
            cur->words++;
            if (!cur->nxt[c]) {
                cur->nxt[c] = new Trie();
            }
            cur = cur->nxt[c];
        }
        cur->end = true;
    }   

    ll find(bool isRoot) {
        ll result = 0;
        if (isRoot || nxt.size() > 1 || end && nxt.size() == 1) result += words;

        for (auto [k, v]: nxt) {
            result += v->find(false);
        }
        return result;
    }
};

int main() {
    fastio;

    int T;
    while (cin >> T) {
        Trie *t = new Trie();

        for (int i = 0; i < T; i++) {
            string s; cin >> s;
            t->insert(s);
        }

        int sum = t->find(true);
        ld result = (sum * 1.0) / T;
        cout << fixed << setprecision(2) << result << endl;
        delete t;
    }
    
    return 0;
}