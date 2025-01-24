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
    map<char, Trie *> go;
    Trie *fail;
    bool isEnd;

    ~Trie() {
        for (auto [k, v]: go) {
            delete v;
        }
    }

    void insert(string s) {
        Trie *cur = this;
        for (auto &c : s) {
            if (!cur->go[c]) {
                cur->go[c] = new Trie();
            }
            cur = cur->go[c];
        }
        cur->isEnd = true;
    }
};

void fail(Trie *t) {
    queue<Trie *>q;
    q.push(t);

    t->fail = t; // root
    while (!q.empty()) {
        Trie *cur = q.front(); q.pop();

        for (auto [c, nxt]: cur->go) {
            if (!nxt) continue;
            
            if (cur == t) {
                nxt->fail = cur;
            } else {
                Trie *dest = cur->fail;
                while (dest->fail != dest && dest->go.find(c) == dest->go.end()) {
                    dest = dest->fail;
                }

                if (dest->go.find(c) != dest->go.end()) dest = dest->go[c];
                nxt->fail = dest;
            }

            if (nxt->fail->isEnd) nxt->isEnd = true;
            q.push(nxt);
        }
    }
}

int main() {
    fastio;
    
    int N, M; cin >> N;
    Trie *root = new Trie();
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        root->insert(s);
    }

    fail(root);
    cin >> M;
    for (int i = 0; i < M; i++) {
        string s; cin >> s;

        bool f = false;
        Trie *cur = root;
        int cnt = 0;
        for (auto &c : s) {
            while (cur->fail != cur && cur->go.find(c) == cur->go.end()) {
                cur = cur->fail;
            }

            if (cur->go.find(c) != cur->go.end()) cur = cur->go[c];
            if (cur->isEnd) {
                cnt++;
                f = true;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    
    return 0;
}