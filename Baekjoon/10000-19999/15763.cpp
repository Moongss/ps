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

int main() {
    fastio;
    
    char arr[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt0 = 0, cnt1 = 0;
    set<char> s;
    set<char> t1;
    set<pair<char, char>> t2;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s.insert(arr[i][j]);
        }
        if (s.size() == 1) t1.insert(*s.begin());
        if (s.size() == 2) {
            char a = *s.begin(); 
            char b = *s.rbegin();
            if (a>b) swap(a, b);
            t2.insert({a, b});
        }
        s.clear();
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s.insert(arr[j][i]);
        }
        if (s.size() == 1) t1.insert(*s.begin());
        if (s.size() == 2) {
            char a = *s.begin(); 
            char b = *s.rbegin();
            if (a>b) swap(a, b);
            t2.insert({a, b});
        }
        s.clear();
    }

    s.clear();
    for (int i = 0; i < 3; i++) {
        s.insert(arr[i][i]);
    }
    if (s.size() == 1) t1.insert(*s.begin());
    if (s.size() == 2) {
        char a = *s.begin(); 
        char b = *s.rbegin();
        if (a>b) swap(a, b);
        t2.insert({a, b});
    }

    s.clear();
    for (int i = 0; i < 3; i++) {
        s.insert(arr[i][2 - i]);
    }
    if (s.size() == 1) t1.insert(*s.begin());
    if (s.size() == 2) {
        char a = *s.begin(); 
        char b = *s.rbegin();
        if (a>b) swap(a, b);
        t2.insert({a, b});
    }

    cout << t1.size() << endl << t2.size() << endl;
    return 0;
}