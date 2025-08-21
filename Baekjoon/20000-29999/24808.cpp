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

struct Desc {
    int d, k;
    char type;

    Desc(int d, char type, int k) : d(d), k(k), type(type) {}
    bool operator < (const Desc &a) const {
        return d < a.d;
    }
};

struct cmp {

    // S -> R순서로 가되, d가 작은게 먼저 나와야함.
    // 그러나, d가 같다면 k가 짧은게 먼저 나와야 함. 근데 이거 지문 잘못읽음 아 
    // pq니까 조건 반대로 (커야 우선순위가 높다 -> 작은게 먼저 나옴)
    bool operator() (const Desc &a, const Desc &b) {
        if (a.type == b.type) {
            if (a.d == b.d) return a.k > b.k;
            return a.d > b.d;
        } else {
            return a.type != 'S';
        }
    }
};


vector<Desc> v;
priority_queue<Desc, vector<Desc>, cmp> pq;
multiset<int> wq;

ll o, r;
ll ocnt, rcnt;
int N, T;
int main() {
    fastio;
    
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        int d; char c; int k; cin >> d >> c >> k;
        v.push_back({d, c, k});
        
        if (c == 'S') ocnt++;
        else rcnt++;
    }

    int i = 0;
    ll time= 1;
    while (wq.size() < T && i < v.size()) {
        if (v[i].type == 'S') o += v[i].k; // in-store 여유있게 드감 처음엔.
        else r += v[i].k; // remote

        // cout << "store : " << o << " remote : " << r << endl;
        // 작은거부터 끝나게
        wq.insert(-(v[i].d + v[i].k));
        i++;
    }

    while (i < v.size()) {
        if (wq.size() == T) {
            time = -*wq.begin(); wq.erase(wq.begin());
            // cout << "time : " << time << endl;

            for (; i < v.size(); i++) {
                if (v[i].d <= time) {
                    // pq push
                    pq.push(v[i]);
                    // cout << "pq : " << v[i].d << " " << v[i].type << " " << v[i].k << endl;
                } 
                else break;
            }
        } else {
            while (wq.size() < T && !pq.empty()) {
                Desc cur = pq.top(); pq.pop();

                // cout << "nxt : " << cur.d << " " << cur.type << " " << cur.k << endl;
                if (cur.type == 'S') o += abs(time - cur.d) + cur.k; // in-store
                else r += abs(time - cur.d) + cur.k; // remote
                wq.insert(-(cur.k + time));
            }
        }
    }

    while (!pq.empty()) {
        if (!wq.empty()) {
            time = -*wq.begin(); wq.erase(wq.begin());
        }

        Desc cur = pq.top(); pq.pop();

        // cout << "nxt : " << cur.d << " " << cur.type << " " << cur.k << endl;
        if (cur.type == 'S') o += abs(time - cur.d) + cur.k; // in-store
        else r += abs(time - cur.d) + cur.k; // remote
        wq.insert(-(cur.k + time));
    }
    // cout << "store : " << o << " remote : " << r << endl;

    cout << fixed << setprecision(6) << (ld)o / ocnt << " " << (ld)r / rcnt << endl;
    return 0;
}