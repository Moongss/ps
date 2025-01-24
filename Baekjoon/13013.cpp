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
string s;
int arr[50];
int ans[50];
int sa[100], pos[100], tmp[100], lcp[100];
int d;

bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i+=d; j+=d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : i > j;
}

void solve() {
    // sa
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }

    d = 1;
    while (d <= N) {
        sort(sa, sa+N, cmp);
        
        memset(tmp, 0, sizeof(tmp));
        for (int i = 0; i < N-1; i++) {
            tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
        }
        for (int i = 0; i < N; i++) {
            pos[sa[i]] = tmp[i];
        }
        d *= 2;
    }
}

int main() {
    fastio;
    
    cin >> N;
    for (int i = 0; i < N; i++) s += 65+50;
    for (int i = 0; i < N; i++) {
        cin >> arr[i]; s[arr[i]] = 'A'+i; 
    }

    solve();

    for (int i = 0; i < N; i++) {
        ans[i] = sa[i]; 
    }

    for (int i = 0; i < N-1; i++) {
        int tmp = s[arr[i+1]];
        s[arr[i+1]] = s[arr[i]]; solve();
        for (int j = 0; j < N; j++) {
            if (ans[j] != sa[j]) {
                s[arr[i+1]] = tmp;
                break;
            }
        }
    }

    set<char> ss; 
    for (int i = 0; i < N; i++ ){
        ss.insert(s[i]);
    }
    cout << ss.size() << endl;

    return 0;
}