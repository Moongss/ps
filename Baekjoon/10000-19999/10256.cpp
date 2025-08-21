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
    // map<char, Trie *> go;
    Trie *go[4];
    Trie *fail;
    bool isEnd;

    ~Trie() {
        for (int i = 0; i < 4; i++) {
            if (go[i]) delete go[i];
        }
    }

    void insert(string s) {
        Trie *cur = this;
        for (auto &c : s) {
            if (!cur->go[c-'0']) {
                cur->go[c-'0'] = new Trie();
            }
            cur = cur->go[c-'0'];
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

        for (int i = 0; i < 4; i++) {
            if (!cur->go[i]) continue;

            Trie *nxt = cur->go[i];
            if (cur == t) nxt->fail = cur;
            else {
                Trie *dest = cur->fail;
                while (dest->fail != dest && !dest->go[i]) {
                    dest = dest->fail;
                }

                if (dest->go[i]) dest = dest->go[i];
                nxt->fail = dest;
            }

            if (nxt->fail->isEnd) nxt->isEnd = true;
            q.push(nxt);
        }
    }
}

void convert(string &s) {
    for (auto &c : s) {
        if (c == 'A') c = '0';
        if (c == 'G') c = '1';
        if (c == 'T') c = '2';
        if (c == 'C') c = '3';
    }
}

int main() {
    fastio;
    
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        string s, marker; cin >> s >> marker;
        convert(s); convert(marker);

        Trie *root = new Trie();
        root->insert(marker);
        for (int i = 0; i < M - 1; i++) {
            for (int j = 0; j < M-i; j++) {
                string k = marker;
                reverse(k.begin()+i, k.begin()+i+1+j);
                root->insert(k);
            }
        }

        fail(root);

        int cnt = 0;
        bool f = false;
        Trie *cur = root;
        for (auto &c : s) {
            while (cur->fail != cur && !cur->go[c-'0']) {
                cur = cur->fail;
            }

            if (cur->go[c-'0']) cur = cur->go[c-'0'];
            if (cur->isEnd) {
                cnt++;
            }
        }

        cout << cnt << endl;
        delete root;
    }
    return 0;
}