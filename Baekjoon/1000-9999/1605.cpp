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
int sa[202020], lcp[202020], pos[202020], tmp[202020];
int d;

bool cmp(int i, int j) {
    if (pos[i] != pos[j]) return pos[i] < pos[j];
    i+=d; j+=d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : i > j;
}

void init() {
    // sa
    for (int i = 0; i < N; i++) {
        sa[i] = i;
        pos[i] = s[i];
    }

    // 하는짓은 기존코드랑 같은데, sa의 위치를 저장할거냐, 그냥 그룹번호만 저장할거냐 차이임. 
    // pos[sa]로 업데이트 해주거나, tmp배열에서 그냥 바로 업데이트한걸 Pos[i]에 넣거나...
    d = 1;
    while (d <= N) {
        sort(sa, sa+N, cmp);
        
        // tmp[0] = 0; // before memset
        tmp[sa[0]] = 0; 
        for (int i = 0; i < N-1; i++) {
            // tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
            tmp[sa[i+1]] = tmp[sa[i]] + cmp(sa[i], sa[i+1]);
        }
        for (int i = 0; i < N; i++) {
            // pos[sa[i]] = tmp[i];
            pos[i] = tmp[i];
        }

        // if (tmp[N-1] == N-1) break;
        // d <= N으로 처리가능
        d *= 2;
    }

    // 이렇게 되면 아래 코드로 추가처리 해야함. 위 코드는 단순히 sa만 체크하는거라..
    // 근데 없어도 되지않나?
    // for (int i = 0; i < N; i++) pos[sa[i]] = i;

    // lcp
    for (int i = 0, k = 0; i < N; i++) {
        if (pos[i] == 0) continue;

        int j = sa[pos[i]-1];
        while (i+k<N && j+k<N && s[i+k] == s[j+k]) k++;

        lcp[pos[i]] = k;
        k = max(k-1, 0);
    }
}


int main() {
    fastio;
    
    cin >> N >> s;
    init();

    int ret = 0;
    for (int i = 0; i < N; i++) ret = max(ret, lcp[i]);
    cout << ret << endl;
    return 0;
}